#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// sp - stack pointer
struct bracket {
    char symbol;
    struct bracket* prev;
} *sp = NULL;

int push(char c) {
    struct bracket* ptr;
    ptr = (struct bracket*)malloc(sizeof(struct bracket));

    if (!ptr)
        return 0;  // failed to allocate memory

    ptr->symbol = c;
    ptr->prev = sp;
    sp = ptr;

    return 1;
}

char pop() {
    if (sp != NULL) {
        struct bracket* tmp = sp;
        char c = sp->symbol;
        sp = sp->prev;
        free(tmp);
        return c;
    }
    else {
        return '\0'; // if stack is empty
    }
}

char peek() {
    if (sp != NULL)
        return sp->symbol;
    else
        return '\0';
}

bool isOpeningBracket(char symbol) {
    return (symbol == '(' || symbol == '{' || symbol == '[');
}

bool isClosingBracket(char symbol) {
    return (symbol == ')' || symbol == '}' || symbol == ']');
}

bool matches(char open, char close) {
    return ((open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']'));
}

int main() {
    char input[] = "{(1+2)*3}+[4+5]";
    bool valid = true;

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        if (isOpeningBracket(ch))
            push(ch);

        else if (isClosingBracket(ch)) {
            char last = pop();
            if (!matches(last, ch)) {
                valid = false;
                break;
            }
        }
    }

    // if there is more brakcets in the stack
    if (sp != NULL)
        valid = false;

    if (valid)
        printf("Valid placing");
    else
        printf("Not valid placing");
}
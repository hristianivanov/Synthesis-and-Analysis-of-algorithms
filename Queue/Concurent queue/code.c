#include <stdio.h>
#include <stdlib.h>   // for malloc and free
#include <string.h>   // for strcpy

struct queue {
    int rank;
    char task[20];
    struct queue* next;
} *head = NULL;

struct queue* findPlace(int r) {
    struct queue* f = head;
    struct queue* s = NULL;

    while (f != NULL && f->rank <= r) {
        s = f;
        f = f->next;
    }

    return s;
}

int enqueu(int r, char* task) {
    struct queue* ptr = (struct queue*)malloc(sizeof(struct queue));

    if (!ptr)
        return 0;  // failed to allocate memory

    ptr->rank = r;
    strcpy_s(ptr->task, sizeof(ptr->task), task);
    ptr->next = NULL;

    struct queue* ptr1 = findPlace(r);

    if (ptr1 != NULL) {
        ptr->next = ptr1->next;
        ptr1->next = ptr;
    }
    else {
        ptr->next = head;
        head = ptr;
    }

    return 1;  // success
}

void dequeue() {
    if (head == NULL)
        return; // queue is empty

    struct queue* temp = head;

    // do whatever you want with this element
    // print, get it's rank or task

    head = head->next;
    free(temp);
}

void printTaskQueue() {
    struct queue* ptr = head;

    while (ptr) {
        printf("%s, %d\n", ptr->task, ptr->rank);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    enqueu(1, "t1");
    enqueu(3, "t3");
    enqueu(6, "t6");
    enqueu(5, "t5");
    enqueu(2, "t2");
    enqueu(3, "t32");

    printTaskQueue();

    dequeue();

    printf("After dequeue:\n");
    printTaskQueue();

    return 0;
}
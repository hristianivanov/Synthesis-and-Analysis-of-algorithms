#include <stdio.h>

int gcd(int a, int b) {
    if (a == 0)
        return b;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int gcd_recoursion(int a, int b) {
    return (0 == a) ? b : gcd(a, b % a);
}

void main() {
    printf("%d", gcd_recoursion(24, 32));
}
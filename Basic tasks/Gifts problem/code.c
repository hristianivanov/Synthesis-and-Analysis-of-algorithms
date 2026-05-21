#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int* gifts;

    printf("Enter numbers of gifts: ");
    scanf_s ("%d", &n);

    gifts = malloc(n * sizeof(int));
    if (!gifts)
        printf("Memory not allocated!!");

    printf("Enter gifts:");
    for (int i = 0; i < n; i++)
        scanf_s("%d", &gifts[i]);

    int total = 0;
    for (int i = 0; i < n; i++)
        total += gifts[i];

    int* can = malloc((total + 1) * sizeof(int));
    for (int i = 0; i <= total; i++)
        can[i] = 0;

    can[0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = total; j >= 0; j--)
            if (can[j] == 1)
                can[j + gifts[i]] = 1;

    int p = total / 2;
    while (p > 0 && !can[p]) 
        p--;

    printf("\nBrat 1: %d, Brat 2: %d\n", p, total - p);
    printf("Razlika: %d\n", (total - 2 * p));


    free(gifts);
    free(can);
}
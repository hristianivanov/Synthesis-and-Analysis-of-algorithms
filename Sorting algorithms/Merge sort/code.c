#include <stdio.h>
#include <stdlib.h>

// i1,i2 първи и последен индекс на първия масив
// j1,j2 първи и последен индекс на втория масив
void merge(float A[], int i1, int i2, int j1, int j2)
{
    int n = j2 - i1 + 1;      // общ брой елементи
    float* T = (float*)malloc(n * sizeof(float));
    if (T == NULL) {
        printf("Error during alocating memory.\n");
        return;
    }

    int k = 0;  // индекс за помощния масив
    int i = i1; // текущ индекс в първия подмасив
    int j = j1; // текущ индекс във втория подмасив

    while ((i <= i2) && (j <= j2)) {
        if (A[i] < A[j]) {
            T[k] = A[i];
            i++;
        }
        else {
            T[k] = A[j];
            j++;
        }
        k++;
    }

    while (i <= i2) {
        T[k] = A[i];
        i++;
        k++;
    }

    while (j <= j2) {
        T[k] = A[j];
        j++;
        k++;
    }

    // връщаме сортираните елементи в оригиналния масив
    for (k = 0; k < n; k++) {
        A[i1 + k] = T[k];
    }

    free(T);
}

// рекурсивна функция за сортиране чрез сливане
void merge_sort(float A[], int i, int j)
{
    if (i <= j) {
        int mid = (i + j) / 2;
        merge_sort(A, i, mid);
        merge_sort(A, mid + 1, j);
        merge(A, i, mid, mid + 1, j);
    }
}

// функция за отпечатване на масив
void print_array(float A[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%.2f ", A[i]);
    }
    printf("\n");
}

int main()
{
    float A[] = { 12, 3.7, 15, -3, 49, 0.6, 10 };
    int n = sizeof(A) / sizeof(A[0]);

    printf("arr before sorting:\n");
    print_array(A, n);

    merge_sort(A, 0, n - 1);

    printf("arr after sorting:\n");
    print_array(A, n);

    return 0;
}
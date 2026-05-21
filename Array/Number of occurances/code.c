#include <stdio.h>
#include <stdlib.h>

void main() {
	int arr[] = { 7, 3, 2, 0, 2, 1, 10, 6, 2, 9, 3, 4 };

	int n = sizeof(arr) / sizeof(arr[0]);

	int* counter = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		counter[arr[i]]++;
	}

	for (int i = 0; i < n - 1; i++)
	{
		printf("%d - %d\n", i, counter[i]);
	}

	free(counter);
}

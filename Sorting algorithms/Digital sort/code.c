#include <stdio.h>
#include <stdlib.h>

void digitalSort(int* arr, int n, int min, int max) {
	int* times = calloc((max + 1), sizeof(int));

	for (int i = 0; i < n; i++)
		times[arr[i]]++;

	int k = 0;
	for (int i = min; i <= max; i++)
		for (int j = 0; j < times[i]; j++)
			arr[k++] = i;

	free(times);
}

int main() {
	int nums[] = { 15, 7, 0, 13, 3, 4, 3, 8, 9 };
	int n = sizeof(nums) / sizeof(nums[0]);

	digitalSort(nums, n, 0, 15);

	for (int i = 0; i < n; i++)
		printf("%d ", nums[i]);

	return 0;
}
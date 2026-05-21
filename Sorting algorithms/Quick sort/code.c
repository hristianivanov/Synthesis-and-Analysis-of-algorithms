#include <stdio.h>
#include <stdlib.h>

void quickSort(int* arr, int n, int start, int end) {

	int i = start;
	int j = end;
	int pivot = (start + end) / 2;

	do
	{
		while (arr[pivot] > arr[i])
			i++;
		while (arr[pivot] < arr[j])
			j--;

		if (i <= j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

			i++; j--;
		}
	} while (i <= j);

	if (start < j)
	{
		quickSort(arr, n, start, j);
	}
	if (end > i) {
		quickSort(arr, n, i, end);
	}
}

int main() {
	int nums[] = { 3,8,4,0,8,7 };
	int n = sizeof(nums) / sizeof(nums[0]);

	quickSort(nums, n, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", nums[i]);

	return 0;
}
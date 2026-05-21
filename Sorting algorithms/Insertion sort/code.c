#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* A, int n) {
	for (int i = 1; i < n; i++)
	{
		int j = i;
		while (j > 0 && A[j - 1] < A[j])
		{
			int temp = A[j - 1];
			A[j - 1] = A[j];
			A[j] = temp;

			j--;
		}
	}
}


void main() {
	int nums[] = { 3,8,4,0,8,7 };

	int n = sizeof(nums) / sizeof(nums[0]);

	insertionSort(nums, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", nums[i]);
	}
}
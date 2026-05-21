#include <stdio.h>
#include <stdlib.h>

// O(n^2) always
void selectionSort(int* A, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		int iMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[iMin] > A[j])
				iMin = j;
		}

		if (iMin != i) {
			int temp = A[iMin];
			A[iMin] = A[i];
			A[i] = temp;
		}

	}
}

void main() {
	int nums[] = { 3,8,4,0,8,7 };

	int n = sizeof(nums) / sizeof(nums[0]);

	selectionSort(nums, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", nums[i]);
	}
}
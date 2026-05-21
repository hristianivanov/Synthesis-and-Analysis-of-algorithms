#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* A, int n) {
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n - 1; j++)
	//	{
	//		if (A[j+1] < A[j])
	//		{
	//			int temp = A[j + 1];
	//			A[j + 1] = A[j];
	//			A[j] = temp;
	//		}
	//	}
	//}

	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (A[j - 1] > A[j])
			{
				int temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
			}
		}
	}
}

void bubbleSortFlag(int* A, int n) {
	int flag;
	do
	{
		flag = 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (A[i + 1] < A[i])
			{
				int temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;

				flag = 0;
			}
		}
	} while (!flag);
}


void main() {
	int nums[] = { 3,8,4,0,8,7 };

	int n = sizeof(nums) / sizeof(nums[0]);

	bubbleSortFlag(nums, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", nums[i]);
	}
}
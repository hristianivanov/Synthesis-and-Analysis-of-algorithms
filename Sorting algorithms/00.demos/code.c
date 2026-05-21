#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		int iMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[iMin] > arr[j])
				iMin = j;
		}

		if (iMin != i)
			swap(&arr[iMin], &arr[i]);
	}
}

void insertionSort(int* arr, int n) {
	for (int i = 1; i < n; i++)
	{
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			swap(&arr[j - 1], &arr[j]);

			j--;
		}
	}
}

void bubbleSort(int* arr, int n) {
	//for (int i = 0; i < n - 1; i++)
	//{
	//	for (int j = n - 1; j > i; j--)
	//	{
	//		if (arr[j-1] > arr[j])
	//		{
	//			swap(&arr[j - 1], &arr[j]);
	//		}
	//	}
	//}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void bubbleSortFlag(int* arr, int n) {

	bool flag;
	do
	{
		flag = true;
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				flag = false;
			}
		}
	} while (!flag);
}

void quickSort(int* arr, int start, int end) {
	int pivot = (start + end) / 2;
	int i = start;
	int j = end;
	do
	{
		while (arr[pivot] > arr[i])
			i++;
		while (arr[pivot] < arr[j])
			j--;

		if (i <= j) {
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (i < end)
		quickSort(arr, i, end);
	if (j > start)
		quickSort(arr, start, j);

}

void merge(int* arr, int i1, int i2, int j1, int j2) {
	int n = j2 - i1 + 1;
	int* cpyArr = (int*)malloc(n * sizeof(int));

	int k = 0;
	int i = i1;
	int j = j1;

	while ((i <= i2) && (j <= j2))
	{
		if (arr[i] > arr[j])
		{
			cpyArr[k] = arr[j];
			j++;
		}
		else
		{
			cpyArr[k] = arr[i];
			i++;
		}
		k++;
	}

	while (i <= i2)
	{
		cpyArr[k] = arr[i];
		i++; k++;
	}

	while (j <= j2)
	{
		cpyArr[k] = arr[j];
		j++; k++;
	}

	for (int i = 0; i < n; i++)
	{
		arr[i + i1] = cpyArr[i];
	}
}

void mergeSort(int* arr, int start, int end) {
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, mid + 1, end);
	}
}

void digitalSort(int A[], int n, int min, int max)
{
	int* times = calloc(max + 1, sizeof(int));

	for (int j = 0; j < n; j++)
		times[A[j]]++;

	int j = 0;
	for (int i = min; i <= max; i++)
		for (int k = 0; k < times[i]; k++)
			A[j++] = i;

	free(times);
}

void main() {
	int nums[] = { 3,8,4,0,8,7 };

	int n = sizeof(nums) / sizeof(nums[0]);
	//quickSort(nums, 0, n - 1);
	//selectionSort(nums, n);
	//insertionSort(nums, n);
	//bubbleSort(nums, n);
	//bubbleSortFlag(nums, n);
	//mergeSort(nums, 0, n - 1);
	//digitalSort(nums, n, 0, 8);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", nums[i]);
	}
}
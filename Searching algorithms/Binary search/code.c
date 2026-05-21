#include <stdio.h>

int bin_search(int* arr, int n, int num) {

	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < num) {
			left = mid + 1;
		}
		else if (arr[mid] > num) {
			right = mid - 1;
		}
		return num;
	}

	return -1;
}

void main() {

}
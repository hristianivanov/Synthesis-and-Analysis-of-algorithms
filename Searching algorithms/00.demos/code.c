#include <stdio.h>

int linear_search1(int* arr, int n, int x) // O(2n)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

int linear_search2(int* arr, int n, int x)
{
	arr[n] = x;
	int i = 0;
	while (arr[i] != x)
		i++;
	if (i < n)
		return i;
	return -1;
}

void main() {

}
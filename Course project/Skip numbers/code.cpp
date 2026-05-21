#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void main() {
	int n, k;
	bool valid = false;

	// --- Input validation for n ---
	do {
		printf("Enter the number of elements in the initial sequence (n > 1): ");
		if (!scanf_s("%d", &n)) {
			printf("Error: Please enter a valid positive integer.\n");
			while (getchar() != '\n'); // clear input buffer
			continue;
		}
		else if (n <= 0) {
			printf("Error: n must be a positive integer greater than 0.\n");
			continue;
		}
		else if (n == 1) {
			printf("Error: n must be greater than 1 to perform eliminations.\n");
			continue;
		}
		valid = true;
	} while (!valid);

	// --- Input validation for k ---
	valid = false;
	do {
		printf("Enter the number of elimination steps (k): ");
		if (scanf_s("%d", &k) != 1) {
			printf("Error: Please enter a valid positive integer.\n");
			while (getchar() != '\n');
			continue;
		}
		if (k <= 0) {
			printf("Error: k must be a positive integer greater than 0.\n");
			continue;
		}
		if (k >= n) {
			printf("Error: k must be smaller than n, otherwise the process cannot continue.\n");
			continue;
		}
		valid = true;
	} while (!valid);

	// --- Allocate memory for the sequence ---
	int* arr = (int*)malloc(n * sizeof(int));
	if (!arr) {
		printf("Memory allocation failed.\n"); return;
	}

	// --- Initialize the sequence: 1, 2, 3, ..., n ---
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	int len = n;

	// --- Perform k elimination steps ---
	for (int step = 2; step <= k; step++) {
		int new_len = 0;

		// Create the new list after removing every "remove_every"-th element
		for (int i = 0; i < len; i++) {
			if ((i + 1) % step != 0) {
				arr[new_len++] = arr[i];
			}
		}

		len = new_len;

		// Safety check: stop if the array becomes too small
		if (len < step) {
			printf("\nProcess stopped early: list too short for step %d.\n", step);
			break;
		}
	}

	// --- Output result ---
	printf("\nResult after %d step(s):\n", k);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	// --- Clean up ---
	free(arr);
}
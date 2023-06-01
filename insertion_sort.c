#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && key < arr[j]) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main() {
	int n, i;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int *arr = (int *)malloc(n * sizeof(int));
	printf("Enter the elements: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	insertion_sort(arr, n);
	printf("Sorted array: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
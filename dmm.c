#include <stdio.h>
#include <stdlib.h>

long long int length = 1000000;
int update = 400;

int main() {

	// Memory allocation
	// malloc
	int *arr = (int*) malloc(length*sizeof(int));
	for (long long int i = 0; i < length; i++) {
		arr[i] = i+1;
	}

	// Clear allocation
	// calloc is same as malloc but it initializes every value to zero

	int *arr2 = (int*) calloc(length, sizeof(int));
	for (long long int i = 0; i < length; i++) {
		arr2[i] = i+1;
	}

	printf("\narr1 = %p", arr);
	printf("\narr2 = %p", arr2);

	// realloc is used to re-allocate
	length += update;
	arr2 = (int*) realloc(arr2, length*sizeof(int));

	for (int i = 0; i < update; i++)
	{
		arr2[length+i-update] = length+i+1-update;
	}

	printf("\narr1 = %p", arr);
	printf("\narr2 = %p", arr2);
	printf("\narr2 = %ld", arr2[length-1]);
	printf("\n%ld", arr2[length+48]);

	free(arr);
	free(arr2);

	printf("\n\n");
}
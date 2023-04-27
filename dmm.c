#include <stdio.h>
#include <stdlib.h>

int a;
int b = 0;
long long int l = 1000000;
int update = 448;

void initt(int *arr) {
	for (long long int i = 0; i < l; i++) {
		arr[i] = i+1;
	}
}

int main() {
	// printf("a = %d\n", a);
	// printf("\nfuck you");
	for (int i = 0; i < 5; i++)
	{
		// printf("\n%d", i);
	}
	
	printf("\n\n\n");

	// Memory allocation
	// malloc
	int *arr = (int*) malloc(l*sizeof(int));
	// initt(arr);
	for (long long int i = 0; i < l; i++) {
		arr[i] = i+1;
	}

	for (int i = 0; i < 10; i++)
	{
		// printf("\n%d", arr[i]);
	}

	// free(arr);


	// Clear allocation
	// calloc is same as malloc but it initializes every value to zero

	int *arr2 = (int*) calloc(l, sizeof(int));
	// initt(arr2);
	for (long long int i = 0; i < l; i++) {
		arr2[i] = i+1;
	}

	for (int i = 0; i < 10; i++)
	{
		// printf("\n%d", arr2[i]);
	}

	// free(arr2);

	printf("\narr1 = %p", arr);
	printf("\narr2 = %p", arr2);
	// realloc is used to re-allocate
	l += update;
	arr2 = (int*) realloc(arr2, l*sizeof(int));
	// initt(arr);

	for (int i = 0; i < update; i++)
	{
		arr2[l+i-update] = l+i+1-update;
	}

	printf("\narr1 = %p", arr);
	printf("\narr2 = %p", arr2);
	printf("\narr2 = %ld", arr2[l-1]);
	printf("\n%ld", arr2[l+48]);

	free(arr);
	free(arr2);
}
#include <stdio.h>
#include <stdlib.h>

int Array[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int main() {
	int length = sizeof(Array) / sizeof(Array[0]);
	printf("%d\n", length);
}
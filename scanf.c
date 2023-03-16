#include <stdio.h>
int main() {
	int a, b;

	// printf("\nEnter a value: ");
	// scanf("%d", &a);
	// printf("\nEnter a value: ");
	// scanf("%d", &b);

	printf("\nEnter two values: ");
	scanf("%d *%d", &a, &b);

	printf("\na = %d, b = %d\n", a, b);
}

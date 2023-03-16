#include <stdio.h>

int main() {
	int a_dec = 16;
	int a_oct = '\020';
	int a_hex = 0x10;

	printf("%d %d %d\n", a_dec, a_oct, a_hex);

	// Though all the three variables represent the same thing in 
	if (a_dec == a_oct == a_hex) {
		printf("True");
	} else {
		printf("False");
	}
	printf("\n");
}

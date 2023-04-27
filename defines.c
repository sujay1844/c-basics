#include <stdio.h>

// Macros
#define TRUE 1
#define FALSE 0

int main() {
	printf("TRUE is %d\n", TRUE);
	printf("FALSE is %d\n", FALSE);
	
	#undef TRUE
	int TRUE = 10;
	printf("Now, TRUE is %d\n", TRUE);
}

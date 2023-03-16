// 2023-03-09
// In python, print returns None
// But in C, printf returns no. of characters.
#include <stdio.h>

int main() {
	int num = printf("Hello\n");
	printf("printf printed %d characters\n", num);
}

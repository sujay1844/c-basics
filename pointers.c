#include <stdio.h>
int Global = 20;
int main() {
	char a = 'j';
	printf("%p (%ld bytes) -> %c \n", &a, sizeof(a), a);
	char b = 'F';
	printf("%p (%ld bytes) -> %c \n", &b, sizeof(b), b);
	printf("\nGlobal %p (%ld bytes) -> %d \n", &Global, sizeof(Global), Global);
	Global++;
	printf("\nGlobal %p (%ld bytes) -> %d \n", &Global, sizeof(Global), Global);
}

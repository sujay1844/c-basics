// hi has empty body
// but bye has no body
// Hence, linker cannot link the function reference to anything in bye.
#include <stdio.h>

int hi() {}
int bye() {}
int main() {
	printf("Hello\n");
	hi();
}

#include <stdio.h>

typedef int tni;

struct Simple {
	int a;
};

struct Complex {
	int b;
};

typedef struct Simple Simpl;

int main() {
	tni c = 3; // User-defined type
	int f = 6; // Primitive datatype
	printf("%d %d\n", c, f);
	typedef int inteee;
	inteee g = 9;

	Simpl hi = {7};
	struct Complex bye = {4};
}

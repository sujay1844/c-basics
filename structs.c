#include <stdio.h>

struct Simple {
	int S1;
	int S2;
};

struct Complex {
	int C1;
	int C2;
	struct Simple SComplex;
};

void Structs() {
	struct Complex C = {
		.C1 = 3,
		.C2 = 4,
		.SComplex = {
			.S1 = 8,
			.S2 = 7,
		},
	};

	printf("C.C1 = %d\n", C.C1);
	printf("C.C2 = %d\n", C.C2);
	printf("C.SComplex.S1 = %d\n", C.SComplex.S1);
	printf("Pointer of C = %p\n", &C);
}

int main() {

	Structs();
	printf("\n\n\n");
}

#include <stdio.h>
int main() {
	printf("10>20 = %d\n", 10>20);
	printf("10<20 = %d\n", 10<20);
	printf("!0 = %d\n", !0);
	printf("!1 = %d\n", !1);

	if (0) {
		printf("Tejas is good boy\n");

	} else {
		printf("Tejas is bad boy\n");
		printf("hi\n");
	}
	// 
	// if (0)
	// 	printf("hi\n");
	// 	printf("hi2\n");
	// else
	// 	printf("bye\n");
	// 	printf("bye2\n");
	char c;
	c = 66;
	printf("%d->%c\n", c, c);

	int a = 10*20+30/2;
	printf("a = %d\n", a);

	int b = (10>=3) < (2*4>9);
	printf("b = %d\n", b);
}

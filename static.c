#include <stdio.h>

// Static variables are stored in the data segment.

int get_some_value()
{
	static int x = 10;

	x++;

	{
		static int x = 20;
		x--;
		printf("Inside block which is inside funcion, x = %d\n", x);
	}

	return x;
}

int main()
{
	printf("Inside function, x = %d\n", get_some_value());
	printf("Inside function, x = %d\n", get_some_value());
	printf("Inside function, x = %d\n", get_some_value());
}
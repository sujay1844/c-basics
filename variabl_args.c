#include <stdio.h>
#include <stdarg.h>

int avg(int n, ...)
{
	va_list args;
	va_start(args, n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += va_arg(args, int);
	}
	va_end(args);
	return sum / n;
}

int main()
{
	printf("%d\n", avg(3, 1, 2, 3));
	printf("%d\n", avg(5, 1, 2, 3, 4, 5));
	printf("%d\n", avg(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
}
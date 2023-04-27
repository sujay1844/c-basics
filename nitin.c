#include <stdio.h>
int main()
{
        int n1 = 100;
        int n2 = 200;
        int temp1 = printf("One");
	int temp2 = printf("Onee");
	int result;
	result = n1?temp1:temp2;
	printf("\nresult-->%d",result);
	printf("\n");
}

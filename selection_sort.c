#include <stdio.h>
#include <stdlib.h>

void display(int array[], int length)
{
	printf("\n");
	for (int i = 0; i < length - 1; i++)
	{
		printf("%d, ", array[i]);
	}
	// Print the last element without a comma
	printf("%d\n", array[length - 1]);
}

void selection_sort(int array[], int length)
{
	int temp;
	int smallest;

	for (int i = 0; i < length; i++)
	{
		smallest = i;
		for (int j = i + 1; j < length; j++)
		{
			if (array[smallest] > array[j])
			{
				smallest = j;
			}
		}
		// Swap the smallest element with the current element
		temp = array[i];
		array[i] = array[smallest];
		array[smallest] = temp;
	}
	display(array, length);
}

int main()
{
	int array[5] = {4, 2, 6, 3, 7};
	selection_sort(array, 5);
}
#include <stdio.h>
#include <stdlib.h>

int binary_search(int array[], int length, int search_term)
{
	// In case the array is not sorted
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

	// Since we are skipping first and last element
	if (array[0] == search_term)
	{
		return 0;
	}
	if (array[length - 1] == search_term)
	{
		return length - 1;
	}

	int low = 0;
	int high = length - 1;
	int mid;

	while (low < high)
	{

		mid = (low + high) / 2;

		if (search_term > array[mid])
		{
			low = mid;
		}
		else if (search_term < array[mid])
		{
			high = mid;
		}
		else
		{
			break;
		}
	}
	while (1)
	{
		if (array[mid] == array[mid - 1])
		{
			// If the previous element is a duplicate
			mid--;
		}
		else
		{
			break;
		}
	}

	if (array[mid] == search_term)
	{
		return mid;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int array[6] = {0, 1, 1, 1, 1, 5};
	int index = binary_search(array, 6, 1);
	printf("\n Element found at location = %d", index);
}
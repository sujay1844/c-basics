#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

typedef enum Order
{
    ASCENDING,
    DESCENDING
} Order;

typedef struct Array
{
    int length;
    int arr[MAX_LENGTH];
} Array;

void display(Array array)
{
    printf("\n");
    for (int i = 0; i < array.length - 1; i++)
    {
        printf("%d, ", array.arr[i]);
    }
    // Print the last element without a comma
    printf("%d\n", array.arr[array.length - 1]);
}

Array selection_sort(Array array, Order order)
{
    int temp;
    int smallest;

    for (int i = 0; i < array.length; i++)
    {
        smallest = i;
        for (int j = i + 1; j < array.length; j++)
        {
            if (order == ASCENDING)
            {
                if (array.arr[smallest] > array.arr[j])
                {
                    smallest = j;
                }
            }
            else
            {
                if (array.arr[smallest] < array.arr[j])
                {
                    smallest = j;
                }
            }
        }
        // Swap the smallest element with the current element
        temp = array.arr[i];
        array.arr[i] = array.arr[smallest];
        array.arr[smallest] = temp;
    }

    return array;
}

int main()
{
    Array array = {
        .arr = {1, -4, 3, 2, 5},
        .length = 5};

    printf("\n Before sorting:");
    display(array);

    array = selection_sort(array, DESCENDING);

    printf("\n After sorting:");
    display(array);

    return 0;
}

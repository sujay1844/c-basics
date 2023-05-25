#include <stdio.h>
#include <time.h>
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

void generateRandomIntegers(Array *array)
{
    srand(time(NULL)); // Initialize the random number generator

    array->length = MAX_LENGTH;

    for (int i = 0; i < array->length; i++)
    {
        array->arr[i] = rand(); // Generate a random integer
    }
}

double measureExecutionTime(Array (*function)(Array, Order), int numExecutions, Array array, Order order)
{
    clock_t start, end;
    double totalExecutionTime = 0.0;

    for (int i = 0; i < numExecutions; i++)
    {
        start = clock(); // Record the starting time

        // Call the function to be timed
        function(array, order);

        end = clock(); // Record the ending time

        double executionTime = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate the elapsed time in seconds

        totalExecutionTime += executionTime;
    }

    double averageExecutionTime = totalExecutionTime / numExecutions;

    return averageExecutionTime * 1000.0;
}

int main()
{
    Array array;
    generateRandomIntegers(&array);

    printf("\n Before sorting:");
    display(array);

    array = selection_sort(array, DESCENDING);

    printf("\n After sorting:");
    display(array);
    printf("Max value of rand(): %d\n", RAND_MAX);

    int numExecutions = 10000; // Specify the number of times the function should be executed

    double averageTime = measureExecutionTime(selection_sort, numExecutions, array, ASCENDING);

    printf("Average time taken: %f ms\n", averageTime * 1000.0);

    return 0;
}
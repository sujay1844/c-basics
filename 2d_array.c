#include <stdio.h>
#include <stdlib.h>

int **create_matrix(int rows, int columns)
{
	int **arr = (int **)malloc(sizeof(int *) * rows);
	for (int row = 0; row < rows; row++)
	{
		arr[row] = (int *)malloc(sizeof(int) * columns);
	}
	return arr;
}

int **input_matrix(int rows, int columns)
{
	int **matrix = create_matrix(rows, columns);
	printf("Enter %d elements:-\n", rows * columns);
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			scanf("%d", &matrix[row][column]);
		}
	}
	return matrix;
}

void display_matrix(int **matrix, int rows, int columns)
{
	printf("\nMatrix:-\n");
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			printf("%d ", matrix[row][column]);
		}
		printf("\n");
	}
}

int diagonal_sum(int **matrix, int rows, int columns)
{
	if (rows != columns)
	{
		return -1;
	}

	int sum = 0;
	for (int row = 0; row < rows; row++)
	{
		sum += matrix[row][row];
	}
	return sum;
}

int **get_transpose(int **matrix, int rows, int columns)
{
	int **transpose = create_matrix(columns, rows);
	for (int column = 0; column < columns; column++)
	{
		for (int row = 0; row < rows; row++)
		{
			transpose[column][row] = matrix[row][column];
		}
	}
	return transpose;

}

int **add_matrices(int **matrix1, int **matrix2, int rows, int columns)
{
	int **result = create_matrix(rows, columns);
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			result[row][column] = matrix1[row][column] + matrix2[row][column];
		}
	}
	return result;
}

int **multiply_matrices(int **matrix1, int **matrix2, int rows1, int columns1, int rows2, int columns2)
{
	if (rows2 != columns1)
	{
		return NULL;
	}

	int **result = create_matrix(rows1, columns2);

	for (int row = 0; row < rows1; row++)
	{
		for (int column = 0; column < columns2; column++)
		{
			result[row][column] = 0;
			for (int i = 0; i < columns1; i++)
			{
				result[row][column] += matrix1[row][i] * matrix2[i][column];
			}
		}
	}
	return result;
}

int main()
{
	int rows = 3, columns = 2;
	int **matrix = input_matrix(rows, columns);
	display_matrix(matrix, rows, columns);

	printf("Sum of diagonal elements = %d", diagonal_sum(matrix, rows, columns));

	int **transpose = get_transpose(matrix, rows, columns);
	display_matrix(transpose, columns, rows);

	int **product = multiply_matrices(matrix, transpose, rows, columns, columns, rows);
	display_matrix(product, rows, rows);

	free(matrix);
	free(transpose);
	free(product);
}
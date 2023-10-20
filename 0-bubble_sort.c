#include "sort.h"

/**
 * swap_pos - swaps position of values in array
 *
 * @array: array to be changed
 * @x: index
 * @y: index
 * Return: void
 */
void swap_pos(int **array, size_t x, size_t y)
{
	int tmp;

	tmp = (*array)[x];
	(*array)[x] = (*array)[y];
	(*array)[y] = tmp;
}

/**
 * bubble_sort - Bubble sort algorithm
 * @array: array of integers
 * @size: size of array
 *
 * Description: Prints the array after each swap.
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int swap;
	size_t i, j;

	if (!array || (array && size < 2))
		return;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_pos(&array, j, j + 1);
				print_array(array, size);
				swap = 1;
			}
		}
		if (swap == 0)
			break;
	}
}

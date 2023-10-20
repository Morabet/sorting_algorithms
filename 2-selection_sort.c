#include "sort.h"

/**
 * swap_pos - swaps position of values in array
 *
 * @array: array to be changed
 * @x: index
 * @y: index
 */
void swap_pos(int **array, size_t x, size_t y)
{
	int tmp;

	tmp = (*array)[x];
	(*array)[x] = (*array)[y];
	(*array)[y] = tmp;
}

/**
 * selection_sort - sorts an array using the Selection sort algorithm
 * @array:  pointer to array of integers
 * @size: size of array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t  i, j, min_idx;
	int swap;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		swap = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
				swap = 1;
			}
		}
		if (swap == 1)
		{
			swap_pos(&array, min_idx, i);
			print_array(array, size);
		}
	}
}

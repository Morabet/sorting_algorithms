#include "sort.h"

/**
 * swap_pos - swaps position of values in array
 *
 * @array: array to be changed
 * @x: index
 * @y: index
 */
void swap_pos(int **array, int x, int y)
{
	int tmp;

	tmp = (*array)[x];
	(*array)[x] = (*array)[y];
	(*array)[y] = tmp;
}

/**
 * partition - split the array to subarray according to pivot
 * @array: pointre to array of integers
 * @lower: lower index for the new array
 * @hight: upper index for the new array
 * @size: the original size to use for printing.
 * Return: pi
 */

int partition(int **array, int lower, int hight, size_t size)
{
	int pivot = (*array)[hight];
	int i = (lower - 1);
	int j;

	for (j = lower; j < hight; j++)
	{
		if ((*array)[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_pos(array, i, j);
				print_array(*array, size);
			}
		}
	}
	if ((i + 1) != hight)
	{
		swap_pos(array, i + 1, hight);
		print_array(*array, size);
	}
	return (i + 1);
}

/**
 * sort_quick - recursively sorts the array given
 * @array: ponter to array of integers
 * @lower: lower index for the new array
 * @hight: upper index for the new array
 * @size: the original size to use for printing.
 * Return: void
 */

void sort_quick(int **array, int lower, int hight, size_t size)
{
	int pi;

	if (lower < hight)
	{
		pi = partition(array, lower, hight, size);
		sort_quick(array, lower, pi - 1, size);
		sort_quick(array, pi + 1, hight, size);
	}
}

/**
 * quick_sort -  Quick sort algorithm
 * @array: pointer to array of integers
 * @size: size of array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort_quick(&array, 0, (int)(size - 1), size);
}


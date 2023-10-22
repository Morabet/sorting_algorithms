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
 * partition - splits the array into two parts
 * @array: array of integers
 * @lower: lower bound
 * @hight: upper bound
 * @size: size of array
 * Return: pi
 */

int partition(int **array, int lower, int hight, size_t size)
{
	int pivot = (*array)[hight];
	int i = (lower - 1);
	int j = (hight + 1);

	while (true)
	{
		do {
			i++;
		} while ((*array)[i] < pivot);

		do {
			j--;
		} while ((*array)[j] > pivot);

		if (i >= j)
			return (i);

		swap_pos(array, i, j);
		print_array(*array, size);
	}
}

/**
 * sort_quick - recursively sorts the array given
 * @array: array of integers
 * @lower: lower bound
 * @hight: upper bound
 * @size: size of array
 */

void sort_quick(int **array, int lower, int hight, size_t size)
{
	int pi;

	if (lower < hight)
	{
		pi = partition(array, lower, hight, size);
		sort_quick(array, lower, pi - 1, size);
		sort_quick(array, pi, hight, size);
	}
}

/**
 * quick_sort_hoare -  Quick sort hoare algorithm
 * @array:  array of integers
 * @size: size of array
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort_quick(&array, 0, (int)(size - 1), size);
}


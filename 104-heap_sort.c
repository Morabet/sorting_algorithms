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
 * sort_heap - builds a heap from an array
 * @array: pointer to array of integers
 * @n: end index as array
 * @i: index of maxid
 * @size: size of the array
 * * Return: void
 */
void sort_heap(int *array, int n, int i, size_t size)
{
	int maxid = i;
	int l = (2 * i) + 1;
	int r = (2 * i) + 2;

	if (l < n && array[l] > array[maxid])
		maxid = l;

	if (r < n && array[r] > array[maxid])
		maxid = r;

	if (maxid != i)
	{
		swap_pos(&array, i, maxid);
		print_array(array, size);
		sort_heap(array, n, maxid, size);
	}
}

/**
 * heap_sort - the Heap sort algorithm
 * @array: pointer to array of ontegers
 * @size: size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i, n;

	if (!array || size < 2)
		return;

	n = ((int)size - 1) / 2;

	for (i = n; i >= 0; i--)
		sort_heap(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap_pos(&array, 0, i);
		print_array(array, size);
		sort_heap(array, i, 0, size);
	}

}

#include "sort.h"

/**
 * swap - swap two integers
 * @n: first number;
 * @m: second number;
 *
 * Return: void
 */
void swap(int *n, int *m)
{
	int tmp;

	tmp = *n;
	*n = *m;
	*m = tmp;
}

/**
 * shell_sort - Shell sort algorithm, using the Knuth sequence.
 * @array: pointer to the array
 * @size: size of the array
 *
 * Return: void.
 */
void shell_sort(int *array, size_t size)
{
	int val, gap, i, j, n;

	if (!array || size < 2)
		return;

	n = (int) size;

	/*calculating the largset interval*/
	val = 1;
	while (val < n / 3)
		val = val * 3 + 1;

	/*decreasing the interval each iteration*/
	for (gap = val; gap > 0; gap /= 3)
	{
		for (j = gap; j < n; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i] > array[i + gap])
					swap(array + i, array + i + gap);
				else
					break;
			}
		}
		print_array(array, size);
	}
}

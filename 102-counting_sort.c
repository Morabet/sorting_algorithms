#include "sort.h"

/**
 * get_max - gets the maximum value in the array
 *
 * @array: array to get max value from
 * @size: size of the array
 *
 * Return: maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	if (size < 2)
		return (0);

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

/**
 * array_of_zero - initialize array by 0
 * @array: array of integers
 * @size: size of the array
 */
void array_of_zero(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}

/**
 * counting_sort - sorts an array using the counting
 * sort algorithm
 *
 * @array: initial array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i;
	int max = get_max(array, size);
	int *compte, *sorted;
	int n = (int)size;

	if (max == 0)
		return;

	compte = malloc(sizeof(int) * (max + 1));
	if (!compte)
		return;

	array_of_zero(compte, max + 1);

	for (i = 0; i < n; i++)
		compte[array[i]] += 1;

	for (i = 1; i <= max; i++)
		compte[i] += compte[i - 1];

	print_array(compte, max + 1);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;

	array_of_zero(sorted, size);
	for (i = n - 1; i >= 0; i--)
	{
		compte[array[i]] -= 1;
		sorted[compte[array[i]]] = array[i];
	}

	free(compte);
	for (i = 0; i < n; i++)
		array[i] = sorted[i];

	free(sorted);
}

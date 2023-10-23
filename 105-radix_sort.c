#include "sort.h"

/**
 * count_sort - using the counting sort algorithm to sort number going
 *			from the LSD to the right
 * @array: pointer to the array
 * @place: the place to sort in the number (MSD <- LSD)
 * @size: size of the array
 * Return: void/
 */
void count_sort(int *array, int place, int size)
{
	int *output, *count, i, max;

	/*get the number with the max LSD*/
	max = (array[0] / place) % 10;
	for (i = 1; i < size; i++)
	{
		if ((array[i] / place) % 10 > max)
			max = array[i];
	}
	output = malloc(sizeof(int) * (size + 1));
	if (!output)
		return;
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
	{
		free(output);
		return;
	}
	/*initialize the count with '0'*/
	for (i = 0; i < max; i++)
		count[i] = 0;
	/*calculate the count of the elements*/
	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;
	/*calculate the cumultativ count*/
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/*sort the elements in the output arrray*/
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	/*copy back from output to array*/
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}

/**
 * radix_sort -  the Radix sort algorithm using the LSD version
 * @array: pointer to the array
 * @size: size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, n, i, place;

	if (!array || size < 2)
		return;

	n = (int) size;

	/*get the max number in array*/
	max = array[0];
	for (i = 0; i < n; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (place = 1; max / place > 0; place *= 10)
	{
		count_sort(array, place, n);
		print_array(array, size);
	}
}

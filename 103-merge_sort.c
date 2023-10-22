#include "sort.h"

/**
 * copyArray - copies the elements of one array to anpther
 * @A: the first array
 * @iBegin: the begining index
 * @iEnd: the end index
 * @B: the second array
 * Return: void
 */
void copyArray(int A[], int iBegin, int iEnd, int B[])
{
	int i;

	for (i = iBegin; i < iEnd; i++)
		B[i] = A[i];
}

/**
 * merge_arrays - merge the sub-arrays to the sorted 'B'
 * @B: the sorted array;
 * @iBegin: the begining index
 * @m: the middle index
 * @iEnd: the end index
 * @A: the working array
 * Return: void
 */
void merge_arrays(int B[], int iBegin, int m, int iEnd, int A[])
{
	int i, j, k;

	i = iBegin;
	j = m;

	printf("Merging...\n[left]: ");
	print_array(A + iBegin, m - iBegin);

	printf("[right]: ");
	print_array(A + m, iEnd - m);

	/*while there are elements on the left or right*/
	for (k = iBegin; k < iEnd; k++)
	{
		/**
		 * if there are elements on the left AND
		 * there are no elements on the right OR
		 * the left <=  right
		 */
		if (i < m && (j >= iEnd || A[i] < A[j]))
		{
			B[k] = A[i];
			i++;
		}
		else
		{
			/*now we check the right side with the left*/
			B[k] = A[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(B + iBegin, iEnd - iBegin);
}

/**
 * split_sort - split the array into subarrays
 * @B: the array to sort (B == array)
 * @iBegin: the begining index
 * @iEnd: the end index
 * @A: the workin array (A == buffer)
 * Return: void
 *
 * Description: we switched 'array'and'buffer' with 'B'and'A' so at the end
 *		'B' will be sorted (array)
 */
void split_sort(int B[], int iBegin, int iEnd, int A[])
{
	int m;

	/*the arrays are of size '1'*/
	if (iEnd - iBegin <= 1)
		return;

	m = (iEnd + iBegin) / 2;

	split_sort(A, iBegin, m, B); /*sort the left side*/
	split_sort(A, m, iEnd, B);

	merge_arrays(B, iBegin, m, iEnd, A);
}


/**
 * merge_sort - the Merge sort algorithm for an array
 * @array: pointer to the header of
 * @size: size of the pointer
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;


	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	copyArray(array, 0, size, buffer);

	split_sort(array, 0, (int) size, buffer);

	free(buffer);
}

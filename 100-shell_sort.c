#include "sort.h"

/**
 * shell_sort - sorting algorithm that uses Knuth sequence
 * of n+1 = n * 3 + 1
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || !size)
		return;

	/* Calculate the maximum gap */
	gap = 1;
	while (gap < size)
		gap = gap * 3 + 1;
	gap = (gap - 1) / 3;

	/* Shell Sort */
	for (; gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}

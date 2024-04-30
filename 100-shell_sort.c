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

	if (array == NULL || !size)
		return;

	/* Calculate the maximum gap */
	for (gap = 1; gap < size; gap = gap * 3 + 1);

	/* Shell sort algorithm */
	for (gap = (gap - 1) / 3; gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j > gap - 1 && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}

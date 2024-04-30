#include "sort.h"

/**
 * bubble_sort - function that sort array from min to max value
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}

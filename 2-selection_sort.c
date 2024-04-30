#include "sort.h"

/**
 * selection_sort - sorts an array of integers using a selection sort algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, min_index;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = find_min_index(array, i, size);
		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
		}

	}
}

/**
 * find_min_index - finds the index of the minimum element in the array
 * starting from a given index
 * @array: array of integers
 * @start: starting index to search from
 * @size: size of the array
 * Return: index of the minimum element
 */
size_t find_min_index(int *array, size_t start, size_t size)
{
	size_t i, min_index = start;

	for (i = start + 1; i < size; i++)
	{
		if (array[i] < array[min_index])
			min_index = i;
	}
	return (min_index);
}

/**
 * swap - swaps the values of two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

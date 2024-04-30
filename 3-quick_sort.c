#include "sort.h"

/**
 * arr_swap - swaps the values of two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void arr_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partition of an array of for values less than pivot value
 * @array: array of integers to be sorted
 * @low: index in array that begins partition
 * @high: index that ends partition
 * @size: amount of element in array
 * Return: new index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			arr_swap(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	arr_swap(&array[i], &array[high]);
	if (array[i] != array[high])
		print_array(array, size);
	return (i);
}

/**
 * q_ksort - Recursively sort array of integers
 * @array: array of integers to be sorted
 * @low: index that starts partition
 * @high: index that ends partition
 * @size: amount of element in array
 */
void q_ksort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		q_ksort(array, low, pi - 1, size);
		q_ksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sort an array of in ascending order
 * @array: array of integers to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	q_ksort(array, 0, (int)size - 1, size);
}

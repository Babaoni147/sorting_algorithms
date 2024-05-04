#include "sort.h"
#include <stdio.h>

/**
 * swapNumber - swaps numbers
 * @array: input array
 * @a: first index
 * @b: second index
 */
void swapNumber(int *array, int a, int b)
{
	array[a] = array[a] + array[b];
	array[b] = array[a] - array[b];
	array[a] = array[a] - array[b];
}

/**
 * recursionHeap - function that recursivly builds the max heap tree
 * @array: input array
 * @i: index number
 * @size: size of the array
 * @limit: limit of the array
 */
void recursionHeap(int *array, int i, size_t size, int limit)
{
	int max;
	int j;

	j = i * 2;

	if (j + 2 < limit)
	{
		recursionHeap(array, j + 1, size, limit);
		recursionHeap(array, j + 2, size, limit);
	}

	if (j + 1 >= limit)
		return;

	if (j + 2 < limit)
		max = (array[j + 1] > array[j + 2]) ? (j + 1) : (j + 2);
	else
		max = j + 1;

	if (array[i] < array[max])
	{
		swapNumber(array, i, max);
		print_array(array, size);
		recursionHeap(array, max, size, limit);
	}
}

/**
 * heap_sort - function that sorts an array
 * @array: input array
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t limit;

	if (!array || size == 0)
		return;

	i = 0;
	limit = size;

	while (limit > 1)
	{
		recursionHeap(array, i, size, limit);
		if (array[i] >= array[limit - 1])
		{
			swapNumber(array, i, limit - 1);
			print_array(array, size);
		}
		limit--;
	}
}

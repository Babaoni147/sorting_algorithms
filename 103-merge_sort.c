#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* sortMerge - sorts and merges the sub arrays
* @start: starting index
* @mid: end index
* @end: end index
* @dest: destination for the data
* @array: array to sort
*/
void sortMerge(size_t start, size_t mid, size_t end, int *dest, int *array)
{
	size_t i, j, l;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);
	i = start;
	j = mid;
	for (l = start; l < end; l++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			dest[l] = array[i];
			i++;
		}
		else
		{
			dest[l] = array[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
* splitMergeSort - recursively splits array, merge and sort
* @start: starting index
* @end: end index
* @array: the array to sort
* @clone: clone of the array
*/
void splitMergeSort(size_t start, size_t end, int *array, int *clone)
{
	size_t mid;

	if (end - start < 2)
		return;
	mid = (start + end) / 2;
	splitMergeSort(start, mid, array, clone);
	splitMergeSort(mid, end, array, clone);
	sortMerge(start, mid, end, array, clone);
	for (mid = start; mid < end; mid++)
		clone[mid] = array[mid];
}

/**
* merge_sort - sorts an array of integers
* @array: array to sort
* @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *clone;

	if (!array || size < 2)
		return;
	clone = malloc(sizeof(int) * size);
	if (!clone)
		return;
	for (i = 0; i < size; i++)
		clone[i] = array[i];
	splitMergeSort(0, size, array, clone);
	free(clone);
}

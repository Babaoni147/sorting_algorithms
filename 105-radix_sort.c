#include "sort.h"
/**
* powTen - function that calculates a positive power of 10
* @power: power of 10 to calculate
* Return: result
*/
unsigned int powTen(unsigned int power)
{
	unsigned int i, result;

	result = 1;
	for (i = 0; i < power; i++)
		result *= 10;
	return (result);
}

/**
* countSort - function that sorts an array
* @array: array to be sorted
* @size: size of the array to be sorted
* @digit: digit to sort
* Return: 1, otherwise 0
*/
unsigned int countSort(int *array, size_t size, unsigned int digit)
{
	int i, count[10] = {0};
	int *cpy = NULL;
	size_t j, temp, total = 0;
	unsigned int p_one, p_two, sort = 0;

	p_two = powTen(digit - 1);
	p_one = p_two * 10;
	cpy = malloc(sizeof(int) * size);
	if (!cpy)
		exit(1);
	for (j = 0; j < size; j++)
	{
		cpy[j] = array[j];
		if (array[j] / p_one != 0)
			sort = 1;
	}
	for (i = 0; i < 10 ; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[(array[j] % p_one) / p_two] += 1;
	for (i = 0; i < 10; i++)
	{
		temp = count[i];
		count[i] = total;
		total += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[count[(cpy[j] % p_one) / p_two]] = cpy[j];
		count[(cpy[j] % p_one) / p_two] += 1;
	}
	free(cpy);
	return (sort);
}

/**
* radix_sort - Radix sort algorithm
* @array: array to sort
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	unsigned int i, sort = 1;

	if (!array || size < 2)
		return;
	for (i = 1; sort == 1; i++)
	{
		sort = countSort(array, size, i);
		print_array(array, size);
	}
}

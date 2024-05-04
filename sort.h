#ifndef SORT_H
#define SORT_H
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t *swap_node(listint_t *node, listint_t **list);
void selection_sort(int *array, size_t size);
size_t find_min_index(int *array, size_t start, size_t size);
void swap(int *a, int *b);
int partition(int *array, int low, int high, size_t size);
void q_ksort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void arr_swap(int *a, int *b);
void shell_sort(int *array, size_t size);
void swapList(listint_t **lead, listint_t **follow, int n);
void increaseSort(listint_t **pointer, listint_t **limit, listint_t **list);
void decreaseSort(listint_t **pointer, listint_t **limit, listint_t **list);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
int get_max(int *array, int size);
void sortMerge(size_t start, size_t mid, size_t end, int *dest, int *array);
void splitMergeSort(size_t start, size_t end, int *array, int *clone);
void merge_sort(int *array, size_t size);
void recursionHeap(int *array, int i, size_t size, int limit);
void swapNumber(int *array, int a, int b);
void heap_sort(int *array, size_t size);
unsigned int powTen(unsigned int power);
unsigned int countSort(int *array, size_t size, unsigned int digit);
void radix_sort(int *array, size_t size);

#endif /*SORT_h*/

#include "sort.h"

/**
 * swapList - swaps the elements of the list
 *
 * @lead: first pointer
 * @follow: second pointer
 * @n: 0 for increase, 1 for decrease
 */
void swapList(listint_t **lead, listint_t **follow, int n)
{
	listint_t *aux, *temp;

	aux = *lead;
	temp = *follow;

	temp->prev = aux->prev;
	aux->next = temp->next;

	if (temp->next)
		temp->next->prev = aux;

	if (aux->prev)
		aux->prev->next = temp;

	aux->prev = temp;
	temp->next = aux;

	if (n == 0)
		*lead = temp;
	else
		*follow = aux;
}

/**
 * increaseSort - move the bigger numbers to the end
 *
 * @pointer: pointer to the bigger number
 * @limit: limit of the list
 * @list: list of integers
 */
void increaseSort(listint_t **pointer, listint_t **limit, listint_t **list)
{
	listint_t *aux;

	aux = *pointer;

	while (aux != *limit && aux->next != *limit)
	{
		if (aux->n > aux->next->n)
		{
			swapList(&aux, &(aux->next), 0);
			if (aux->prev == NULL)
				*list = aux;
			print_list(*list);
		}
		aux = aux->next;
	}

	*limit = aux;
	*pointer = aux;
}

/**
 * decreaseSort - moves the smaller numbers to the start
 *
 * @pointer: pointer to the smaller number
 * @limit: limit of the list
 * @list: list of integers
 */
void decreaseSort(listint_t **pointer, listint_t **limit, listint_t **list)
{
	listint_t *aux;

	aux = *pointer;

	while (aux != *limit && aux->prev != *limit)
	{
		if (aux->n < aux->prev->n)
		{
			swapList(&(aux->prev), &aux, 1);
			if (aux->prev->prev == NULL)
				*list = aux->prev;
			print_list(*list);
		}
		aux = aux->prev;
	}

	*limit = aux;
	*pointer = aux;
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * @list: head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limit1, *limit2, *pointer;

	if (!list)
		return;

	if (!*list)
		return;

	limit1 = limit2 = NULL;
	pointer = *list;

	do {
		increaseSort(&pointer, &limit1, list);
		decreaseSort(&pointer, &limit2, list);
	} while (limit1 != limit2);
}

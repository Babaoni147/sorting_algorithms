#include "sort.h"

/**
 * swap_node - swaps two adjacent nodes in a doubly linked list
 * @node: the node to be swapped with its previous node
 * @list: pointer to the head of the doubly linked list
 * Return: pointer to the new head of the list after swapping
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *temp = node->next;

	if (node->prev)
		node->prev->next = temp;
	else
		*list = temp;

	if (temp->next)
		temp->next->prev = node;

	node->next = temp->next;
	temp->prev = node->prev;
	temp->next = node;
	node->prev = temp;

	return (temp);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using an insertion sort algorithm
 * @list: doubly linked list of integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *lead, *follow, *new;

	if (list == NULL || (*list) == NULL || ((*list)->next) == NULL)
		return;

	follow = (*list);
	lead = (*list)->next;

	while (lead)
	{
		new = lead->next;

		while (follow && lead->n < follow->n)
		{
			follow = swap_node(follow, list);
			print_list(*list);
			follow = lead->prev;
		}
		lead = new;
		if (lead)
			follow = lead->prev;
	}
}

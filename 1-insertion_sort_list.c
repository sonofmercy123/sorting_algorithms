#include "sort.h"

/**
 * node_swapper - Function that swaps the
 * place of two nodes and rebuilds connections with
 * the rest of the list
 * @current: The current node to be swapped
 * Return: Nothing
 */
void node_swapper(listint_t *current)
{
	listint_t *temp = current->prev;

	temp->next = current->next;
	if (temp->next != NULL)
		temp->next->prev = temp;

	current->prev = temp->prev;
	if (current->prev != NULL)
		current->prev->next = current;

	current->next = temp;
	temp->prev = current;
}

/**
 * insertion_sort_list - Function that implements the
 * insertion sort algorithm for linked lists
 * @list: The unsorted doubly linked list
 * Return: Nothing
 * Description: Each node is checked against the node before it.
 * If the node is in the wrong spot, move the node backwards until
 * it is in the correct spot. Has a time complexity of O(n)
 * due to only needing 1 loop (and a bunch of if statements)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp = NULL;

	if (!list || !*list || (*list)->next == NULL)
		return;

	current = *list;

	while (current != NULL)
	{
		temp = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			node_swapper(current);
			if ((*list)->prev != NULL && ((*list)->n > (*list)->prev->n))
				*list = (*list)->prev;

			print_list(*list);
		}
		current = temp;
	}
}

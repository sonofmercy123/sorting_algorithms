#include "sort.h"

/**
 * forward_shake - Function that moves a node towards the end
 * of the list
 * @current: The current node to be shifted
 * Return: Nothing
 */
void forward_shake(listint_t *current)
{
	listint_t *temp = current->next;

	current->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = current;
	temp->prev = current->prev;
	if (current->prev != NULL)
		current->prev->next = temp;
	temp->next = current;
	current->prev = temp;
}

/**
 * backward_shake - Function that moves a node towards the beginning
 * of the list
 * @current: The current node to be shifted
 * Return: Nothing
 */
void backward_shake(listint_t *current)
{
	listint_t *temp = current->prev;

	temp->next = current->next;
	if (current->next != NULL)
		current->next->prev = temp;
	current->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = current;
	current->next = temp;
	temp->prev = current;
}

/**
 * start_of_list - Function that ensures list is always pointing
 * to the beginning of the linked list
 * @list: The unsorted linked list
 * Return: Nothing
 */
void start_of_list(listint_t **list)
{
	while ((*list)->prev != NULL && (*list)->n > (*list)->prev->n)
		*list = (*list)->prev;
}

/**
 * cocktail_shaker - The true driving function. Utilizing the
 * concept of a cocktail shaker, this function sorts a list
 * by going back and forth until the list is sorted
 * @list: The unsorted list
 * Return: Nothing
 */
void cocktail_shaker(listint_t **list)
{
	listint_t *current = *list, *list_checker = *list;

	while (list_checker != NULL)
	{
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				forward_shake(current);
				start_of_list(list);
				print_list(*list);
			}
			else
				current = current->next;
		}
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				backward_shake(current);
				start_of_list(list);
				print_list(*list);
			}
			else
				current = current->prev;
		}
		list_checker = *list;
		while (list_checker != NULL)
		{
			if (list_checker->next != NULL && list_checker->n > list_checker->next->n)
			{
				list_checker = *list;
				current = list_checker;
				break;
			}
			else
				list_checker = list_checker->next;
		}
	}
}

/**
 * cocktail_sort_list - The false driving function. Checks for
 * valid list. Solely created to bypass the 40 line restriction
 * @list: The unsorted list
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cocktail_shaker(list);
}

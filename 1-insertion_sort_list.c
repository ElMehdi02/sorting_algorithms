#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 * @list: doubly linked list of integers
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *j, *temp, *curr;

	if (!list || !*list || !(*list)->next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		j = curr;
		while (j->prev && j->n < j->prev->n)
		{
			temp = j->prev;
			if (temp->prev)
				temp->prev->next = j;
			j->prev = temp->prev;
			temp->prev = j;
			temp->next = j->next;
			if (j->next)
				j->next->prev = temp;
			j->next = temp;

			if (!j->prev)
				*list = j;
			print_list(*list);
		}
		curr = curr->next;
	}
}

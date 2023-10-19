#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: doubly linked list to be sorted
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp = NULL;
	int swapped = 1;

	if (!list || !(*list) || !(*list)->next)
		return;

	tmp = *list;
	while (swapped)
	{
		swapped = 0;
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				swap((int *)&(tmp->n), (int *)&(tmp->next->n));
				print_list(*list);
				swapped = 1;
			}
			else
				tmp = tmp->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (tmp->prev)
		{
			if (tmp->n < tmp->prev->n)
			{
				swap((int *)&(tmp->n), (int *)&(tmp->prev->n));
				print_list(*list);
				swapped = 1;
			}
			else
				tmp = tmp->prev;
		}
	}
}

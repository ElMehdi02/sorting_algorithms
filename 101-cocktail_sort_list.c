#include "sort.h"

void swap_ahead(listint_t **list, listint_t **taill, listint_t **shakr);
void swap_behind(listint_t **list, listint_t **taill, listint_t **shakr);
void cocktail_sort_list(listint_t **list);

/**
 * swap_ahead - Swap a node in a listint_t doubly   linked list
 * @list: Pointer to the  head of a doubly  linked list of integers.
 * @taill: Pointer to the  taill of   doubly  linked list.
 * @shakr: Pointer to the current swapping node of the cocktail shakr algo.
 */
void swap_ahead(listint_t **list, listint_t **taill, listint_t **shakr)
{
	listint_t *temp = (*shakr)->next;

	if ((*shakr)->prev != NULL)
		(*shakr)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shakr)->prev;
	(*shakr)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *shakr;
	else
		*taill = *shakr;
	(*shakr)->prev = temp;
	temp->next = *shakr;
	*shakr = temp;
}

/**
 * swap_behind - Swap a node in a listint_t doubly-linked
 * @list: Pointer to the head of a doubly   linked list of integers.
 * @taill: Pointer to the taill of the doubly   linked list.
 * @shakr: Pointer to the current swapping node of the cocktail shakr algo.
 */
void swap_behind(listint_t **list, listint_t **taill, listint_t **shakr)
{
	listint_t *temp = (*shakr)->prev;

	if ((*shakr)->next != NULL)
		(*shakr)->next->prev = temp;
	else
		*taill = temp;
	temp->next = (*shakr)->next;
	(*shakr)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shakr;
	else
		*list = *shakr;
	(*shakr)->next = temp;
	temp->prev = *shakr;
	*shakr = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly   linked list of integers in
 *                      ascending order using the cocktail shakr algorithm.
 * @list: Pointer to the head of a listint_t doubly   linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *taill, *shakr;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (taill = *list; taill->next != NULL;)
		taill = taill->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shakr = *list; shakr != taill; shakr = shakr->next)
		{
			if (shakr->n > shakr->next->n)
			{
				swap_ahead(list, &taill, &shakr);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shakr = shakr->prev; shakr != *list;
				shakr = shakr->prev)
		{
			if (shakr->n < shakr->prev->n)
			{
				swap_behind(list, &taill, &shakr);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}

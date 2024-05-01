#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using insertion sort algorithm.
 *
 * @list: The list to be printed
 */
void insertion_sort_list(listint_t **list)
{
	int found = 0;
	listint_t *tmp, *tmp_nxt = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;
	tmp = *list;
	while (tmp->next)
	{
		if (tmp->n > tmp->next->n)
		{
			tmp->next->prev = tmp->prev;
			if (tmp->next->prev)
				tmp->prev->next = tmp->next;
			else
				*list = tmp->next;

			tmp->prev = tmp->next;
			tmp->next = tmp->next->next;
			tmp->prev->next = tmp;

			if (tmp->next)
				tmp->next->prev = tmp;
			tmp = tmp->prev;
			print_list(*list);

			if (tmp->prev && (tmp->prev->n > tmp->n))
			{
				if (!found)
					tmp_nxt = tmp->next;
				found = 1;
				tmp = tmp->prev;
				continue;
			}
		}
		if (!found)
			tmp = tmp->next;
		else
			tmp = tmp_nxt, found = 0;
	}
}

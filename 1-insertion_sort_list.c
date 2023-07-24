#include "sort.h"
/**
 * insertion_sort_list - insert function
 * @list: a list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *pntr = NULL, *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	pntr = (*list)->next;
	while (pntr)
	{
		while (pntr->prev != NULL && pntr->n < (pntr->prev)->n)
		{
			temp = pntr;
			if (pntr->next)
				(pntr->next)->prev = temp->prev;
			(pntr->prev)->next = temp->next;
			pntr = pntr->prev;
			temp->prev = pntr->prev;
			temp->next = pntr;
			if (pntr->prev)
				(pntr->prev)->next = temp;
			pntr->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
			pntr = pntr->prev;
		}
		pntr = pntr->next;
	}
}

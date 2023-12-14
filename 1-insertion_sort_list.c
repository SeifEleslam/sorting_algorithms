#include "sort.h"

/**
 * insertion_sort_list - Prints an array of integers
 * @list: The array to be printed
 */
void insertion_sort_list(listint_t **list)
{
	size_t i;
	listint_t *curr, *next;

	for (curr = (*list)->next; curr;)
	{
		next = curr->next;
		for (; curr->prev && curr->n < curr->prev->n;)
		{
			swap_nodes(curr, curr->prev);
			if (curr->prev == NULL)
				*list = curr;
			print_list(*list);
		}
		curr = next;
	}
}
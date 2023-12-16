#include "sort.h"

/**
 * assure_node - Prints an array of integers
 * @node: The array to be printed
 */
void assure_node(listint_t *node)
{
	if (!node)
		return;
	if (node->prev)
		node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * swap_nodes - Prints an array of integers
 * @node1: The array to be printed
 * @node2: Number of elements in @array
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	listint_t *temp;

	temp = node1->prev == node2 ? node1 : node1->prev;
	node1->prev = node2->prev == node1 ? node2 : node2->prev;
	node2->prev = temp;
	temp = node1->next == node2 ? node1 : node1->next;
	node1->next = node2->next == node1 ? node2 : node2->next;
	node2->next = temp;
	assure_node(node1);
	assure_node(node2);
}

/**
 * cocktail_sort_list - Prints an array of integers
 * @list: The array to be printed
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr = (*list)->next, *compared;
	size_t dir = 0, swaps = 1, loop = 1;

	if (!list || !*list || !(*list)->next)
		return;
	while (swaps > 0)
	{
		swaps = 0, loop = 1;
		while (loop)
		{
			compared = dir == 0 ? curr->prev : curr->next;
			if ((curr->n < compared->n && dir == 0) ||
				(curr->n > compared->n && dir != 0))
			{
				swap_nodes(curr, compared), swaps += 1;
				while ((*list)->prev)
					*list = (*list)->prev;
				curr = dir == 0 ? curr->next : curr->prev;
				print_list(*list);
			}
			loop = !curr->next || !curr->prev ? 0 : loop;
			dir = !curr->next ? 1 : !curr->prev ? 0
												: dir;
			curr = dir == 0 ? curr->next : curr->prev;
		}
	}
}

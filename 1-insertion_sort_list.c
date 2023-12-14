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
 * insertion_sort_list - Prints an array of integers
 * @list: The array to be printed
 */
void insertion_sort_list(listint_t **list)
{
	size_t i;
	listint_t *curr, *next;

	if (!list || !*list)
		return;
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
#include "sort.h"

/**
 * swap_array - Prints an array of integers
 * @array: The array to be printed
 * @idx1: Number of elements in @array
 * @idx2: Number of elements in @array
 */
// void swap_array(int *array, size_t idx1, size_t idx2)
// {
// 	int temp;

// 	temp = array[idx1];
// 	array[idx1] = array[idx2];
// 	array[idx2] = temp;
// }

/**
 * swap_nodes - Prints an array of integers
 * @node1: The array to be printed
 * @node2: Number of elements in @array
 */
// void swap_nodes(listint_t *node1, listint_t *node2)
// {
// 	listint_t *temp;

// 	temp = node1->prev == node2 ? node1 : node1->prev;
// 	node1->prev = node2->prev == node1 ? node2 : node2->prev;
// 	node2->prev = temp;
// 	temp = node1->next == node2 ? node1 : node1->next;
// 	node1->next = node2->next == node1 ? node2 : node2->next;
// 	node2->next = temp;
// 	assure_node(node1);
// 	assure_node(node2);
// }

/**
 * insert_before_node - Prints an array of integers
 * @node1: The array to be printed
 * @node2: Number of elements in @array
 */
// void insert_before_node(listint_t *node1, listint_t *node2)
// {
// 	if (node1->prev)
// 		node1->prev->next = node1->next;
// 	if (node1->next)
// 		node1->next->prev = node1->prev;
// 	node1->prev = node2->prev;
// 	node2->prev = node1;
// 	node1->next = node2;
// 	assure_node(node1);
// }

// /**
//  * assure_node - Prints an array of integers
//  * @node: The array to be printed
//  */
// void assure_node(listint_t *node)
// {
// 	if (!node)
// 		return;
// 	if (node->prev)
// 		node->prev->next = node;
// 	if (node->next)
// 		node->next->prev = node;
// }
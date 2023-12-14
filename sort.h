#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdlib.h>
#include <stdio.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_array(int *array, size_t idx1, size_t idx2);
void swap_nodes(listint_t *node1, listint_t *node2);
void insert_before_node(listint_t *node1, listint_t *node2);
void assure_node(listint_t *node);

/* Sort Algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

#endif

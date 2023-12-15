#include "sort.h"

/**
 * swap_array - Prints an array of integers
 * @array: The array to be printed
 * @idx1: Number of elements in @array
 * @idx2: Number of elements in @array
 */
void swap_array(int *array, size_t idx1, size_t idx2)
{
	int temp;

	temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
}

/**
 * insertion_sort_list - Prints an array of integers
 * @list: The array to be printed
 */
void selection_sort(int *array, size_t size)
{
	size_t i, l, smallest;

	for (i = 0; i < size; i++)
	{
		for (l = i, smallest = i; l < size; l++)
			if (array[l] < array[smallest])
				smallest = l;
		if (smallest != i)
			swap_array(array, smallest, i), print_array(array, size);
	}
}
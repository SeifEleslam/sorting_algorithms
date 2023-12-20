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
 * recursive_quick_sort - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @p_array: The array to be printed
 * @p_size: Number of elements in @array
 */
void recursive_quick_sort(int *array, size_t size,
						  int *p_array, size_t p_size)
{
	size_t i, l;
	int pivot;

	if (size <= 1 || !array)
		return;
	pivot = array[size - 1], i = 0, l = size - 1;
	while (1)
	{
		while (array[i] < pivot)
			i++;
		while (array[l] > pivot)
			l--;
		if (i >= l)
			break;

		swap_array(array, i, l), print_array(p_array, p_size), i++, l--;
	}
	if (array[l] == pivot)
		l--;
	recursive_quick_sort(array, l + 1, p_array, p_size);
	recursive_quick_sort(array + l + 1, size - l - 1, p_array, p_size);
}

/**
 * quick_sort_hoare - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void quick_sort_hoare(int *array, size_t size)
{
	recursive_quick_sort(array, size, array, size);
}

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
	size_t i, l, pivot;

	if (size <= 1 || !array)
		return;
	for (i = 0, l = 0, pivot = size - 1; l < pivot; l++)
		if (array[l] <= array[pivot])
		{
			if (l != i)
				swap_array(array, l, i), print_array(p_array, p_size);
			i++;
		}
	if (i != pivot)
		swap_array(array, pivot, i), print_array(p_array, p_size);
	recursive_quick_sort(array, i, p_array, p_size);
	recursive_quick_sort(array + i + 1, size - i - 1, p_array, p_size);
}

/**
 * quick_sort - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	recursive_quick_sort(array, size, array, size);
}

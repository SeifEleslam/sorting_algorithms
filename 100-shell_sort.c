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
 * Knuth_gap - Prints an array of integers
 * @size: Number of elements in @array
 */
size_t Knuth_gap(size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = gap * 3 + 1;
	return gap / 3;
}

/**
 * selection_sort - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, l;
	int curr;

	if (!array || size <= 0)
		return;
	for (gap = Knuth_gap(size); gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			curr = array[i];
			for (l = i; l >= gap && array[l - gap] > curr; l -= gap)
				array[l] = array[l - gap];
			array[l] = curr;
		}
		print_array(array, size);
	}
}

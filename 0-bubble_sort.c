#include "sort.h"

/**
 * bubble_sort - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, changed;

	changed = 1;
	while (changed)
	{
		changed = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_array(array, i, i + 1);
				changed = 1;
				print_array(array, size);
			}
		}
	}
}
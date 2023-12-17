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
 * _max - Prints an array of integers
 * @array: The array to be printed
 * @idx1: Number of elements in @array
 * @idx2: Number of elements in @array
 * Return: idx of max
 */
size_t _max(int *array, size_t idx1, size_t idx2)
{
	return (array[idx1] < array[idx2] ? idx2 : idx1);
}

/**
 * heapify - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @max_size: Number of elements in @array
 * @idx: Number of elements in @array
 *
 */
void heapify(int *array, size_t size, size_t max_size, size_t idx)
{
	size_t max;

	if (idx * 2 + 1 >= max_size)
		return;
	heapify(array, size, max_size, idx * 2 + 1);
	if (idx * 2 + 2 < max_size)
		heapify(array, size, max_size, idx * 2 + 2),
			max = _max(array, 2 * idx + 1, 2 * idx + 2);
	else
		max = 2 * idx + 1;
	if (array[max] > array[idx])
		swap_array(array, idx, max), print_array(array, size),
			heapify(array, size, max_size, max);
}

/**
 * heap_sort - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array || size <= 0)
		return;
	for (i = 0; i < size - 1; i++)
		heapify(array, size, size - i, 0),
			swap_array(array, 0, size - i - 1),
			print_array(array, size),
			heapify(array, size, size - i - 1, 0);
}

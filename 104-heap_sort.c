#include "sort.h"

/**
 * swap_array - Prints an array of integers
 * @num1: Number of elements in @array
 * @num2: Number of elements in @array
 */
void swap_array(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * _max - Prints an array of integers
 * @num1: The array to be printed
 * @num2: Number of elements in @array
 * Return: pointer to num
 */
int *_max(int *num1, int *num2)
{
	return (*num1 < *num2 ? num2 : num1);
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
	int *max;

	if (idx * 2 + 1 >= max_size)
		return;
	heapify(array, size, max_size, idx * 2 + 1);
	if (idx * 2 + 2 < max_size)
		heapify(array, size, max_size, idx * 2 + 2),
			max = _max(array + 2 * idx + 1, array + 2 * idx + 2);
	else
		max = array + 2 * idx + 1;
	if (*max >= array[idx])
		swap_array(&array[idx], max), print_array(array, size),
			heapify(array, size, max_size, idx);
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
			swap_array(array, array + size - i - 1),
			print_array(array, size);
}

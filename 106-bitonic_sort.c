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
 * merge - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @dir: Number of elements in @array
 */
void merge(int *array, size_t size, size_t dir)
{
	size_t i;

	if (size < 2)
		return;
	for (i = 0; i < size / 2; i++)
		if ((array[i] > array[i + size / 2] && dir == 0) ||
			(array[i] < array[i + size / 2] && dir == 1))
			swap_array(array, i, i + size / 2);
	merge(array, size / 2, dir);
	merge(array + (size / 2), size / 2, dir);
}

/**
 * bitonize - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @dir: Number of elements in @array
 */
void bitonize(int *array, size_t size, size_t total_size, size_t dir)
{
	if (size < 2)
		return;
	printf("Merging [%ld/%ld] (%s):\n", size, total_size, dir == 0 ? "UP" : "DOWN");
	print_array(array, size);
	bitonize(array, size / 2, total_size, 0);
	bitonize(array + (size / 2), size / 2, total_size, 1);
	merge(array, size, dir);
	printf("Result [%ld/%ld] (%s):\n", size, total_size, dir == 0 ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_sort - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bitonic_sort(int *array, size_t size)
{
	bitonize(array, size, size, 0);
}

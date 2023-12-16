#include "sort.h"

/**
 * counting_sort - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max, *out_arr, *count_arr;

	if (!array || size <= 0)
		return;
	for (i = 1, max = array[0]; i < size; i++)
		if (max <= array[i])
			max = array[i] + 1;
	count_arr = malloc(sizeof(int) * max);
	out_arr = malloc(sizeof(int) * size);
	for (i = 0; i < (size_t)max; i++)
		count_arr[i] = 0;
	for (i = 0; i < size; i++)
		count_arr[array[i]] += 1;
	for (i = 1; i < (size_t)max; i++)
		count_arr[i] = count_arr[i] + count_arr[i - 1];
	print_array(count_arr, (size_t)max);
	for (i = 0; i < size; i++)
		out_arr[count_arr[array[i]] - 1] = array[i];
	for (i = 0; i < size; i++)
		array[i] = out_arr[i];
	free(out_arr), free(count_arr);
}

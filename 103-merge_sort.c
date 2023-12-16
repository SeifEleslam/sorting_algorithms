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
 * merge_sort - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	size_t i, l, d, size1, size2;
	int *new_arr;

	if (size <= 1)
		return;
	size1 = size / 2, size2 = size - size1;
	merge_sort(array, size1);
	merge_sort(&array[size1], size2);
	new_arr = malloc(sizeof(int) * size);
	printf("Merging...\n");
	printf("[left]: "), print_array(array, size1);
	printf("[right]: "), print_array(&array[size1], size2);
	for (i = 0; i < size; i++)
		new_arr[i] = -1;
	for (i = 0, d = 0; i < size1; i++)
		for (l = d; l < size2; l++)
			if (array[i] > array[l + size1])
				new_arr[i + l] = array[l + size1], array[l + size1] = -1, d++;
			else
				break;
	for (i = 0, l = 0; i < size && l < size; i++)
	{
		while (array[l] == -1 && l < size)
			l++;
		if (new_arr[i] == -1 && l < size)
			new_arr[i] = array[l], array[l] = -1;
	}
	for (i = 0; i < size; i++)
		array[i] = new_arr[i];
	free(new_arr);
	printf("[Done]: "), print_array(array, size);
}

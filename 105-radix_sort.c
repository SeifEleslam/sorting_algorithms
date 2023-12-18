#include "sort.h"

/**
 * get_digit - Prints an array of integers
 * @num: The array to be printed
 * @digit_num: Number of elements in @array
 * Return: Number of elements in @array
 */
size_t get_digit(int num, size_t digit_num)
{
	for (; digit_num > 10; digit_num /= 10)
		num /= 10;
	num = num % 10;
	return (num);
}

/**
 * digit_max - Prints an array of integers
 * @array: The array to be printed
 * @size: The array to be printed
 * @digit_num: Number of elements in @array
 * Return: idx of max
 */
size_t digit_max(int *array, size_t size, size_t digit_num)
{
	size_t i, max, curr;

	max = get_digit(array[0], digit_num);
	for (i = 0; i < size; i++)
	{
		curr = get_digit(array[i], digit_num);
		if (max < curr)
			max = curr;
	}
	return (max);
}

/**
 * digit_counting_sort - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @digit_num: The array to be printed
 * @max_digit: Number of elements in @array
 */
void digit_counting_sort(int *array, size_t size,
						 size_t digit_num, size_t max_digit)
{
	size_t i;
	int max, *out_arr, *count_arr;

	if (!array || size <= 1)
		return;
	for (i = 1, max = array[0] + 1; i < size; i++)
		if (max <= array[i])
			max = array[i] + 1;
	count_arr = malloc(sizeof(int) * max_digit);
	out_arr = malloc(sizeof(int) * size);
	for (i = 0; i < (size_t)max_digit; i++)
		count_arr[i] = 0;
	for (i = 0; i < size; i++)
		count_arr[get_digit(array[i], digit_num)] += 1;
	for (i = 1; i < (size_t)max_digit; i++)
		count_arr[i] = count_arr[i] + count_arr[i - 1];
	for (i = 0; i < size; i++)
		out_arr[count_arr[get_digit(array[size - i - 1],
									digit_num)] -
				1] = array[size - i - 1],
				count_arr[get_digit(array[size - i - 1], digit_num)]--;
	for (i = 0; i < size; i++)
		array[i] = out_arr[i];
	free(out_arr), free(count_arr);
	print_array(array, size);
}

/**
 * radix_sort - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	size_t i, digits;
	int max;

	if (!array || size < 2)
		return;

	for (i = 1, max = array[0]; i < size; i++)
		if (array[i] > max)
			max = array[i];
	for (digits = 10; max >= 10; max /= 10)
		digits *= 10;
	for (i = 10; i <= digits; i *= 10)
		digit_counting_sort(array, size, i, digit_max(array, size, i) + 1);
}

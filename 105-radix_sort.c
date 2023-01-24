#include "sort.h"

/**
 * lsd_sort - Function that sorts an array using LSD Radix Sort
 * @array: The array to be sorted
 * @count: Array for counting
 * @temp: The temporary array
 * @size: The size of the passed in array
 * @digit_pointer: Points to the digit in each value
 * Return: Nothing
 * Description: LSD stands for least significat digit. LSD Radix
 * Sort works by looking at the digit in the rightmost position
 * and performing ascending sort based on this. This is
 * repeated until digit_pointer points to 0 for the highest
 * value in the array, which by then we would know that
 * the entire array would have been properly sorted. For easier
 * understanding, treat each value in the array like a string
 * and that we are reading from right to left
 */
void lsd_sort(int *array, int *count, int *temp, size_t size,
		size_t digit_pointer)
{
	int j;
	size_t i;

	/*
	 * Initialization to 0 is necessary. Apparently
	 * temp and count would be holding random values
	 * which could interfere with the final results otherwise
	 */
	for (i = 0; i < size; i++)
		temp[i] = 0, count[i] = 0;

	/* Count the occurance of a number at the digit position */
	for (i = 0; i < size; i++)
		count[(array[i] / digit_pointer) % 10]++;

	/* This is borrowed from counting sort */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Determine where the value should be placed in the array */
	for (j = size - 1; j >= 0; j--)
	{
		temp[count[(array[j] / digit_pointer) % 10] - 1] = array[j];
		count[(array[j] / digit_pointer) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	print_array(array, size);
}

/**
 * radix_sort - Driver function. Checks for valid array, finds
 * the highest value in the array, then calls the workhorse function
 * @array: The unsorted array
 * @size: The size of the passed in array
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	size_t max_value = 0, i;
	int *count = NULL, *temp = NULL;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > (int)max_value)
			max_value = array[i];

	temp = malloc(sizeof(array) * (size));
	if (temp == NULL)
		return;

	count = malloc(sizeof(array) * (size));
	if (count == NULL)
	{
		free(temp);
		return;
	}

	for (i = 1; max_value / i > 0; i *= 10)
		lsd_sort(array, count, temp, size, i);

	free(count);
	free(temp);
}

#include "sort.h"

/**
 * rewrite_array - Function that ultimately replaces the
 * unsorted array with the sorted array
 * @array: The passed in unsorted array
 * @new_array: A created array counting duplicate values, if any
 * @third_array: A created array holding the properly sorted array
 * @size: Size of the passed in unsorted array
 * Return: Nothing
 */
void rewrite_array(int *array, int *new_array, int *third_array, size_t size)
{
	int i;
	size_t j;

	/**
	 * This part may be confusing as there are nested indexes.
	 * For this loop, we take the original array and work backwards.
	 * We access the value at third_array, which is the value
	 * of new_array, which is the value of array at index i
	 * For example, with an array of [3, 2, 4, 7, 1], our
	 * goal is [1, 2, 3, 4, 7]. Our new_array would look like this:
	 * [0, 1, 2, 3, 4, 4, 4, 5]
	 * Working backwards, we access what value new_array[1] holds,
	 * subtract 1, and decide that third_array at this index is where
	 * we put our value. In this case, 1. Decrement by 1, as we have
	 * one less index to fill
	 * Next, array[i] = 7. new_array[7] says 5, so subtract by 1.
	 * 7 should be at third_array[4], so it goes there.
	 * Repeat with 4, 2, and 3, and the array becomes sorted.
	 */
	for (i = size - 1; i >= 0; i--)
	{
		third_array[new_array[array[i]] - 1] = array[i];
		new_array[array[i]]--;
	}

	for (j = 0; j < size; j++)
		array[j] = third_array[j];
}

/**
 * array_for_print - Function that prints the counting array
 * The number only increments when the value exists in the
 * original array, and this is ultimately used for rewrite_array
 * @new_array: A created array counting duplicate values, if any
 * @size: Size of the passed in array
 * Return: Nothing
 */
void array_for_print(int *new_array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		new_array[i] += new_array[i - 1];

	print_array(new_array, size);
}

/**
 * value_checker - Function that checks how many of a
 * value is present in the array. Later used to determine
 * value placement and printing
 * @array: The passed in array
 * @new_array: A created array counting duplicate values, if any
 * @new_size: Size of new_array. Named as such to avoid confusion
 * Return: Nothing
 */
void value_checker(int *array, int *new_array, size_t new_size)
{
	size_t i, j;

	for (i = 0; i < new_size; i++)
	{
		j = array[i];
		new_array[j] += 1;
	}
}

/**
 * counting_sort - Driver function. Using the concept of
 * counting sort, sort the given array
 * @array: The unsorted array
 * @size: Size of the passed in array
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *new_array = NULL, *third_array = NULL;
	size_t big_num = 0, i;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
		if ((int)big_num < array[i])
			big_num = array[i];

	new_array = malloc(sizeof(array[0]) * (big_num + 1));
	if (new_array == NULL)
		return;

	third_array = malloc(sizeof(array[0]) * (big_num + 1));
	if (third_array == NULL)
	{
		free(new_array);
		return;
	}

	for (i = 0; i <= big_num; i++)
		new_array[i] = 0;

	value_checker(array, new_array, size);
	array_for_print(new_array, big_num + 1);
	rewrite_array(array, new_array, third_array, size);
	free(new_array);
	free(third_array);
}

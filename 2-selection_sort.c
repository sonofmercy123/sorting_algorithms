#include "sort.h"

/**
 * selection_sort - Function that sorts the array using
 * the selection sort algorithm
 * @array: The unsorted array
 * @size: The size of the passed in array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int min_value, swapper;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapper = 0;
		min_index = i;
		min_value = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min_value)
			{
				min_value = array[j];
				min_index = j;
				swapper = 1;
			}
		}

		array[min_index] = array[i];
		array[i] = min_value;
		if (swapper == 1)
			print_array(array, size);
	}
}

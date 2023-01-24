#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the Bubble
 *sort algorithm.
 *@array: is the array of integers to be reordered
 *@size: is the size of the array
 *Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, temp;
	int swapper;

	if (array == NULL || size < 2)
		return;
	do {
		swapper = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapper = 1;
				if (swapper == 1)
					print_array(array, size);
			}
		}
	} while (swapper == 1);
}

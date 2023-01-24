#include "sort.h"

/**
 * print_before_merge - Function that prints all values to the left
 * and right of the array at the midpoint before any merging occurs
 * @array: The unsorted array
 * @temp: The throwaway array
 * @begin: The first index of the array
 * @mid: The midpoint of the array
 * @end: The last index of the array
 * Return: Nothing
 */
void print_before_merge(int *array, int *temp, size_t begin, size_t mid,
			size_t end)
{
	size_t i = begin, j = mid + 1, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	while (i <= mid)
	{
		temp[k] = array[i];
		k++, i++;
	}

	print_array(temp, k);
	k = 0;
	printf("[right]: ");

	while (j <= end)
	{
		temp[k] = array[j];
		k++, j++;
	}

	print_array(temp, k);
}

/**
 * rebuild_array - The workhorse function. Copies the unsorted array
 * to a temporary array, then determines which value goes where
 * @array: The unsorted array
 * @temp: The throwaway array
 * @begin: The first index of the array
 * @mid: The midpoint of the array
 * @end: The last index of the array
 * Return: Nothing
 */
void rebuild_array(int *array, int *temp, size_t begin, size_t mid, size_t end)
{
	size_t i = begin, j = mid + 1, k = 0;

	print_before_merge(array, temp, begin, mid, end);

	while (i <= mid && j <= end)
	{
		if (array[i] <= array[j])
		{
			temp[k] = array[i];
			k++, i++;
		}
		else
		{
			temp[k] = array[j];
			k++, j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = array[i];
		k++, i++;
	}

	while (j <= end)
	{
		temp[k] = array[j];
		k++, j++;
	}

	printf("[Done]: ");
	print_array(temp, k);

	for (i = begin; i <= end; i++)
		array[i] = temp[i - begin];
}

/**
 * split_array - Function that "splits" the array. Basically
 * a function that calls itself recursively, as we want to try
 * to break down the array until we get an array of size 1
 * This is known as the top-down merge sort algorithm
 * @array: The unsorted array
 * @temp: The throwaway array
 * @begin: The first index of the array
 * @end: The last index of the array
 * Return: Nothing
 */
void split_array(int *array, int *temp, size_t begin, size_t end)
{
	size_t mid = (end + begin - 1) / 2;

	if (begin < end)
	{
		split_array(array, temp, begin, mid);
		split_array(array, temp, mid + 1, end);
		rebuild_array(array, temp, begin, mid, end);
	}
}

/**
 * merge_sort - The driver function. Handles checking for
 * valid array and creating and freeing the temp array
 * @array: The unsorted array
 * @size: The size of the passed in array
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(array[0]) * size);
	if (temp == NULL)
		return;

	split_array(array, temp, 0, size - 1);
	free(temp);
}

#include "sort.h"

/**
 * quick_sort - Calls quick_sort_rep function
 * @array: The array to be printed
 * @size: The number of element of the @array
 */

void quick_sort(int *array, size_t size)
{
	int low = 0;
	int high = size - 1;

	if (!array || size < 2)
		return;
	quick_sort_rep(array, low, high, size);
}

/**
 * quick_sort_rep - Sorts an array of integers in ascending order
 * using Quick sort algorithm
 * @array: The array to be printed
 * @low: The start of the array
 * @high: The end of the array
 * @size: The number of element of the @array
 */
void quick_sort_rep(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);

		quick_sort_rep(array, low, pi - 1, size);
		quick_sort_rep(array, pi + 1, high, size);
	}
}

/**
 * lomuto_partition - Partition the array using the last element as the pivot
 * @array: The array to be printed
 * @low: The start of the array
 * @high: The end of the array
 * @size: The number of element of the @array
 *
 * Return: the index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp = 0;

	i = low;
	pivot = array[high];

	for (j = low; j < high; ++j)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			if (temp != array[i])
				print_array(array, size);
			++i;
		}
	}

	temp = array[i];
	array[i] = array[high];
	array[high] = temp;

	if (temp != array[i])
		print_array(array, size);

	return (i);
}

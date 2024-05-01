#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using Shell sort algorithm, using Knuth sequence
 * @array: The array to be sorted
 * @size: The number of elements in @array
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j = 0;
	size_t gap = 1;
	int temp = 0;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		i = gap;
		while (i < size)
		{
			temp = array[i];
			j = i;

			while ((j > gap - 1) && array[j - gap] >= temp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}

			array[j] = temp;
			i++;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}


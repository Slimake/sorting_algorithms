#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the @array.
 *
 */

void counting_sort(int *array, size_t size)
{
	int max = 0, i = 1;
	int *count = NULL, *temp = NULL;

	if (!array || size < 2)
		return;
	max = array[0];
	while (i < (int)size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	count = malloc(sizeof(int) * max + 1);
	if (!count)
	{
		free(temp);
		return;
	}

	for (i = 0; i <= (int)max; ++i)
		count[i] = 0;
	for (i = 0; i < (int)size; ++i)
		count[array[i]]++;
	for (i = 1; i <= (int)max; ++i)
		count[i] = count[i - 1] + count[i];
	print_array(count, max + 1);
	for (i = 0; i < (int)size; ++i)
	{
		temp[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; ++i)
		array[i] = temp[i];

	free(count);
	free(temp);
}


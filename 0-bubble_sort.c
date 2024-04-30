#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in
 * ascending order using bubble sort algorithm
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;
	size_t swap = 0;

	if (size < 2)
		return;

	/* Loop through the array each time the inner loop runs */
	i = 0;
	while (array && i <= size - 1)
	{
		/* Loop through elements in the array */
		for (j = 0; j <= size - 2; j++)
		{
			/* Swap elements if condition is True */
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;

				print_array(array, size);
				swap++;
			}
		}
		/* If no swap break the loop */
		if (swap == 0)
			break;

		i++;
	}
}

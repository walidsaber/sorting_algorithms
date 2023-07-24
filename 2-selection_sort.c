#include "sort.h"

/**
 * selection_sort - selecting function
 * @array: the array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, k = 0, temp = 0;

	if (array == NULL || size == 0)
		return;

	for (; i < size - 1; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[k])
				k = j;
		}
		if (k != i)
		{
			temp = array[i];
			array[i] = array[k];
			array[k] = temp;
			print_array(array, size);
		}
	}
}

#include "sort.h"

/**
 * quick_sort - quick sorting
 * @array: array
 * @size: size

*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	rec(array, 0, size - 1, size);
}

/**
 * rec - rec of the function
 * @array: array
 * @lower: lower
 * @higher: higher
 * @size: size
 */
void rec(int *array, int lower, int higher, size_t size)
{
	int l_p = 0;

	if (lower < higher)
	{
		l_p = Lomuto(array, lower, higher, size);
		rec(array, lower, l_p - 1, size);
		rec(array, l_p + 1, higher, size);
	}
}

/**
 * Lomuto - Lomuto partition scheme
 * @array: the array
 * @lower: low
 * @higher: high
 * @size: size
 */
int Lomuto(int *array, int lower, int higher, size_t size)
{
	int i = 0, j = 0, pivot = 0, aux = 0;

	pivot = array[higher];
	i = lower;

	for (j = lower; j < higher; ++j)
	{
		if (array[j] < pivot)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;

			if (aux != array[i])
				print_array(array, size);

			++i;
		}
	}

	aux = array[i];
	array[i] = array[higher];
	array[higher] = aux;

	if (aux != array[i])
		print_array(array, size);

	return (i);
}

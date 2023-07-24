#include "sort.h"

/**
 * shell_sort - shell sortin method
 * @array: the array
 * @size: array size
 */

void shell_sort(int *array, size_t size)
{
	int i = 0, k = 0, avg = 1, temp = 0;

	if (!array || size < 2)
		return;

	while (avg < (int) size / 3)
		avg = avg * 3 + 1;

	while (avg > 0)
	{
		k = avg;
		while (k < (int) size)
		{
			temp = array[k];
			i = k;

			while (i > avg - 1 && array[i - avg] >= temp)
			{
				array[i] = array[i - avg];
				i = i - avg;
			}

			array[i] = temp;
			k++;
		}
		print_array(array, size);
		avg = (avg - 1) / 3;
	}
}

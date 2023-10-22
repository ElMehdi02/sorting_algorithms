#include "sort.h"

/**
 * swap_nbrs - Swap two numbers in an array.
 * @x:   first number to swap.
 * @y:   second number to swap.
 */
void swap_nbrs(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * shell_sort - Sort an array of numbers in ascending order
 * @array: An array of numbers.
 * @size:   size of   array.
 *
 * Description: Uses   Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gapp, x, y;

	if (array == NULL || size < 2)
		return;

	for (gapp = 1; gapp < (size / 3);)
		gapp = gapp * 3 + 1;

	for (; gapp >= 1; gapp /= 3)
	{
		for (x = gapp; x < size; x++)
		{
			y = x;
			while (y >= gapp && array[y - gapp] > array[y])
			{
				swap_nbrs(array + y, array + (y - gapp));
				y -= gapp;
			}
		}
		print_array(array, size);
	}
}

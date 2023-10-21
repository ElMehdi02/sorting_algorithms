#include "sort.h"

/**
 * swap - swap two elements in an array
 * @array: array of integers
 * @i: index of first element
 * @j: index of second element
 * Return: void
 */

void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * partition - partition an array using the Lomuto partition scheme
 * @array: array of integers
 * @start: lowest index of array
 * @end: highest index of array
 * @size: size of array
 * Return: index of pivot
 */

int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start - 1;
	int j;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, i, j);
			if (i != j)
				print_array(array, size);
		}
	}
	if (array[end] < array[i + 1])
	{
		swap(array, i + 1, end);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - recursive helper function for quick_sort
 * @array: array of integers
 * @start: lowest index of array
 * @end: highest index of array
 * @size: size of array
 * Return: void
 */

void quick_sort_recursive(int *array, int start, int end, size_t size)
{
	int p;

	if (start < end)
	{
		p = partition(array, start, end, size);
		quick_sort_recursive(array, start, p - 1, size);
		quick_sort_recursive(array, p + 1, end, size);
	}
}

/**
 * quick_sort - sort an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

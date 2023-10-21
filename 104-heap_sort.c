#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify - heapifies a subtree
 * @array: array to be sorted
 * @size: size of the array
 * @i: index of the subtree
 * @len: size of the heap
 */

void heapify(int *array, size_t size, int i, size_t len)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < (int)len && array[left] > array[max])
		max = left;

	if (right < (int)len && array[right] > array[max])
		max = right;

	if (max != i)
	{
		swap(&array[i], &array[max]);
		print_array(array, size);
		heapify(array, size, max, len);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}

#include "sort.h"

/**
 * merge - Sort a array of integers.
 * @array: An array of an array of integers to sort.
 * @temp_arr: A temp_arr to store the sorted array.
 * @low: The low index of the array.
 * @mid: The middle index of the array.
 * @high: The high index of the array.
 */
void merge(int *array, int *temp_arr, size_t low, size_t mid,
		size_t high)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + low, mid - low);

	printf("[right]: ");
	print_array(array + mid, high - mid);

	for (i = low, j = mid; i < mid && j < high; k++)
	{
		if (array[i] < array[j])
			temp_arr[k] = array[i++];
		else
			temp_arr[k] = array[j++];
	}
	for (; i < mid; i++)
		temp_arr[k++] = array[i];
	for (; j < high; j++)
		temp_arr[k++] = array[j];
	for (i = low, k = 0; i < high; i++)
		array[i] = temp_arr[k++];

	printf("[Done]: ");
	print_array(array + low, high - low);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @array: An array of an array of integers to sort.
 * @temp_arr: A temp_arr to store the sorted result.
 * @low: The low index of the array.
 * @high: The high index of the array.
 */
void merge_sort_recursive(int *array, int *temp_arr, size_t low, size_t high)
{
	size_t mid;

	if (high - low > 1)
	{
		mid = low + (high - low) / 2;
		merge_sort_recursive(array, temp_arr, low, mid);
		merge_sort_recursive(array, temp_arr, mid, high);
		merge(array, temp_arr, low, mid, high);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *temp_arr;

	if (array == NULL || size < 2)
		return;

	temp_arr = malloc(sizeof(int) * size);
	if (temp_arr == NULL)
		return;

	merge_sort_recursive(array, temp_arr, 0, size);

	free(temp_arr);
}

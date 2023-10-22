#include "sort.h"

void merge_sub(int *sub, int *buffr, size_t front, size_t mid,
		size_t back);
void merge_recursive(int *sub, int *buffr, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_sub - Sort a sub array of integers.
 * @sub: sub array of an array of integers to sort.
 * @buffr: buffer to store the sorted subarray.
 * @front: front index of the array.
 * @mid: middle index of the array.
 * @back: back index of the array.
 */
void merge_sub(int *sub, int *buffr, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub + front, mid - front);

	printf("[right]: ");
	print_array(sub + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buffr[k] = (sub[i] < sub[j]) ? sub[i++] : sub[j++];
	for (; i < mid; i++)
		buffr[k++] = sub[i];
	for (; j < back; j++)
		buffr[k++] = sub[j];
	for (i = front, k = 0; i < back; i++)
		sub[i] = buffr[k++];

	printf("[Done]: ");
	print_array(sub + front, back - front);
}

/**
 * merge_recursive - Implement the merge sort algorithm through recursion.
 * @sub: A sub array of an array of integers to sort.
 * @buffr: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_recursive(int *sub, int *buffr, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_recursive(sub, buffr, front, mid);
		merge_recursive(sub, buffr, mid, back);
		merge_sub(sub, buffr, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: an Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffr;

	if (array == NULL || size < 2)
		return;

	buffr = malloc(sizeof(int) * size);
	if (buffr == NULL)
		return;

	merge_recursive(array, buffr, 0, size);

	free(buffr);
}

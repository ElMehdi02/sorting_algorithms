#include "sort.h"
#define UP 0
#define DOWN 1


void swap_nbrs(int *a, int *b);
void bitonic_mrg(int *array, size_t size, size_t start, size_t seque,char flw);
void bitonic_seque(int *array, size_t size, size_t start, size_t seque, char flw);
void bitonic_sort(int *array, size_t size);

/**
 * swap_nbrs - Swap two integers in an array.
 * @a:   first integer to swap.
 * @b:   second integer to swap.
 */
void swap_nbrs(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bitonic_mrg - Sort a bitonic sequence inside   array of integers.
 * @array:   array of integers.
 * @size:   size of   array.
 * @start:   starting index of   sequence in array to sort.
 * @seque:   size of   sequence to sort.
 * @flw:   direction to sort in.
 */
void bitonic_mrg(int *array, size_t size, size_t start, size_t seque,
		char flw)
{
	size_t i, jmp = seque / 2;

	if (seque > 1)
	{
		for (i = start; i < start + jmp; i++)
		{
			if ((flw == UP && array[i] > array[i + jmp]) ||
			    (flw == DOWN && array[i] < array[i + jmp]))
				swap_nbrs(array + i, array + i + jmp);
		}
		bitonic_mrg(array, size, start, jmp, flw);
		bitonic_mrg(array, size, start + jmp, jmp, flw);
	}
}

/**
 * bitonic_seque - Convert   array of integers into a bitonic sequence.
 * @array:   array of integers.
 * @size:   size of   array.
 * @start:   starting index of a block of   building bitonic sequence.
 * @seque:   size of a block of   building bitonic sequence.
 * @flw:   direction to sort   bitonic sequence block in.
 */
void bitonic_seque(int *array, size_t size, size_t start, size_t seque, char flw)
{
	size_t cut = seque / 2;
	char *str = (flw == UP) ? "UP" : "DOWN";

	if (seque > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seque, size, str);
		print_array(array + start, seque);

		bitonic_seque(array, size, start, cut, UP);
		bitonic_seque(array, size, start + cut, cut, DOWN);
		bitonic_mrg(array, size, start, seque, flw);

		printf("Result [%lu/%lu] (%s):\n", seque, size, str);
		print_array(array + start, seque);
	}
}

/**
 * bitonic_sort - Sort   array of integers in ascending
 *                order using   bitonic sort algorithm.
 * @array:   array of integers.
 * @size:   size of   array.
 *
 * Description: Prints   array after each swap. Only works for
 * size equal to powers of two
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seque(array, size, 0, size, UP);
}

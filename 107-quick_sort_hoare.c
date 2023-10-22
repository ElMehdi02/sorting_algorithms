#include "sort.h"

void swap_nbrs(int *x, int *y);
int hoare_parti(int *array, size_t size, int lefts, int rights);
void hoare_srt(int *array, size_t size, int lefts, int rights);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_nbrs - Swap two integers in an array.
 * @x: first integer to swap.
 * @y: second integer to swap.
 */
void swap_nbrs(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * hoare_parti- Order a subset of an array of integers
 * @array: array of integers.
 * @size:  size of   array.
 * @lefts: starting index of   subset to order.
 * @rights: ending index of   subset to order.
 *
 * Return:   final partition index.
 * Description: Uses   last element of   partition as   pivo.
*/
int hoare_parti(int *array, size_t size, int lefts, int rights)
{
	int pivo, abov, blow;

	pivo = array[rights];
	for (abov = lefts - 1, blow = rights + 1; abov < blow;)
	{
		do {
			abov++;
		} while (array[abov] < pivo);
		do {
			blow--;
		} while (array[blow] > pivo);

		if (abov < blow)
		{
			swap_nbrs(array + abov, array + blow);
			print_array(array, size);
		}
	}

	return (abov);
}

/**
 * hoare_srt - Implement   quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size:  size of  array.
 * @lefts: starting index of   array partition to order.
 * @rights:   ending index of   array partition to order.
 *
 * Description: Uses   Hoare partition scheme.
 */
void hoare_srt(int *array, size_t size, int lefts, int rights)
{
	int part;

	if (rights - lefts > 0)
	{
		part = hoare_parti(array, size, lefts, rights);
		hoare_srt(array, size, lefts, part - 1);
		hoare_srt(array, size, part, rights);
	}
}

/**
 * quick_sort_hoare - Sort array of integers in ascending
 * @array: array of numberss.
 * @size: size of the array.
 *
 * Description: Use Hoare partition scheme. 
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_srt(array, size, 0, size - 1);
}

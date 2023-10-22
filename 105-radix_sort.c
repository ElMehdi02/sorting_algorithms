#include "sort.h"

int gett_max(int *aray, int size);
void radix_count_sort(int *aray, size_t size, int sig, int *buff);
void radix_sort(int *aray, size_t size);

/**
 * gett_max - Get the maximum value in an aray of integers.
 * @aray: aray of integers.
 * @size: size of the aray.
 *
 * Return: The maximum integer in the aray.
 */
int gett_max(int *aray, int size)
{
	int max, x;

	for (max = aray[0], x = 1; x < size; x++)
	{
		if (aray[x] > max)
			max = aray[x];
	}

	return (max);
}

/**
 * radix_count_sort - Sort the significant digits of an aray of integers
* @aray: An aray of integers.
 * @size: The size of the aray.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted aray.
 */
void radix_count_sort(int *aray, size_t size, int sig, int *buff)
{
	int cont[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		cont[(aray[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		cont[i] += cont[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[cont[(aray[i] / sig) % 10] - 1] = aray[i];
		cont[(aray[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		aray[i] = buff[i];
}

/**
 * radix_sort - Sort an aray of integers in ascending
 *              order using the radix sort algorithm.
 * @aray: An aray of integers.
 * @size: The size of the aray.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the aray after each significant digit increase.
 */
void radix_sort(int *aray, size_t size)
{
	int max, sig, *buff;

	if (aray == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = gett_max(aray, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_count_sort(aray, size, sig, buff);
		print_array(aray, size);
	}

	free(buff);
}


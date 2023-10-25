#include "sort.h"

/**
 * knuthSequence - using knuth sequaence to sort
 * @size: the size of the array
 * Return: h.
 */
int knuthSequence(size_t size)
{
	size_t n = 1;

	while (n < size / 3)
	{
		n = 3 * n + 1;
	}
	return (n);
}

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the shell sort algorithm, using the knuth sequence
 * @array: the array
 * @size: the size
 */
void shell_sort(int *array, size_t size)
{
	int gap, temp;
	int j;
	size_t i;

	if (array == NULL || size <= 1)
		return;
	gap = knuthSequence(size);
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}

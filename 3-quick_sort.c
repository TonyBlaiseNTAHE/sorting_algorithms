#include "sort.h"

/**
 * swap - swaps two number in an array
 * @a: array's element
 * @b: array's element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomutoPartition - swaps numbers in partion
 * @array: the array
 * @low: the low boundary
 * @high: the higher boundary
 * @size: the size of the array
 * Return: the index.
 */
int lomutoPartition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}
/**
 * q - sort the array recursively
 * @array: the array
 * @low: the lower boundery
 * @high: the higher boundery
 * @size: the size of the array
 */
void q(int *array, size_t low, size_t high, size_t size)
{
	int loc;

	if (low < high)
	{
		loc = lomutoPartition(array, low, high, size);
		if (loc > 0)
			q(array, low, loc - 1, size);
		q(array, loc + 1, high, size);
	}
}
/**
 * quick_sort - sorts the array
 * @array: the array
 * @size: the size.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	q(array, 0, size - 1, size);
}

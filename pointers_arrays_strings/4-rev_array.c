#include "main.h"

/**
 * reverse_array - reverses an array of integers
 * @a: array to reverse
 * @n: number of elements in the array
 *
 * Return: nothing
 */
void reverse_array(int *a, int n)
{
	int i = 0;
	int temp;

	while (i < n / 2)
	{
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
		i++;
	}
}

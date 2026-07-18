#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sums of both matrix diagonals
 * @a: pointer to the first matrix element
 * @size: width and height of the square matrix
 *
 * Return: nothing
 */
void print_diagsums(int *a, int size)
{
	int i;
	int first;
	int second;

	first = 0;
	second = 0;

	for (i = 0; i < size; i++)
	{
		first += a[(i * size) + i];
		second += a[(i * size) + (size - 1 - i)];
	}

	printf("%d, %d\n", first, second);
}

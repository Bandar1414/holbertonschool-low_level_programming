#include "main.h"

/**
 * print_triangle - prints a right-aligned triangle
 * @size: size of the triangle
 */
void print_triangle(int size)
{
	int row;
	int column;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 1; row <= size; row++)
	{
		for (column = 1; column <= size; column++)
		{
			if (column <= size - row)
				_putchar(' ');
			else
				_putchar('#');
		}

		_putchar('\n');
	}
}

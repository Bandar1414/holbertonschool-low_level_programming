#include "main.h"

/**
 * print_diagonal - draws a diagonal line using backslashes
 * @n: number of backslashes to print
 */
void print_diagonal(int n)
{
	int row;
	int space;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 0; row < n; row++)
	{
		for (space = 0; space < row; space++)
			_putchar(' ');

		_putchar('\\');
		_putchar('\n');
	}
}

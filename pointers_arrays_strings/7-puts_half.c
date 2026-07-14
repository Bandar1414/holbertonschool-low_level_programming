#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: string to print
 */
void puts_half(char *str)
{
	int length;
	int start;

	length = 0;

	while (str[length] != '\0')
		length++;

	start = length / 2;

	if (length % 2 != 0)
		start++;

	while (str[start] != '\0')
	{
		_putchar(str[start]);
		start++;
	}

	_putchar('\n');
}

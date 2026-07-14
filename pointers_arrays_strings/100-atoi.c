#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: converted integer, or 0 if no number is found
 */
int _atoi(char *s)
{
	int sign;
	int number_found;
	unsigned int number;

	sign = 1;
	number_found = 0;
	number = 0;

	while (*s != '\0')
	{
		if (*s == '-')
			sign *= -1;

		if (*s >= '0' && *s <= '9')
		{
			number_found = 1;
			number = number * 10 + (*s - '0');
		}
		else if (number_found)
		{
			break;
		}

		s++;
	}

	return (number * sign);
}

#include "main.h"

/**
 * _strpbrk - searches a string for any accepted byte
 * @s: string to search
 * @accept: bytes to search for
 *
 * Return: pointer to the first matching byte, or 0
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s != '\0')
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
				return (s);
		}

		s++;
	}

	return (0);
}

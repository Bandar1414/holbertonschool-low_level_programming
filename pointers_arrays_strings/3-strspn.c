#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to examine
 * @accept: bytes accepted in the prefix
 *
 * Return: number of accepted bytes at the start of s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count;
	int i;
	int found;

	count = 0;

	while (s[count] != '\0')
	{
		found = 0;

		for (i = 0; accept[i] != '\0'; i++)
		{
			if (s[count] == accept[i])
			{
				found = 1;
				break;
			}
		}

		if (found == 0)
			break;

		count++;
	}

	return (count);
}

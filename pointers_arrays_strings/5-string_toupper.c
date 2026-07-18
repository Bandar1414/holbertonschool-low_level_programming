#include "main.h"

/**
 * string_toupper - changes lowercase letters to uppercase
 * @str: string to change
 *
 * Return: pointer to the changed string
 */
char *string_toupper(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= ('a' - 'A');

		i++;
	}

	return (str);
}

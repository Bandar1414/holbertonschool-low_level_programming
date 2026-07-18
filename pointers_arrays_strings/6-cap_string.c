#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to change
 *
 * Return: pointer to the changed string
 */
char *cap_string(char *str)
{
	int i = 0;
	int j;
	char separators[] = " \t\n,;.!?\"(){}";

	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= ('a' - 'A');

	while (str[i] != '\0')
	{
		j = 0;

		while (separators[j] != '\0')
		{
			if (str[i] == separators[j] &&
			    str[i + 1] >= 'a' && str[i + 1] <= 'z')
				str[i + 1] -= ('a' - 'A');

			j++;
		}

		i++;
	}

	return (str);
}

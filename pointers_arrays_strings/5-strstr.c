#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: string to search
 * @needle: substring to locate
 *
 * Return: pointer to the substring, or 0 if not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *start;
	char *search;
	char *find;

	if (*needle == '\0')
		return (haystack);

	while (*haystack != '\0')
	{
		start = haystack;
		search = haystack;
		find = needle;

		while (*search != '\0' &&
		       *find != '\0' &&
		       *search == *find)
		{
			search++;
			find++;
		}

		if (*find == '\0')
			return (start);

		haystack++;
	}

	return (0);
}

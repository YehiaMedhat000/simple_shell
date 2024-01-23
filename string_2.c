#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @src: The source string
 * @dest: The destination string
 * Return: The new concatenated string
 */

/* Still not working: Return Error */
char *_strcat(char *dest, const char *src)
{
	int i = 0;
	int dlen = _strlen(dest);

	for (i = 0; src[i]; i++)
	{
		dest[dlen + i] = src[i];
	}
	return (dest);
}

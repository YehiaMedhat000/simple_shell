#include "main.h"

/**
 * _strcpy - Copies a string
 * @destination: the destination buffer
 * @source: the source string
 * Return: pointer to the destination buffer
 */
char *_strcpy(char *destination, char *source)
{
	int i = 0;

	if (destination == source || source == NULL)
		return (destination);
	while (source[i])
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return (destination);
}

/**
 * _strncpy - Copies a substring
 * @destination: The string to copy
 * @source: The source string
 * @lim: The amount of characters to be copied
 * Return: The substring copied
 */

char *_strncpy(char *destination, char *source, int lim)
{
	int k, l;
	char *str = destination;

	k = 0;
	while (source[k] != '\0' && k < lim - 1)
	{
		destination[k] = source[k];
		k++;
	}
	if (k < lim)
	{
		l = k;
		while (l < lim)
		{
			destination[l] = '\0';
			l++;
		}
	}
	return (str);
}

/**
 * _strdup - Duplicates a string
 * @string: The string to duplicate
 * Return: The duplicate string
 */

char *_strdup(const char *string)
{
	int len = 0;
	char *dup;

	if (string == NULL)
		return (NULL);
	while (*string++)
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	for (len++; len--;)
		dup[len] = *--string;
	return (dup);
}

/**
 * _puts - prints an input string
 * @string: the string print
 * Return: Nothing (void)
 */

void _puts(char *string)
{
	int j = 0;

	if (!string)
		return;
	while (string[j] != '\0')
	{
		_putchar(string[j]);
		j++;
	}
}

/**
 * _putchar - writes chr to stdout
 * @chr: The character to print
 * Return: (1) success or (-1)
 * And errno is set appropriately.
 */

int _putchar(char chr)
{
	static int j;
	static char buffer[WRBUF];

	if (chr == BUFLUSH || j >= WRBUF)
	{
		write(1, buffer, j);
		j = 0;
	}
	if (chr != BUFLUSH)
		buffer[j++] = chr;
	return (1);
}

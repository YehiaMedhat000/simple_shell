#include "main.h"

/**
 * _strlen - strlen custom function
 * @str: The char in use
 * Return: Length of str
 */

size_t _strlen(char *str)
{
	size_t len = 0;

	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: The difference of the
 * numerical value of *s1 - *s2
 */

int _strcmp(const char *s1, const char *s2)
{
	unsigned char c1, c2;

	do
	{
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
		if (c1 == '\0')
		return c1 - c2;
	}
	while (c1 == c2);
	return c1 - c2;
}

/**
 * _strncmp - Compares some chars from
 * each string
 * @s1: First string
 * @s2: Second string
 * Return: Difference of *s1 - *s2
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	register unsigned char u1, u2;

	while (n-- > 0)
	{
		u1 = (unsigned char) *s1++;
		u2 = (unsigned char) *s2++;
		if (u1 != u2)
			return (u1 - u2);
		if (u1 == '\0')
			return (0);
	}
	return (0);
}


/**
 * _strtok - Tokenizes strings according
 * to the values in delim
 * @str: String to tokenize
 * @delim: The delimiters to use
 * Return: Char pointer to the next
 * value that's not null and not in
 * delim
 */

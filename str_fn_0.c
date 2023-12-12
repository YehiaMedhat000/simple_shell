#include "main.h"

/**
 * _strlen - Gets string length
 * @str: The string
 * Return: Size of str in chars
 */

int _strlen(char *str)
{
	int len = 0;

	if (!str || !*str)
		return (0);
	while (*str++)
		len++;
	return (len);
}

/**
 * _strcmp - Compares two strings
 * and check which is larger
 * or if they equal
 * @str1: First string in comparison
 * @str2: Second string in comparison
 * Return: (0) if they are equal
 * difference between first different
 * char between them, it could be
 * negative of positive
 */

int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * _strncmp - Compares number of chars
 * from two strings
 * @s1: First string
 * @s2: Second string
 * @n: Number of chars to compare
 * Return: Positive value if s1 > s2
 * Negative if s1 < s2
 * 0 if they are identical
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2 || !n)
		exit(1);
	while (n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/**
 * _strchr - Checks the first occurrance
 * of char c in string s
 * @s: The string to search in
 * @c: The char to search in s
 * Return: Pointer to the first
 * occurrance of c in s
 * NULL in case of failure
 */

char *_strchr(char *s, int c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++);
	return (NULL);
}

/**
 * _puts - Custom implementation of
 * the puts() function
 * @buff: The buffer to put
 * Return: Nothing (void)
 */

void _puts(char *buff)
{
	int j = 0;

	if (!buff)
		return;
	while (buff[j])
	{
		_putchar(buff[j]);
		j++;
	}
}

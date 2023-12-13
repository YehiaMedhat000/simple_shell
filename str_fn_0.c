#include "main.h"

/**
 * _strlen - Gets string length
 * @str: The string
 * Return: Size of str in chars
 */

size_t _strlen(char *str)
{
	size_t len = 0;

	if (!str || !*str)
		return (0);
	while (*str++)
		len++;
	return (len);
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

char *_strchr(const char *s, int c)
{
	int idx = 0;

	while (*(s + idx))
	{
		if (*(s + idx) == c)
			return ((char *)(s + idx));
		idx++;
	}
	return ("");
}

/**
 * _strspn - Calculates the number of
 * chars in str which exist in grp
 * from the beginning
 * @s: The string to search
 * @accept: The group characters to search
 * Return: Number of chars that are in
 * both grp and str from the beginning
 */

size_t _strspn(const char *s, const char *accept)
{
	size_t len = 0;
	int count_in = 0, count_acc;

	if (!s || !accept)
		return (0);
	if (!*s || !*accept)
		return (0);

	while (*s)
	{
		count_acc = 0;
		count_in = 0;
		while (accept[count_acc])
		{
			if (*s == accept[count_acc])
			{
				s++;
				count_in++;
				count_acc++;
			}
			else
				count_acc++;
		}
		len += count_in;
		if (count_in == 0)
			break;
	}
	return (len);
}

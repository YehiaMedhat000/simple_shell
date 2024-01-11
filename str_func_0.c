#include "main.h"

/**
 * _strlen - Gets a string length
 * @str: The string to get its length
 * Return: The length of the string
 */

int _strlen(char *str)
{
	int len = 0;

	if (!str)
		return (0);

	while (*str++)
		len++;
	return (len);
}

/**
 * _strcmp - performs comparison of two
 * strings.
 * @str1: the first string
 * @str2: the second string
 * Return: -1 if str1 < str2
 * or 0 if str1 == str2
 * or 1 if str1 > str2
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
	/* One string is null-terminated while the other is not. */
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * find_substring - checks if substring
 * starts with string
 * @string: string to search
 * @substring: the substring to find
 * Return: pointer to substring
 * or NULL if not found
 */

char *find_substring(const char *string, const char *substring)
{
	while (*substring)
		if (*substring++ != *string++)
			return (NULL);
	return ((char *)string);
}

/**
 * _strcat - concatenates two strings
 * @destination: the destination buffer
 * @source: the source buffer
 * Return: pointer to destination
 */

char *_strcat(char *destination, char *source)
{
	char *result = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (result);
}

/**
 * _strncat - concatenates two strings
 * with a limit
 * @first_string: the first string
 * @second_string: the second string
 * @lim: the maximum number of bytes
 * Return: the concatenated string
 */
char *_strncat(char *first_string, char *second_string, int lim)
{
	int i, j;
	char *result = first_string;

	i = 0;
	j = 0;
	while (first_string[i] != '\0')
		i++;
	while (second_string[j] != '\0' && j < lim)
	{
		first_string[i] = second_string[j];
		i++;
		j++;
	}
	if (j < lim)
		first_string[i] = '\0';
	return (result);
}

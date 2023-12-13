#include "main.h"

/**
 * begins_with - Checks if str begins
 * with the string check
 * @str: String to check
 * @check: The set of characters to
 * check if they exist in str
 * Return: Pointer to next char check
 * if it exists in str, NULL otherwise
 */

char *begins_with(const char *str, const char *check)
{
	while (*check)
	{
		if (*check++ != *str++)
			return (NULL);
	}
	return ((char *)str);
}

/**
 * _strcpy - Copies str1 to str2
 * @str1: The destination string
 * @str2: The source string
 * Return: str1
 */

char *_strcpy(char *str1, char *str2)
{
	int j = 0;

	if (str1 == str2 || str2 == 0)
		return (str1);
	while (str2[j])
	{
		str1[j] = str2[j];
		j++;
	}
	str2[j] = 0;
	return (str1);
}

/**
 * _strdup - Duplicates a string for
 * assignment purposes from const char
 * @ptr: Char pointer to the string to
 * duplicate
 * Return: ptr, (NULL) in failure
 */

char *_strdup(const char *ptr)
{
	int len = 0;
	char *buff;

	if (ptr == NULL)
		return (NULL);
	while (*ptr++)
		len++;
	buff = malloc(sizeof(char) * len);
	if (!buff)
		return (NULL);
	for (len++; len--;)
		buff[len] = *--ptr;
	return (buff);
}

/**
 * _strncpy - Copies given number of
 * bytes from one string to another
 * @str1: Destination string
 * @str2: Source string
 * @n: Number of bytes to copy
 * Return: The output string
 */

char *_strncpy(char *str1, char *str2, int n)
{
	int j = 0, k;
	char *ptr = str1;

	while (str2[j] && j < n - 1)
	{
		str1[j] = str2[j];
		j++;
	}
	if (j < n)
	{
		k = j;
		while (k < n)
		{
			str1[k] = 0;
			k++;
		}
	}
	return (ptr);
}

/**
 * _strcat - Custom implementation of
 * the strcat function
 * @destination: The string to output
 * @source: The source string
 * Return: Pointer to destination
 */

char *_strcat(char *destination, char *source)
{
	char *ptr = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (ptr);
}

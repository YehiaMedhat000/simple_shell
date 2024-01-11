#include "main.h"

/**
 * _strchr - Finds a character's
 * position in a string
 * @str: The string used
 * @chr: The character to search in str
 * Return: Pointer to the first
 * occurrance of chr in str
 * NULL, if not found
 */

char *_strchr(char *str, char chr)
{
	do {
		if (*str == chr)
			return (str);
	} while (*str++);

	return (NULL);
}

/**
 * _strtow - Splits string according to
 * delim string
 * @string: The string to split
 * @delim: The delimiters used to split
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **_strtow(char *string, char *delim)
{
	int ith, jth, kth, mth, nwrds = 0;
	char **str;

	if (string == NULL || string[0] == 0)
		return (NULL);
	if (!delim)
		delim = " ";
	for (ith = 0; string[ith] != '\0'; ith++)
		if (!qdelim(string[ith], delim) && (qdelim(string[ith + 1], delim) || !string[ith + 1]))
			nwrds++;

	if (nwrds == 0)
		return (NULL);
	str = malloc((1 + nwrds) * sizeof(char *));
	if (!str)
		return (NULL);
	for (ith = 0, jth = 0; jth < nwrds; jth++)
	{
		while (qdelim(string[ith], delim))
			ith++;
		kth = 0;
		while (!qdelim(string[ith + kth], delim) && string[ith + kth])
			kth++;
		str[jth] = malloc((kth + 1) * sizeof(char));
		if (!str[jth])
		{
			for (kth = 0; kth < jth; kth++)
				free(str[kth]);
			free(str);
			return (NULL);
		}
		for (mth = 0; mth < kth; mth++)
			str[jth][mth] = string[ith++];
		str[jth][mth] = 0;
	}
	str[jth] = NULL;
	return (str);
}

/**
 * _strtow2 - Tokenize strings
 * according to a string delim
 * @string: The string to split
 * @delim: The delimiters string
 * Return: Char double pointer
 */

char **_strtow2(char *string, char delim)
{
	int z, i, ls, n, nwrds = 0;
	char **ptr;

	if (string == NULL || string[0] == 0)
		return (NULL);
	for (z = 0; string[z] != '\0'; z++)
		if ((string[z] != delim && string[z + 1] == delim) ||
		    (string[z] != delim && !string[z + 1]) || string[z + 1] == delim)
			nwrds++;
	if (nwrds == 0)
		return (NULL);
	ptr = malloc((1 + nwrds) * sizeof(char *));
	if (!ptr)
		return (NULL);
	for (z = 0, i = 0; i < nwrds; i++)
	{
		while (string[z] == delim && string[z] != delim)
			z++;
		ls = 0;
		while (string[z + ls] != delim && string[z + ls] && string[z + ls] != delim)
			ls++;
		ptr[i] = malloc((ls + 1) * sizeof(char));
		if (!ptr[i])
		{
			for (ls = 0; ls < i; ls++)
				free(ptr[ls]);
			free(ptr);
			return (NULL);
		}
		for (n = 0; n < ls; n++)
			ptr[i][n] = string[z++];
		ptr[i][n] = 0;
	}
	ptr[i] = NULL;
	return (ptr);
}

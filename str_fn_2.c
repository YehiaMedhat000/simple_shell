#include "main.h"

/**
 * _putchar - Custom implementation of
 * the putchar function
 * @chr: The character to print
 * Return: (1) success, (-1) on failure
 * and errno is set properly
 */

int _putchar(char chr)
{
	static int j;
	static char buffer[W_BUF_S];

	if (chr == BUF_FLUSH || j >= W_BUF_S)
	{
		write(1, buffer, j);
		j = 0;
	}
	if (chr != BUF_FLUSH)
		buffer[j++] = chr;
	return (1);
}

/**
 * _strncat - Custom implementation of
 * the strncat function
 * @destination: The destination string
 * @source: The source string
 * @len: Length of the concatenated
 * part
 * Return: The output string
 */

char *_strncat(char *destination, char *source, int len)
{
	int m = 0, n = 0;
	char *str = destination;

	while (destination[m])
		m++;
	while (source[n] && n < len)
	{
		destination[m] = source[n];
		m++;
		n++;
	}
	if (n < len)
		destination[m] = 0;
	return (str);
}

/**
 * _strtow - Works like strtok()
 * @s: The string to split
 * @delim: The string with the delimiters
 * Return: Pointer to the splitted
 * tokens, (NULL) in failure
 */

char **_strtow(char *s, char *delim)
{
	int n, m, k, j, nwrd = 0;
	char **ptr;

	if (!s || !*s)
		return (NULL);
	if (!delim)
		delim = " ";
	for (n = 0; s[n]; n++)
		if (!qdelim(s[n], delim) && (qdelim(s[n + 1], delim) || !s[n + 1]))
			nwrd++;
	if (nwrd == 0)
		return (NULL);
	ptr = malloc(sizeof(char *) * (1 + nwrd));
	if (!ptr)
		return (NULL);
	for (n = 0, m = 0; m < nwrd; m++)
	{
		while (qdelim(s[n], delim))
			n++;
		k = 0;
		while (!qdelim(s[n + k], delim) && s[n + k])
			k++;
		ptr[m] = malloc((k + 1) * sizeof(char));
		if (!ptr[m])
		{
			for (k = 0; k < m; k++)
				free(ptr[k]);
			free(ptr);
			return (NULL);
		}
		for (j = 0; j < k; j++)
			ptr[m][j] = s[n++];
		ptr[m][j] = 0;
	}
	ptr[m] = NULL;
	return (ptr);
}

/**
 * _strtowchr - Custom implementation
 * of an strtok_r like function
 * @s: String to split
 * @delim: String of delimiters
 * Return: A pointer to the output
 * NULL if it fails
 */

char **_strtowchr(char *s, char delim)
{
	int n, m, k = 0, j, nwrd = 0;
	char **str;

	if (!s || !*s)
		return (NULL);
	for (n = 0; s[n]; n++)
		if ((s[n] != delim && s[n + 1] == delim)
		|| (s[n] != delim && !s[n + 1]) || s[n + 1] == 0)
		nwrd++;
	if (nwrd == 0)
		return (NULL);
	str = malloc((1 + nwrd) * sizeof(char *));
	if (!str)
		return (NULL);
	for (n = 0, m = 0; m < nwrd; m++)
	{
		while (s[n] == delim && s[n] != delim)
			j++;
		while (s[n + k] != delim && s[n + k] && s[n + k] != delim)
			k++;
		str[m] = malloc((k + 1) * sizeof(char));
		if (!str[m])
		{
			for (k = 0; k < m; k++)
				free(str[k]);
			free(str);
			return (NULL);
		}
		for (j = 0; j < k; j++)
			str[m][j] = s[n++];
		str[m][j] = 0;
	}
	str[m] = NULL;
	return (str);
}

#include "main.h"

/**
 * _strcspn - Calculates the length of
 * a string prefix which doesn't have
 * any char in the reject chars
 * @s: The string being searched
 * @reject: The bytes to search in s
 * Return: Length of prefix which
 * doesn't have bytes in reject
 */

size_t _strcspn(const char *s, const char *reject)
{
	size_t len_prefix = 0;
	int count_in = 0, count_acc;
	int len_reject = _strlen(reject);

	if (!s || !reject || !*s)
		return (0);
	if (!*reject)
		return (_strlen(s));

	while (*s)
	{
		count_acc = 0;
		count_in = 0;
		while (reject[count_acc])
		{
			if (*s == reject[count_acc])
			{
				s++;
				count_acc++;
			}
			else
			{
				count_in++;
				count_acc++;
			}
		}
		if (count_in != len_reject)
			break;

		len_prefix++;
		s++;
		continue;
	}
	return (len_prefix);
}

/**
 * _strtok_r -
 * @str: The string to tokenize
 * @delim: String of the delimiters
 * @saveptr: Pointer to the next token
 * for the next execution
 * Return: Pointer to the next token
 * NULL if there are no more tokens
 */

char *_strtok_r(char *str, const char *delim, char **saveptr)
{
	char *tok_end;

	if (str == NULL)
		str = *saveptr;
	if (!*str)
	{
		*saveptr = str;
		return (NULL);
	}

	str += _strspn(str, delim);
	if (!*str)
	{
		*saveptr = str;
		return (NULL);
	}
	tok_end = str + _strcspn(str, delim);
	if (!*tok_end)
	{
		*saveptr = tok_end;
		return (str);
	}
	*tok_end = 0;
	*saveptr = tok_end + 1;
	return (str);
}

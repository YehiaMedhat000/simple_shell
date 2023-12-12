#include "main.h"

/**
 * interact - Checks if bash is
 * in interactive mode
 * @data: Info struct
 * Return: (1) if interactive mode on
 * (0) otherwise
 */

int interact(info *data)
{
	return (isatty(STDIN_FILENO) && data->rdfd <= 2);
}

/**
 * qdelim - Checks for delimiters
 * @chr: Character to check
 * @d: Delimiter string
 * Return: (1) if chr is in d
 * (0) otherwise
 */

int qdelim(char chr, char *d)
{
	while (*d)
	{
		if (*d++ == chr)
			return (1);
	}
	return (0);
}

/**
 * qalpha - Checks for alphabet chars
 * @chr: Character to check
 * Return: (1) if chr is alphabetical
 * byte, (0) otherwise
 */

int qalpha(int chr)
{
	if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'))
		return (1);
	return (0);
}

/**
 * _atoi - Converts integers in strings
 * to number data types
 * @str: String to converted
 * Return: (0) if no numbers found
 * converted number if conversion
 * occurred successfully
 */

int _atoi(char *str)
{
	int j, sign = 1, check = 0, out;
	unsigned int res = 0;

	for (j = 0; str[j] != '\0' && check != 2; j++)
	{
		if (str[j] == '-')
			sign *= -1;
		if (str[j] >= '0' && str[j] <= '9')
		{
			check = 1;
			res *= 10;
			res += (str[j] - '0');
		}
		else if (check == 1)
			check = 2;
	}
	if (sign == -1)
		out = -res;
	else
		out = res;

	return (out);
}

#include "main.h"

/**
 * interact - Checks for interactive mode
 * @data: Info struct
 * Return: Int type
 */

int interact(inf *data)
{
	return (isatty(STDIN_FILENO) && data->rdfd <= 2);
}

/**
 * qdelim - Checks if chr is delimeter
 * @chr: Char type
 * @dlm: Char pointer
 * Return: Int type
 */

int qdelim(char chr, char *dlm)
{
	while (*dlm)
		if (*dlm++ == chr)
			return (1);
	return (0);
}

/**
 * qlapha - Checks if chr is letter
 * @chr: Char type
 * Return: Int type
 */

int qlapha(int chr)
{
	if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Converts char * to int
 * @str: Char pointer
 * Return: Int type
 */

int _atoi(char *str)
{
	int j, sgn = 1, fg = 0, out;
	unsigned int res = 0;

	for (j = 0;  str[j] != '\0' && fg != 2; j++)
	{
		if (str[j] == '-')
			sgn *= -1;

		if (str[j] >= '0' && str[j] <= '9')
		{
			fg = 1;
			res *= 10;
			res += (str[j] - '0');
		}
		else if (fg == 1)
			fg = 2;
	}

	if (sgn == -1)
		out = -res;
	else
		out = res;

	return (out);
}

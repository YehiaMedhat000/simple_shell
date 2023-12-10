#include "main.h"

/**
 * _etoi - Converts number in string
 * to a number data type
 * @str: The string to convert
 * Return: (0) if no numbers are found
 * The converted number if conversion
 * successfully occurred
 * (-1) in error
 */

int _etoi(char *str)
{
	int j;
	unsigned long int res = 0;

	if (*str == '+')
		str++;
	for (j = 0; str[j] != '\0'; j++)
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			res *= 10;
			res += (str[j] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * prt_err - Prints error messages
 * @data: Info struct
 * @err_str: Error message
 * Return: Nothing (void)
 */

void prt_err(info *data, char *err_str)
{
	eprt(data->file);
	eprt(": ");
	prt_d(data->lcount, STDERR_FILENO);
	eprt(": ");
	eprt(data->av[0]);
	eprt(": ");
	eprt(err_str);
}

/**
 * prt_d - Prints base 10 numbers
 * @num: Number to print
 * @fd: File descriptor to write to
 * Return: Number of printed bytes
 */

int prt_d(int num, int fd)
{
	int (*__pchr)(char) = _putchar;
	int j, n = 0;
	unsigned int absolute, p;

	if (fd == STDERR_FILENO)
		__pchr = eprtchr;
	if (num < 0)
	{
		absolute = -num;
		__pchr('-');
		n++;
	}
	else
		absolute = -num;
	p = absolute;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (absolute / j)
		{
			__pchr('0' + p / j);
			n++;
		}
		p %= j;
	}
	__pchr('0' + p);
	n++;
	return (n);
}

/**
 * conv_d - Converts a number to string
 * @number: Number to convert
 * @base: Base of the converted number
 * @checks: Arguments passed
 * Return: String with the number
 */

char *conv_d(long int number, int base, int checks)
{
	static char *arr;
	static char *buff[50];
	char sign = 0;
	char *str;
	unsigned long n = number;

	if (!(checks & CONV_UNSGND) && number < 0)
	{
		n = -number;
		sign = '-';
	}
	arr = checks & CONV_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
	str = &buff[49];
	*str = '\0';

	do {
		*--str = arr[number % base];
		n /= base;
	} while (number != 0);
	if (sign)
		*--str = sign;
	return (str);
}

/**
 * rm_comnt - Removes comments from
 * scripts
 * @buffer: The string to modify
 * Return: (0) Always
 */

void rm_comnt(char *buffer)
{
	int j;

	for (j = 0; buffer[j] != 0; j++)
	{
		if (buffer[j] == '#' && (!j || buffer[j - 1] == ' '))
		{
			buffer[j] = 0;
			break;
		}
	}
}

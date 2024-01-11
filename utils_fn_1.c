#include "main.h"

/**
 * _etoi - Converts char * to int
 * @str: Char pointer
 * Return: Int type
 */

int _etoi(char *str)
{
	int j = 0;
	unsigned long int rslt = 0;

	if (*str == '+')
		str++;
	for (j = 0;  str[j] != '\0'; j++)
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			rslt *= 10;
			rslt += (str[j] - '0');
			if (rslt > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rslt);
}

/**
 * prterr - Printing function
 * @data: Info struct
 * @err: Char pointer
 * Return: Nothing (void)
 */

void prterr(inf *data, char *err)
{
	eprt(data->file);
	eprt(": ");
	prtd(data->lc, STDERR_FILENO);
	eprt(": ");
	eprt(data->av[0]);
	eprt(": ");
	eprt(err);
}

/**
 * prtd - Printing numbers
 * @num: Int type
 * @fdes: File describtor
 * Return: Int type
 */

int prtd(int num, int fdes)
{
	int (*prtc)(char) = _putchar;
	int j, cnt = 0;
	unsigned int abslt, crnt;

	if (fdes == STDERR_FILENO)
		prtc = eprtchr;
	if (num < 0)
	{
		abslt = -num;
		prtc('-');
		cnt++;
	}
	else
		abslt = num;
	crnt = abslt;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (abslt / j)
		{
			prtc('0' + crnt / j);
			cnt++;
		}
		crnt %= j;
	}
	prtc('0' + crnt);
	cnt++;

	return (cnt);
}

/**
 * convnum - Converts int to char *
 * @number: Long int type
 * @bs: Int type
 * @fgs: Int type
 * Return: Char pointer
 */

char *convnum(long int number, int bs, int fgs)
{
	static char *ary;
	static char buf[50];
	char sgn = 0;
	char *pntr;
	unsigned long sze = number;

	if (!(fgs & CONVUNSID) && number < 0)
	{
		sze = -number;
		sgn = '-';

	}
	ary = fgs & CONVLWR ? "0123456789abcdef" : "0123456789ABCDEF";
	pntr = &buf[49];
	*pntr = '\0';

	do	{
		*--pntr = ary[sze % bs];
		sze /= bs;
	} while (sze != 0);

	if (sgn)
		*--pntr = sgn;
	return (pntr);
}

/**
 * rmcmnt - Removes comments
 * @buffer: Char pointer
 * Return: Nothing (void)
 */

void rmcmnt(char *buffer)
{
	int j;

	for (j = 0; buffer[j] != '\0'; j++)
		if (buffer[j] == '#' && (!j || buffer[j - 1] == ' '))
		{
			buffer[j] = '\0';
			break;
		}
}

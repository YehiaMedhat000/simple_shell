#include "main.h"

/**
 * eprt - prints an input string
 * @string: Char pointer
 * Return: Nothing (void)
 */

void eprt(char *string)
{
	int j = 0;

	if (!string)
		return;
	while (string[j] != '\0')
	{
		eprtchr(string[j]);
		j++;
	}
}

/**
 * eprtchr - Error printing function
 * @chr: Char type
 * Return: Int type
 */

int eprtchr(char chr)
{
	static int j;
	static char buffer[WRBUF];

	if (chr == BUFLUSH || j >= WRBUF)
	{
		write(2, buffer, j);
		j = 0;
	}
	if (chr != BUFLUSH)
		buffer[j++] = chr;
	return (1);
}

/**
 * prtfd - Bytewise printing function
 * @chr: Char type
 * @fdes: File descriptor
 * Return: Int type
 */

int prtfd(char chr, int fdes)
{
	static int j;
	static char buffer[WRBUF];

	if (chr == BUFLUSH || j >= WRBUF)
	{
		write(fdes, buffer, j);
		j = 0;
	}
	if (chr != BUFLUSH)
		buffer[j++] = chr;
	return (1);
}

/**
 * prtchrfd	- Printing function
 * @string: Char pointer
 * @fdes: File descriptor
 * Return: Int type
 */

int prtchrfd(char *string, int fdes)
{
	int j = 0;

	if (!string)
		return (0);
	while (*string)
	{
		j += prtfd(*string++, fdes);
	}
	return (j);
}

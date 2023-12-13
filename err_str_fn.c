#include "main.h"

/**
 * eprt - Very normal printing function
 * @s: The value to print
 * Return: Nothing (void)
 */

void eprt(char *s)
{
	int j = 0;

	if (!s)
		return;
	while (s[j])
	{
		eprtchr(s[j]);
		j++;
	}
}

/**
 * eprtchr - Prints a char per time
 * like putchar()
 * @chr: The value to print
 * Return: (1) success, (-1) on error
 * and errno is set properly
 */

int eprtchr(char chr)
{
	static int j;
	static char buffer[W_BUF_S];

	if (chr == BUF_FLUSH || j >= W_BUF_S)
	{
		write(2, buffer, j);
		j = 0;
	}
	if (chr != BUF_FLUSH)
		buffer[j++] = chr;
	return (1);
}

/**
 * prtfd - Printing function
 * @chr: The value to print
 * @fdcr: File descriptor to which
 * chr is written
 * Return: (1) success, (-1) and errno
 * is set properly
 */

int prtfd(char chr, int fdcr)
{
	static int j;
	static char buffer[W_BUF_S];

	if (chr == BUF_FLUSH || j >= W_BUF_S)
	{
		write(fdcr, buffer, j);
		j = 0;
	}
	if (chr != BUF_FLUSH)
		buffer[j++] = chr;
	return (1);
}

/**
 * prtchr_fd - Printing function
 * @s: The value printed
 * @fdcr: File descirptor
 * Return: Number of printed chars
 */

int prtchr_fd(char *s, int fdcr)
{
	int j = 0;

	if (!s)
		return (0);
	while (*s)
		j += prtfd(*s++, fdcr);
	return (j);
}

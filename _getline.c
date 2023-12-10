#include "main.h"


/**
 * buffin - Puts chained commands in
 * a buffer
 * @data: Info struct
 * @buffer: Buffer to use
 * @size: Size of buffer
 * Return: Number of bytes read
 */

ssize_t buffin(info *data, char **buffer, size_t *size)
{
	ssize_t j = 0;
	size_t l = 0;

	if (!*size)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sgnthndlr);
#if _GETLINE
		j = getline(buffer, &l, stdin);
#else
		j = _getline(data, buffer, &l);
#endif
		if (j > 0)
		{
			if ((*buffer)[j - 1] == '\n')
			{
				(*buffer)[j - 1] = 0;
				j--;
			}
			data->lcount_flag = 1;
			rm_comnt(*buffer);
			bld_hst_lst(data, *buffer, data->histc);
			*size = j;
			data->bash_buf = buffer;
		}
	}
	return (j);
}

/**
 * get_in - Gets a line without \n
 * @data: Info struct
 * Return: Number of bytes read
 */

ssize_t get_in(info *data)
{
	static char *buffer;
	static size_t k, n, l;
	ssize_t ch = 0;
	char **inbuff = &(data->args), *str;

	_putchar(BUF_FLUSH);
	ch = buffin(data, &buffer, &l);
	if (ch == -1)
		return (-1);
	if (l)
	{
		n = k;
		str = buffer + k;
		chk_chn(data, buffer, &n, k, l);
		while (n < l)
		{
			if (qchn(data, buffer, &n))
				break;
			n++;
		}

		k = n + 1;
		if (k >= l)
		{
			k = l = 0;
			data->bash_buf_t = BASH_NORM;
		}
		*inbuff = str;
		return (_strlen(str));
	}
	*inbuff = buffer;
	return (ch);
}

/**
 * rd_buf - Reads some buffer
 * @data: Info struct
 * @buffer: The buffer to read
 * @s: The buffer size
 * Return: Number of bytes read
 * successfully
 */

ssize_t rd_buf(info *data, char *buffer, size_t *s)
{
	ssize_t rd = 0;

	if (*s)
		return (0);
	rd = read(data->rdfd, buffer, R_BUF_S);
	if (r >= 0)
		*s = rd;
	return (r);
}

/**
 * _getline - Custom implementation of
 * getline() function
 * @data: Info struct
 * @buffer: Buffer to use
 * @len: Length of buffer
 * Return: Number of read bytes
 */

int _getline(info *data, char **buffer, size_t len)
{
	static char buffcpy[R_BUF_S];
	static size_t j, l;
	size_t i;
	ssize_t ch = 0, sh = 0;
	char *str = NULL, *nstr = NULL, *clh;

	str = *buffer;
	if (str && len)
		sh = *len;
	if (j == l)
		j = l = 0;

	ch = rd_buf(data, buffcpy, &l);
	if (ch == -1 || (ch == 0 && l == 0))
		return (-1);
	clh = _strchr(buffcpy + j, '\n');
	i = clh ? 1 + (unsigned int)(clh - buffcpy) : l;
	nstr = _realloc(str, sh, sh ? sh + i : i + 1);
	if (!nstr)
		return (str ? free(str), -1 : -1);
	if (sh)
		_strncat(nstr, buffcpy + j, i - j);
	else
		_strncpy(nstr, buffcpy + j, i - j + 1);

	sh += i - j;
	j = i;
	str = nstr;
	if (len)
		*len = sh;
	*buffer = str;
	return (sh);
}
sgnthndlr()
/**
 * sgnthndlr - Handles <C-c>
 * @signumber: The number of the signal
 * Return: Nothing (void)
 */

void sgnthndlr(__attribute__((unused))int signumber)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

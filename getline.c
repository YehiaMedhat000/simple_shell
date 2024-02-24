#include "main.h"

/**
 * buffin - Gets input command
 * @data: Info struct
 * @buffer: Char double pointer
 * @length: size_t type
 * Return: ssize_t type
 */

ssize_t buffin(inf *data, char **buffer, size_t *length)
{
	ssize_t ret = 0;
	size_t lep = 0;

	if (!*length)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sgntndl);
#if _GETLINE
		ret = getline(buffer, &lep, stdin);
#else
		ret = _getline(data, buffer, &lep);
#endif
		if (ret > 0)
		{
			if ((*buffer)[ret - 1] == '\n')
			{
				(*buffer)[ret - 1] = '\0';
				ret--;
			}
			data->lcf = 1;
			rmcmnt(*buffer);
			bldhstlst(data, *buffer, data->hstc++);
			{
				*length = ret;
				data->buf = buffer;
			}
		}
	}
	return (ret);
}

/**
 * getin - Function that takes input
 * @data: Info struct
 * Return: ssize_t type
 */

ssize_t getin(inf *data)
{
	static char *buffer;
	static size_t h, i, length;
	ssize_t ret = 0;
	char **bpuf = &(data->agm), *pntr;

	_putchar(BUFLUSH);
	ret = buffin(data, &buffer, &length);
	if (ret == -1)
		return (-1);
	if (length)
	{
		i = h;
		pntr = buffer + h;

		chkchn(data, buffer, &i, h, length);
		while (i < length)
		{
			if (qchain(data, buffer, &i))
				break;
			i++;
		}

		h = i + 1;
		if (h >= length)
		{
			h = length = 0;
			data->buf = SHNORM;
		}

		*bpuf = pntr;
		return (_strlen(pntr));
	}

	*bpuf = buffer;
	return (ret);
}

/**
 * rdbuff - Reading function
 * @data: Info struct
 * @buffer: Char pointer
 * @siz: size_t type
 * Return: ssize_t type
 */

ssize_t rdbuff(inf *data, char *buffer, size_t *siz)
{
	ssize_t ret = 0;

	if (*siz)
		return (0);
	ret = read(data->rdfd, buffer, RDBUF);
	if (ret >= 0)
		*siz = ret;
	return (ret);
}

/**
 * _getline - Gets line from stdin
 * @data: Info struct
 * @pntrarg: Char double pointer
 * @alen: size_t pointer
 * Return: Int type
 */

int _getline(inf *data, char **pntrarg, size_t *alen)
{
	static char buffer[RDBUF];
	static size_t ith, lenv;
	size_t kth;
	ssize_t ret = 0, siz = 0;
	char *ptr = NULL, *new_ptr = NULL, *c;

	ptr = *pntrarg;
	if (ptr && alen)
		siz = *alen;
	if (ith == lenv)
		ith = lenv = 0;

	ret = rdbuff(data, buffer, &lenv);
	if (ret == -1 || (ret == 0 && lenv == 0))
		return (-1);

	c = _strchr(buffer + ith, '\n');
	kth = c ? 1 + (unsigned int)(c - buffer) : lenv;
	new_ptr = _realloc(ptr, siz, siz ? siz + kth : kth + 1);
	if (!new_ptr) /* MALLOC FAILURE! */
		return (ptr ? free(ptr), -1 : -1);

	if (siz)
		_strncat(new_ptr, buffer + ith, kth - ith);
	else
		_strncpy(new_ptr, buffer + ith, kth - ith + 1);

	siz += kth - ith;
	ith = kth;
	ptr = new_ptr;

	if (alen)
		*alen = siz;
	*pntrarg = ptr;
	return (siz);
}

/**
 * sgntndl - Handling signals function
 * @sgnm: Int type
 * Return: Nothing (void)
 */

void sgntndl(__attribute__((unused))int sgnm)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFLUSH);
}

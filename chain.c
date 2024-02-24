#include "main.h"

/**
 * qchain - Auxiliary function
 * @data: Info struct
 * @buffer: Char pointer
 * @siz: size_t type
 * Return: Int type
 */

int qchain(inf *data, char *buffer, size_t *siz)
{
	size_t sn = *siz;

	if (buffer[sn] == '|' && buffer[sn + 1] == '|')
	{
		buffer[sn] = 0;
		sn++;
		data->buf_type = SHOR;
	}
	else if (buffer[sn] == '&' && buffer[sn + 1] == '&')
	{
		buffer[sn] = 0;
		sn++;
		data->buf_type = SHAND;
	}
	else if (buffer[sn] == ';')
	{
		buffer[sn] = 0;
		data->buf_type = SHCHAIN;
	}
	else
		return (0);
	*siz = sn;
	return (1);
}

/**
 * chkchn - Checks validity of chaining
 * @data: Info struct
 * @buffer: Char pointer
 * @sizpntr: size_t pointer
 * @siz: size_t type
 * @length: size_t type
 * Return: Nothing (void)
 */

void chkchn(inf *data, char *buffer, size_t *sizpntr, size_t siz, size_t length)
{
	size_t sn = *sizpntr;

	if (data->buf_type == SHAND)
	{
		if (data->sat)
		{
			buffer[siz] = 0;
			sn = length;
		}
	}
	if (data->buf_type == SHOR)
	{
		if (!data->sat)
		{
			buffer[siz] = 0;
			sn = length;
		}
	}

	*sizpntr = sn;
}

/**
 * rplcals - Replaces alias with its
 * value
 * @data: Info struct
 * Return: Int type
 */

int rplcals(inf *data)
{
	int k;
	llist *nd;
	char *pntr;

	for (k = 0; k < 10; k++)
	{
		nd = ndstarts(data->als, data->av[0], '=');
		if (!nd)
			return (0);
		free(data->av[0]);
		pntr = _strchr(nd->s, '=');
		if (!pntr)
			return (0);
		pntr = _strdup(pntr + 1);
		if (!pntr)
			return (0);
		data->av[0] = pntr;
	}
	return (1);
}

/**
 * rplcvar - Replaces variables with
 * their values
 * @data: Info struct
 * Return: Int type
 */

int rplcvar(inf *data)
{
	int k = 0;
	llist *nd;

	for (k = 0; data->av[k]; k++)
	{
		if (data->av[k][0] != '$' || !data->av[k][1])
			continue;

		if (!_strcmp(data->av[k], "$?"))
		{
			rplcstr(&(data->av[k]),
				_strdup(convnum(data->sat, 10, 0)));
			continue;
		}
		if (!_strcmp(data->av[k], "$$"))
		{
			rplcstr(&(data->av[k]),
				_strdup(convnum(getpid(), 10, 0)));
			continue;
		}
		nd = ndstarts(data->env, &data->av[k][1], '=');
		if (nd)
		{
			rplcstr(&(data->av[k]),
				_strdup(_strchr(nd->s, '=') + 1));
			continue;
		}
		rplcstr(&data->av[k], _strdup(""));

	}
	return (0);
}

/**
 * rplcstr - Auxiliary function
 * @vecchio: Char double pointer
 * @nuovo: Char pointer
 * Return: Int type
 */

int rplcstr(char **vecchio, char *nuovo)
{
	free(*vecchio);
	*vecchio = nuovo;
	return (1);
}

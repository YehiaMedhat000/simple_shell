#include "main.h"

/**
 * clinf - initializes inf struct
 * @data: struct address
 * Return: Nothing (void)
 */

void clinf(inf *data)
{
	data->agm = NULL;
	data->av = NULL;
	data->pth = NULL;
	data->ac = 0;
}

/**
 * stinf - Set info struct
 * @data: Info struct
 * @av: Arguments
 * Return: Nothing (void)
 */

void stinf(inf *data, char **av)
{
	int j = 0;

	data->file = av[0];
	if (data->agm)
	{
		data->av = _strtow(data->agm, " \t");
		if (!data->av)
		{

			data->av = malloc(sizeof(char *) * 2);
			if (data->av)
			{
				data->av[0] = _strdup(data->agm);
				data->av[1] = NULL;
			}
		}
		for (j = 0; data->av && data->av[j]; j++)
			;
		data->ac = j;

		rplcals(data);
		rplcvar(data);
	}
}

/**
 * frinf - Frees info struct
 * @data: Info struct
 * @chk: Int type
 * Return: Nothing (void)
 */

void frinf(inf *data, int chk)
{
	hfree(data->av);
	data->av = NULL;
	data->pth = NULL;
	if (chk)
	{
		if (!data->buf)
			free(data->agm);
		if (data->env)
			frlst(&(data->env));
		if (data->hst)
			frlst(&(data->hst));
		if (data->als)
			frlst(&(data->als));
		hfree(data->envron);
			data->envron = NULL;
		buffree((void **)data->buf);
		if (data->rdfd > 2)
			close(data->rdfd);
		_putchar(BUFLUSH);
	}
}

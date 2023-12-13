#include "main.h"

/**
 * clr_inf - Inits the info data type
 * @data: Info struct
 * Return: Nothing (void)
 */

void clr_inf(info *data)
{
	data->args = NULL;
	data->av = NULL;
	data->path = NULL;
	data->ac = 0;
}

/**
 * st_inf - Sets the info struct
 * @data: Info struct
 * @argv: Arguments array
 * Return: Nothing (void)
 */

void st_inf(info *data, char **argv)
{
	int j;

	data->file = argv[0];
	if (data->args)
	{
		data->av = _strtow(data->args, " \t");
		if (!data->av)
		{
			data->av[0] = _strdup(data->args);
			data->av[1] = NULL;
		}
	}
	for (j = 0; data->av && data->av[j]; j++)
		;
	data->ac = j;
	rplc_als(data);
	rplc_vars(data);
}

/**
 * fr_inf - Frees an Info struct
 * @data: Info struct
 * @check: check if all
 * Return: Nothing (void)
 */

void fr_inf(info *data, int check)
{
	_free(data->av);
	data->av = NULL;
	data->path = NULL;
	if (check)
	{
		if (!data->bash_buf)
			free(data->args);
		if (data->env)
			fr_lst(&(data->env));
		if (data->hist)
			fr_lst(&(data->hist));
		if (data->als)
			fr_lst(&(data->als));
		_free(data->environ);
		data->environ = NULL;
		bffree((void **)data->bash_buf);
		if (data->rdfd > 2)
			close(data->rdfd);
		_putchar(BUF_FLUSH);
	}
}

#include "main.h"

/**
 * _hstr - Displays history commands
 * in a list form
 * @data: Info struct
 * Return: (0) Always
 */

int _hstr(info *data)
{
	prt_lst(data->hist);
	return (0);
}

/**
 * unst_als - Removes aliases
 * @data: Info struct
 * @s: Alias value
 * Return: (0) success, (1) failure
 */

int unst_als(info *data, char *s)
{
	char *ptr, chr;
	int check;

	ptr = _strchr(s, '=');
	if (!ptr)
		return (1);
	chr = *ptr;
	*ptr = 0;
	check = dlt_nd_idx(&(data->als),
		get_nd_idx(data->als,
	nd_begins_with(data->als, s, -1)));
	*ptr = chr;
	return (check);
}

/**
 * st_als - Inits aliases
 * @data: Info struct
 * @s: Some buffer or string
 * Return: (0) success, (1) failure
 */

int st_als(info *data, char *s)
{
	char *ptr = NULL;

	ptr = _strchr(ptr, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (unst_als(data, s));
	unst_als(data, s);
	return (add_nd_end(&(data->als), s, 0) == NULL);
}

/**
 * prt_als - Prints aliases
 * @nd: Node in the llist
 * Return: (0) success, (1) failure
 */

int prt_als(llist *nd)
{
	char *ptr = NULL, *sth = NULL;

	if (nd)
	{
		ptr = _strchr(nd->s, '=');
		for (sth = nd->s; sth <= ptr; sth++)
			_putchar(*sth);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _als - Custom implementation of the
 * alias bash command
 * @data: Info struct
 * Return: (0) Always
*/

int _als(info *data)
{
	int j;
	char *ptr = NULL;
	llist *nd = NULL;

	if (data->ac == 1)
	{
		nd = data->als;
		while (nd)
		{
			prt_als(nd);
			nd = nd->next;
		}
		return (0);
	}
	for (j = 1; data->av[j]; j++)
	{
		ptr = _strchr(data->av[j], '=');
		if (ptr)
			st_als(data, data->av[j]);
		else
			prt_als(nd_begins_with(data->als, data->av[j], '='));
	}
	return (0);
}

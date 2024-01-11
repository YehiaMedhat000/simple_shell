#include "main.h"

/**
 * _lhst - Builtin history command
 * @data: Info struct
 * Return: Int type
 */

int _lhst(inf *data)
{
	prtlst(data->hst);
	return (0);
}

/**
 * unstals - Unsets alias
 * @data: Info struct
 * @str: Char pointer
 * Return: Int type
 */

int unstals(inf *data, char *str)
{
	char *pntr, chr;
	int ret;

	pntr = _strchr(str, '=');
	if (!pntr)
		return (1);
	chr = *pntr;
	*pntr = 0;
	ret = dltndidx(&(data->als),
		getndidx(data->als, ndstarts(data->als, str, -1)));
	*pntr = chr;
	return (ret);
}

/**
 * stals - Sets an alias value
 * @data: Info struct
 * @string: Char pointer
 * Return: Int type
 */

int stals(inf *data, char *string)
{
	char *pntr;

	pntr = _strchr(string, '=');
	if (!pntr)
		return (1);
	if (!*++pntr)
		return (unstals(data, string));

	unstals(data, string);
	return (addnden(&(data->als), string, 0) == NULL);
}

/**
 * prtals - Printing function
 * @nd: llist type
 * Return: Int type
 */

int prtals(llist *nd)
{
	char *pntr = NULL, *als = NULL;

	if (nd)
	{
		pntr = _strchr(nd->s, '=');
		for (als = nd->s; als <= pntr; als++)
			_putchar(*als);
		_putchar('\'');
		_puts(pntr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _lals - Builtin alias command
 * @data: Info struct
 * Return: Int type
 */

int _lals(inf *data)
{
	int j = 0;
	char *pntr = NULL;
	llist *nd = NULL;

	if (data->ac == 1)
	{
		nd = data->als;
		while (nd)
		{
			prtals(nd);
			nd = nd->next;
		}
		return (0);
	}
	for (j = 1; data->av[j]; j++)
	{
		pntr = _strchr(data->av[j], '=');
		if (pntr)
			stals(data, data->av[j]);
		else
			prtals(ndstarts(data->als, data->av[j], '='));
	}

	return (0);
}

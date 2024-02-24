#include "main.h"

/**
 * _lenv - Prints current environment
 * @data: Info struct
 * Return: Int type
 */

int _lenv(inf *data)
{
	prtlstr(data->env);
	return (0);
}

/**
 * _getenv - Gets a variable's value
 * @data: Info struct
 * @var: Char pointer
 * Return: Char pointer
 */

char *_getenv(inf *data, const char *var)
{
	llist *nd = data->env;
	char *pntr;

	while (nd)
	{
		pntr = find_substring(nd->s, var);
		if (pntr && *pntr)
			return (pntr);
		nd = nd->next;
	}
	return (NULL);
}

/**
 * _lstenv - Inits env variables
 * @data: Info struct
 * Return: Int type
 */

int _lstenv(inf *data)
{
	if (data->ac != 3)
	{
		eprt("Incorrect number of arguements\n");
		return (1);
	}
	if (_stenv(data, data->av[1], data->av[2]))
		return (0);
	return (1);
}

/**
 * _lunstenv - Remove env var
 * @data: Info struct
 * Return: Int type
 */

int _lunstenv(inf *data)
{
	int j;

	if (data->ac == 1)
	{
		eprt("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= data->ac; j++)
		_unstenv(data, data->av[j]);

	return (0);
}

/**
 * ppltenvlst - Populate env llist
 * @data: Info struct
 * Return: Int type
 */

int ppltenvlst(inf *data)
{
	llist *nd = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		addnden(&nd, environ[j], 0);
	data->env = nd;
	return (0);
}

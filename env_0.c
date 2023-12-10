#include "main.h"

/**
 * _getenv - Gets the value of an
 * environment variable
 * @data: Info struct
 * @var: Variable name
 * Return: The var string value
 */

char *_getenv(info *data, const char *var)
{
	llist node = data->env;
	char *i;

	while (node)
	{
		i = begins_with(node->s, var);
		if (i && *i)
			return (i);
		node = node->next;
	}
	return (NULL);
}

/**
 * _env - Prints environment variables
 * @data: Info struct
 * Return: (0) always
 */

int _env(info *data)
{
	prt_lst_str(data->env);
	return (0);
}

/**
 * stenv - Inits new environment variables
 * @data: Info struct
 * Return: (0) always
 */

int stenv(info *data)
{
	if (data->ac != 3)
	{
		eprt("Insert correct number of args.\n");
		return (1);
	}
	if (_stenv(data, data->av[1], data->av[2]))
		return (0);
	return (1);
}

/**
 * unstenv - Removes environment variable
 * @data: Info struct
 * Return: (0) success, (1) failure
 */

int unstenv(info *data)
{
	int j;

	if (data->ac == 1)
	{
		eprt("Insert correct number of args.\n");
		return (1);
	}
	for (j = 1; j <= data->ac; j++)
		_unstenv(data, data->av[j]);
	return (0);
}

/**
 * pplt_env_lst - Populates env llist
 * @data: Info struct
 * Return: (0) Always
 */

int pplt_env_lst(info *data)
{
	llist *node = NULL;
	size_t n;

	for (j = 0; environ[j]; j++)
		add_nd_end(&node, environ[j], 0);
	data->env = node;
	return (0);
}

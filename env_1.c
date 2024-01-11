#include "main.h"

/**
 * get_iron - Copies environ
 * @data: Info struct
 * Return: Char double pointer
 */

char **get_iron(inf *data)
{
	if (!data->envron || data->chenv)
	{
		data->envron = lststr(data->env);
		data->chenv = 0;
	}

	return (data->envron);
}

/**
 * _unstenv - Remove env vrbl
 * @data: Info struct
 * @vrbl: Char pointer
 * Return: Int type
 */

int _unstenv(inf *data, char *vrbl)
{
	llist *nd = data->env;
	size_t j = 0;
	char *pntr;

	if (!nd || !vrbl)
		return (0);

	while (nd)
	{
		pntr = find_substring(nd->s, vrbl);
		if (pntr && *pntr == '=')
		{
			data->chenv = dltndidx(&(data->env), j);
			j = 0;
			nd = data->env;
			continue;
		}
		nd = nd->next;
		j++;
	}
	return (data->chenv);
}

/**
 * _stenv - Auxiliary function
 * @data: Info struct
 * @vrbl: Char pointer
 * @val: Char pointer
 * Return: Int type
 */

int _stenv(inf *data, char *vrbl, char *val)
{
	char *buffer = NULL;
	llist *nd;
	char *pntr;

	if (!vrbl || !val)
		return (0);

	buffer = malloc(_strlen(vrbl) + _strlen(val) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, vrbl);
	_strcat(buffer, "=");
	_strcat(buffer, val);
	nd = data->env;
	while (nd)
	{
		pntr = find_substring(nd->s, vrbl);
		if (pntr && *pntr == '=')
		{
			free(nd->s);
			nd->s = buffer;
			data->chenv = 1;
			return (0);
		}
		nd = nd->next;
	}
	addnden(&(data->env), buffer, 0);
	free(buffer);
	data->chenv = 1;
	return (0);
}

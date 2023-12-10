#include "main.h"

/**
 * get_envrn - Gets copy of environ
 * @data: Info struct
 * Return: Copy of environ
 */

char **get_envrn(info *data)
{
	if (!data->environ || data->ch_env)
	{
		data->environ = lst_str(data->env);
		data->ch_env = 0;
	}
	return (data->environ);
}

/**
 * _unstenv - Removes environment variable
 * @data: Info struct
 * @var: Variable to remove
 * Return: (1) success, (0) otherwise
 */

int _unstenv(info *data, char *var)
{
	llist *node = data->env;
	size_t n = 0;
	char *str;

	while (node)
	{
		str = begins_with(node->s, var);
		if (str && *str == '=')
		{
			data->ch_env = dlt_nd_idx(&(data->env), n);
			n = 0;
			node = data->env;
			continue;
		}
		node = data->env;
		n++;
	}
	return (data->ch_env);
}

/**
 * _stenv - Inits an environment variable
 * @data: Info struct
 * @var_name: Variable name
 * @val: Variable's value
 * Return: (0) success, (1) failure
 */

int _stenv(info *data, char *var_name, char *val)
{
	char *str, *buffer = NULL;
	llist *node;

	if (!var_name || !val)
		return (0);

	buffer = malloc(_strlen(var_name) + _strlen(value) + 2);
	if (!buffer)
		return (0);

	_strcpy(buffer, var_name);
	_strcpy(buffer, "=");
	_strcpy(buffer, val);
	node = data->env;
	while (node)
	{
		str = begins_with(node->s, var_name);
		if (str && *str == '=')
		{
			free(node->s);
			node->s = buffer;
			data->ch_env = 1;
			return (0);
		}
		node = node->next;
	}
	add_nd_end(&(data->env), buffer, 0);
	free(buffer);
	data->ch_env = 1;
	return (0);
}

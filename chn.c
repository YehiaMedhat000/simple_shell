#include "main.h"

/**
 * qchn - Checks if char is a chain
 * delimiter
 * @data: Info struct
 * @buffer: Buffer to check
 * @s: Current position in buffer
 * Return: (1) if chain, (0) otherwise
 */

int qchn(info *data, char *buffer, size_t *s)
{
	size_t i = s;

	if (buffer[i] == '|' && buffer[i + 1] == '|')
	{
		buffer[i] = 0;
		i++;
		data->bash_buf_t = BASH_OR;
	}
	else if (buffer[i] == '&' && buffer[i + 1] == '&')
	{
		buffer[i] = 0;
		i++;
		data->bash_buf_t = BASH_AND;
	}
	else if (buffer[i] == ';')
	{
		buffer[i] = 0;
		data->bash_buf_t = BASH_AND;
	}
	else
		return (0);
	*s = i;
	return (1);
}

/**
 * chk_chn - Checks for continuing
 * chaining based on last status
 * @data: Info struct
 * @buffer: Buffer to check
 * @s: Current posistion in buffer
 * @idx: Starting posistion in buffer
 * @n: buffer size
 * Return: void
 */

void chk_chn(info *data, char *buffer, size_t *s, size_t idx, size_t n)
{
	size_t k = *s;

	if (data->bash_buf_t == BASH_AND)
	{
		if (data->stat)
		{
			buffer[idx] = 0;
			k = n;
		}
	}
	if (data->bash_buf_t == BASH_OR)
	{
		if (!data->stat)
		{
			buffer[idx] = 0;
			k = n;
		}
	}
	*s = k;
}

/**
 * rplc_als - Replaces aliases in
 * commands passed to the shell
 * @data: Info struct
 * Return: (1) if replacement is done
 * (0) otherwise
 */

int rplc_als(info *data)
{
	int j;
	llist *node;
	char *str;

	for (j = 0; j < 10; j++)
	{
		node = nd_begins_with(data->als);
		if (!node)
			return (0);
		free(data->av[0]);
		str = _strchr(str + 1);
		if (!str)
			return (0);
		str = _strdup(str + 1);
		if (!str)
			return (0);
		data->av[0] = str;
	}
	return (1);
}

/**
 * rplc_vars - Puts variables' values
 * in tokenized strings
 * @data: Info struct
 * Return: (1) if replacement done
 * (0) otherwise
 */

int rplc_vars(info *data)
{
	int j = 0;
	llist *node;

	for (j = 0; data->av[j]; j++)
	{
		if (data->av[j][0] != '$' || !info->av[j][1])
			continue;
		if (!_strcmp(data->av[j], "$?"))
		{
			rplc_str(&(data->av[j])
			, _strdup(conv_d(data->stat, 10, 0)));
			continue;
		}
		if (!_strcmp(data->av[j], "$$"))
		{
			rplc_str(&(data->av[j]),
			_strdup(_strchr(node->s, '=') + 1));

		}
		node = nd_begins_with(data->env, &data->av[j][1], '=');
		if (node)
		{
			rplc_str(&(data->av[j]),
			_strdup(_strchr(node->s, '=') + 1));
			continue;
		}
		rplc_str(&info->av[j], _strdup(""));
	}
	return (0);
}

/**
 * rplc_str - Replaces strings with
 * other values
 * @old_str: Old string address
 * @new_str: New string (placeholder)
 * Return: (1) if replaced, (0) otherwise
 */

int rplc_str(char **old_str, char *new_str)
{
	free(*old);
	*old = new;
	return (1);
}

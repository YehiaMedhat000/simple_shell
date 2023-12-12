#include "main.h"

/**
 * _ext - Custom exit command for bash
 * @data: Info struct
 * Return: (1) success, (-2) or (-1)
 * on failure
 */

int _ext(info *data)
{
	int check;

	if (data->av[1])
	{
		check = _etoi(data->av[1]);
		if (check == -1)
		{
			data->stat = 2;
			prt_err(data, "Invalid number: ");
			eprt(data->av[1]);
			eprtchr('\n');
			return (1);
		}
		data->error_n = _etoi(data->av[1]);
		return (-2);
	}
	data->error_n = -1;
	return (-1);
}

/**
 * _cd - Custom implementation of the
 * cd command for shell project
 * @data: Info struct
 * Return: (0) success, (1) failure
 */

int _cd(info *data)
{
	char *str, *directory, buf[R_BUF_S];
	int check;

	str = getcwd(buf, 1024);
	if (!str)
		perror("");
	if (!data->av[1])
	{
		directory = _getenv(data, "HOME=");
		if (!directory)
			check = chdir((directory = _getenv(data, "PWD=")) ? directory : "/");
		else
			check = chdir(directory);
	}
	else if (_strcmp(data->av[1], "-") == 0)
	{
		if (!_getenv(data, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(data, "OLDPWD="));
		_putchar('\n');
		check = chdir((directory = _getenv(data, "OLDPWD=")) ? directory : "/");
	}
	else
		check = chdir(data->av[1]);
	if (check == -1)
	{
		prt_err(data, "Error");
		eprt(data->av[1]);
		eprtchr('\n');
	}
	else
	{
		_stenv(data, "OLDPWD", _getenv(data, "PWD="));
		_stenv(data, "PWD", getcwd(buf, 1024));
	}
	return (0);
}

/**
 * _hlp - Custom implemenation of the
 * help command for shell project
 * @data: Info struct
 * Return: (0) success
 */

int _hlp(info *data)
{
	char **argv;

	argv = data->av;
	_puts("Well, this makes nonsense");
	if (0)
		_puts(*argv);
	return (0);
}

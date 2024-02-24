#include "main.h"

/**
 * _lexit - Builtin exit command
 * @data: Info struct
 * Return: Int type
 */

int _lexit(inf *data)
{
	int chk;

	if (data->av[1])  /* If there is an exit arguement */
	{
		chk = _etoi(data->av[1]);
		if (chk == -1)
		{
			data->sat = 2;
			prterr(data, "Illegal number: ");
			eprt(data->av[1]);
			eprtchr('\n');
			return (1);
		}
		data->errn = _etoi(data->av[1]);
		return (-2);
	}
	data->errn = -1;
	return (-2);
}

/**
 * _lcd - Builtin cd command
 * @data: Info struct
 * Return: Int type
 */

int _lcd(inf *data)
{
	char *str, *drctry, buf[1024];
	int cdret;

	str = getcwd(buf, 1024);
	if (!str)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!data->av[1])
	{
		drctry = _getenv(data, "HOME=");
		if (!drctry)
			cdret = /* TODO: what should this be? */
				chdir((drctry = _getenv(data, "PWD=")) ? drctry : "/");
		else
			cdret = chdir(drctry);
	}
	else if (_strcmp(data->av[1], "-") == 0)
	{
		if (!_getenv(data, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(data, "OLDPWD=")), _putchar('\n');
		cdret = /* TODO: what should this be? */
			chdir((drctry = _getenv(data, "OLDPWD=")) ? drctry : "/");
	}
	else
		cdret = chdir(data->av[1]);
	if (cdret == -1)
	{
		prterr(data, "can't cd to ");
		eprt(data->av[1]), eprtchr('\n');
	}
	else
	{
		_stenv(data, "OLDPWD", _getenv(data, "PWD="));
		_stenv(data, "PWD", getcwd(buf, 1024));
	}
	return (0);
}

/**
 * _lhelp - Builting help command
 * @data: Info struct
 * Return: Int type
 */

int _lhelp(inf *data)
{
	char **arrg;

	arrg = data->av;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arrg);
	return (0);
}

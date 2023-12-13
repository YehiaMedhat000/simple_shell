#include "main.h"

/**
 * qbash - Checks if file is program
 * @data: info struct
 * @p: File path
 * Return: 1 if file is a prog
 * 0 otherwise
 */

int qbash(info *data, char *p)
{
	struct stat sta;

	(void)data;
	if (!p || stat(p, &sta))
		return (0);
	if (sta.st_mode & S_IFREG)
		return (1);
	return (0);
}

/**
 * chardup - Duplicates chars
 * @strpath: The PATH var
 * @init: Initial index
 * @stp: The stopping index
 * Return: The duplicate buffer
 */

char *chardup(char *strpath, int init, int stp)
{
	static char buffer[R_BUF_S];
	int j = 0, n = 0;

	for (n = 0, j = init; j < stp; j++)
	{
		if (strpath[j] != ':')
			buffer[n++] = strpath[j];
	}
	buffer[n] = 0;
	return (buffer);
}

/**
 * f_path - Finds command in PATH
 * @data: Info struct
 * @strpath: PATH value
 * @file: Command file to find
 * Return: If file is found
 * Full path of the file, or NULL
 */

char *f_path(info *data, char *strpath, char *file)
{
	int j = 0, idx = 0;
	char *p;

	if (!strpath)
		return (NULL);
	if ((_strlen(file) > 2) && begins_with(file, "./"))
	{
		if (qbash(data, file))
			return (file);
	}
	while (1)
	{
		if (!strpath[j] || strpath[j] == ':')
		{
			p = chardup(strpath, idx, j);
			if (!*p)
				_strcat(p, file);
			else
			{
				_strcat(p, "/");
				_strcat(p, file);
			}
			if (qbash(data, p))
				return (p);
			if (!strpath[j])
				break;
			idx = j;
		}
		j++;
	}
	return (NULL);
}

#include "main.h"

/**
 * qbash - determines if a file is an executable command
 * @data: the data struct
 * @pth: pth to the file
 * Return: 1 if true, 0 otherwise
 */

int qbash(inf *data, char *pth)
{
	struct stat st;

	(void)data;
	if (!pth || stat(pth, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dupchr - duplicates characters
 * @pthptr: the pth string
 * @begin: starting index
 * @end: stopping index
 * Return: pointer to new buffer
 */

char *dupchr(char *pthptr, int begin, int end)
{
	static char buffer[1024];
	int j = 0, i = 0;

	for (i = 0, j = begin; j < end; j++)
		if (pthptr[j] != ':')
			buffer[i++] = pthptr[j];
	buffer[i] = 0;
	return (buffer);
}

/**
 * fpth - finds this prog in the pth string
 * @data: the data struct
 * @pthptr: the pth string
 * @prog: the prog to find
 * Return: Char pointer
 */

char *fpth(inf *data, char *pthptr, char *prog)
{
	int j = 0, curr_pos = 0;
	char *pth;

	if (!pthptr)
		return (NULL);
	if ((_strlen(prog) > 2) && find_substring(prog, "./"))
	{
		if (qbash(data, prog))
			return (prog);
	}
	while (1)
	{
		if (!pthptr[j] || pthptr[j] == ':')
		{
			pth = dupchr(pthptr, curr_pos, j);
			if (!*pth)
				_strcat(pth, prog);
			else
			{
				_strcat(pth, "/");
				_strcat(pth, prog);
			}
			if (qbash(data, pth))
				return (pth);
			if (!pthptr[j])
				break;
			curr_pos = j;
		}
		j++;
	}
	return (NULL);
}

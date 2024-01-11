#include "main.h"

/**
 * gethstf - Gets history file
 * @data: Info struct
 * Return: Char pointer
 */

char *gethstf(inf *data)
{
	char *buffer, *drctry;

	drctry = _getenv(data, "HOME=");
	if (!drctry)
		return (NULL);
	buffer = malloc(sizeof(char) * (_strlen(drctry) + _strlen(HSTF) + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	_strcpy(buffer, drctry);
	_strcat(buffer, "/");
	_strcat(buffer, HSTF);
	return (buffer);
}

/**
 * wrthst - Creates a file, or append
 * to an existing one
 * @data: Info struct
 * Return: Int type
 */

int wrthst(inf *data)
{
	ssize_t fdes;
	char *file = gethstf(data);
	llist *nd = NULL;

	if (!file)
		return (-1);

	fdes = open(file, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(file);
	if (fdes == -1)
		return (-1);
	for (nd = data->hst; nd; nd = nd->next)
	{
		prtchrfd(nd->s, fdes);
		prtd('\n', fdes);
	}
	prtfd(BUFLUSH, fdes);
	close(fdes);
	return (1);
}

/**
 * rdhst - Reads history
 * @data: Info struct
 * Return: Int type
 */

int rdhst(inf *data)
{
	int j, end = 0, lcnt = 0;
	ssize_t fdes, len, siz = 0;
	struct stat st;
	char *buffer = NULL, *file = gethstf(data);

	if (!file)
		return (0);

	fdes = open(file, O_RDONLY);
	free(file);
	if (fdes == -1)
		return (0);
	if (!fstat(fdes, &st))
		siz = st.st_size;
	if (siz < 2)
		return (0);
	buffer = malloc(sizeof(char) * (siz + 1));
	if (!buffer)
		return (0);
	len = read(fdes, buffer, siz);
	buffer[siz] = 0;
	if (len <= 0)
		return (free(buffer), 0);
	close(fdes);
	for (j = 0; j < siz; j++)
		if (buffer[j] == '\n')
		{
			buffer[j] = 0;
			bldhstlst(data, buffer + end, lcnt++);
			end = j + 1;
		}
	if (end != j)
		bldhstlst(data, buffer + end, lcnt++);
	free(buffer);
	data->hstc = lcnt;
	while (data->hstc-- >= HSTAX)
		dltndidx(&(data->hst), 0);
	rumberhst(data);
	return (data->hstc);
}

/**
 * bldhstlst - Builts llist of history
 * @data: Info struct
 * @buffer: Char pointer
 * @lcnt: Int type
 * Return: Int type
 */

int bldhstlst(inf *data, char *buffer, int lcnt)
{
	llist *nd = NULL;

	if (data->hst)
		nd = data->hst;
	addnden(&nd, buffer, lcnt);

	if (!data->hst)
		data->hst = nd;
	return (0);
}

/**
 * rumberhst - Renindexes history
 * @data: Int type
 * Return: Int type
 */

int rumberhst(inf *data)
{
	llist *nd = data->hst;
	int j = 0;

	while (nd)
	{
		nd->n = j++;
		nd = nd->next;
	}
	return (data->hstc = j);
}

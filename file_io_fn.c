#include "main.h"

/**
 * get_hstfile - Retrieves history
 * file for the history commands
 * @data: Info struct
 * Return: Buffer of the history
 */

char *get_hstfile(info *data)
{
	char *buffer, *d;

	d = _getenv(data, "HOME=");
	if (!d)
		return (NULL);
	buffer = malloc(sizeof(char) * (_strlen(d) + _strlen(HIST_F) + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	_strcpy(buffer, d);
	_strcat(buffer, "/");
	_strcat(buffer, HIST_F);
	return (buffer);
}

/**
 * wrt_hst - Writes history to a buffer
 * existing or newly created
 * @data: Info struct
 * Return: (1) success, (-1) on failure
 */

int wrt_hst(info *data)
{
	ssize_t fd;
	char *file = get_hstfile(data);
	llist *nd = NULL;

	if (!file)
		return (-1);
	fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(file);
	if (fd == -1)
		return (-1);
	for (nd = data->hist; nd; nd = nd->next)
	{
		prtchr_fd(nd->s, fd);
		prtfd('\n', fd);
	}
	prtfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * renum_hst - Reindex history list
 * after changes occurred
 * @data: Info struct
 * Return: The edited histc
 */

int renum_hst(info *data)
{
	llist *nd = data->hist;
	int j = 0;

	while (nd)
	{
		nd->n = j++;
		nd = nd->next;
	}
	return (data->histc);
}

/**
 * rd_hst - Reads history from history
 * file for history functions
 * @data: Info struct
 * Return: (histc) success
 * or (0) on failure
 */

int rd_hst(info *data)
{
	int j, end = 0, lcnt = 0;
	ssize_t fdcr, len, fs = 0;
	struct stat st;
	char *buffer = NULL, *file = get_hstfile(data);

	if (!file)
		return (0);
	fdcr = open(file, O_RDONLY);
	free(file);
	if (fdcr == -1)
		return (0);
	if (!fstat(fdcr, &st))
		fs = st.st_size;
	if (fs < 2)
		return (0);
	buffer = malloc(sizeof(char) * (fs + 1));
	if (!buffer)
		return (0);
	len = read(fdcr, buffer, fs);
	buffer[fs] = 0;
	if (len <= 0)
		return (free(buffer), 0);
	close(fdcr);
	for (j = 0; j < fs; j++)
		if (buffer[j] == '\n')
		{
			buffer[j] = 0;
			bld_hst_lst(data, buffer + end, lcnt++);
			end = j + 1;
		}
	if (end != j)
		bld_hst_lst(data, buffer + end, lcnt++);
	free(buffer);
	data->histc = lcnt;
	while (data->histc-- >= HIST_MAX)
		dlt_nd_idx(&(data->hist), 0);
	renum_hst(data);
	return (data->histc);
}

/**
 * bld_hst_lst - Inits the history list
 * @data: Info struct
 * @buffer: Buffer to use
 * @lc: LineCount, histc
 * Return: (0) Always
 */

int bld_hst_lst(info *data, char *buffer, int lc)
{
	llist *nd = NULL;

	if (data->hist)
		nd = data->hist;
	add_nd_end(&nd, buffer, lc);
	if (!data->hist)
		data->hist = nd;
	return (0);
}

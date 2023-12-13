#include "main.h"

/**
 * shell - Main looping function
 * @data: Info struct
 * @argv: Argument values
 * Return: (0) success, (1) failure
 * or exits with exit code
 */

int shell(info *data, char **argv)
{
	ssize_t i = 0;
	int bltin = 0;

	while (i != -1 && bltin != -2)
	{
		clr_inf(data);
		if (interact(data))
			_puts("$ ");
		eprtchr(BUF_FLUSH);
		i = get_in(data);
		if (i != -1)
		{
			st_inf(data, argv);
			bltin = f_bltin(data);
			if (bltin == -1)
				f_bash(data);
		}
		else if (interact(data))
			_putchar('\n');
		fr_inf(data, 0);
	}
	wrt_hst(data);
	fr_inf(data, 1);
	if (!interact(data) && data->stat)
		exit(data->stat);
	if (bltin == -2)
	{
		if (data->error_n == -1)
			exit(data->stat);
		exit(data->error_n);
	}
	return (bltin);
}

/**
 * f_bltin - Finds commands which are
 * builtin the shell
 * @data: Info struct
 * Return: (-1) if not found,
 * (0) if prog executed successfully
 * (1) if prog found and not executed
 * successfully
 * (-2) if prog sends signal exit()
 */

int f_bltin(info *data)
{
	int j, bltin = -1;
	blt_in blt[] = {
		{"exit", _ext},
		{"env", _env},
		{"help", _hlp},
		{"history", _hstr},
		{"setenv", stenv},
		{"unsetenv", unstenv},
		{"cd", _cd},
		{"alias", _als},
		{NULL, NULL}
	};

	for (j = 0; blt[j].type; j++)
	{
		if (_strcmp(data->av[0], blt[j].type) == 0)
		{
			data->lcount++;
			bltin = blt[j].fn(data);
			break;
		}
	}
	return (bltin);
}

/**
 * f_bash - Checks for the commands
 * location in PATH var
 * @data: Info struct
 * Return: Nothing (void)
 */

void f_bash(info *data)
{
	char *path = NULL;
	int j, l;

	data->path = data->av[0];
	if (data->lcount_flag == 1)
	{
		data->lcount++;
		data->lcount_flag = 0;
	}
	for (j = 0, l = 0; data->args[j]; j++)
	{
		if (!qdelim(data->args[j], " \t\n"))
			l++;
	}
	path = f_path(data, _getenv(data, "PATH="), data->av[0]);
	if (path)
	{
		data->path = path;
		fork_bash(data);
	}
	else
	{
		if ((interact(data) || _getenv(data, "PATH=")
		|| data->av[0][0] == '/') && qbash(data, data->av[0]))
		fork_bash(data);
		else if (*(data->args) != '\n')
		{
			data->stat = 127;
			prt_err(data, "Seems not found\n");
		}
	}
}

/**
 * fork_bash - Forks for runnig exec on
 * child process
 * @data: info struct
 * Return: Nothing (void)
 */

void fork_bash(info *data)
{
	pid_t chld;

	chld = fork();
	if (chld == -1)
	{
		perror("Error: ");
		return;
	}
	if (chld == 0)
	{
		if (execve(data->path, data->av, get_envrn(data)) == -1)
		{
			fr_inf(data, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(data->stat));
		if (WIFEXITED(data->stat))
		{
			data->stat = WEXITSTATUS(data->stat);
			if (data->stat == 126)
				prt_err(data, "Permission denied\n");
		}
	}

}

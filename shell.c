#include "main.h"

/**
 * shell - Main loopin function
 * @data: Info struct
 * @agv: Char double pointer
 * Return: Int type
 */

int shell(inf *data, char **agv)
{
	ssize_t ret = 0;
	int bltinret = 0;

	while (ret != -1 && bltinret != -2)
	{
		clinf(data);
		if (interact(data))
			_puts("$ ");
		eprtchr(BUFLUSH);
		ret = getin(data);
		if (ret != -1)
		{
			stinf(data, agv);
			bltinret = fbltin(data);
			if (bltinret == -1)
				fcmd(data);
		}
		else if (interact(data))
			_putchar('\n');
		frinf(data, 0);
	}
	wrthst(data);
	frinf(data, 1);
	if (!interact(data) && data->sat)
		exit(data->sat);
	if (bltinret == -2)
	{
		if (data->errn == -1)
			exit(data->sat);
		exit(data->errn);
	}
	return (bltinret);
}

/**
 * fbltin - Auxiliary function
 * @data: Info struct
 * Return: Int tp
 */

int fbltin(inf *data)
{
	int ith, bltinret = -1;
	bltin table[] = {
		{"exit", _lexit},
		{"env", _lenv},
		{"help", _lhelp},
		{"history", _lhst},
		{"setenv", _lstenv},
		{"unsetenv", _lunstenv},
		{"cd", _lcd},
		{"alias", _lals},
		{NULL, NULL}
	};

	for (ith = 0; table[ith].tp; ith++)
		if (_strcmp(data->av[0], table[ith].tp) == 0)
		{
			data->lc++;
			bltinret = table[ith].fn(data);
			break;
		}
	return (bltinret);
}

/**
 * fcmd - Auxiliary function
 * @data: Info struct
 * Return: Nothing (void)
 */

void fcmd(inf *data)
{
	char *pathpntr = NULL;
	int ith, kth;

	data->pth = data->av[0];
	if (data->lcf == 1)
	{
		data->lc++;
		data->lcf = 0;
	}
	for (ith = 0, kth = 0; data->agm[ith]; ith++)
		if (!qdelim(data->agm[ith], " \t\n"))
			kth++;
	if (!kth)
		return;

	pathpntr = fpth(data, _getenv(data, "PATH="), data->av[0]);
	if (pathpntr)
	{
		data->pth = pathpntr;
		forsh(data);
	}
	else
	{
		if ((interact(data) || _getenv(data, "PATH=")
			|| data->av[0][0] == '/') && qbash(data, data->av[0]))
			forsh(data);
		else if (*(data->agm) != '\n')
		{
			data->sat = 127;
			prterr(data, "not found\n");
		}
	}
}

/**
 * forsh - Forking function
 * @data: Info struct
 * Return: Nothing (void)
 */

void forsh(inf *data)
{
	pid_t cpid;

	cpid = fork();
	if (cpid == -1)
	{
		perror("Error:");
		return;
	}
	if (cpid == 0)
	{
		if (execve(data->pth, data->av, get_iron(data)) == -1)
		{
			frinf(data, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(data->sat));
		if (WIFEXITED(data->sat))
		{
			data->sat = WEXITSTATUS(data->sat);
			if (data->sat == 126)
				prterr(data, "Permission denied\n");
		}
	}
}

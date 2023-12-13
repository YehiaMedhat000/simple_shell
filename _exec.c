#include "main.h"

/**
 * _exec - Executes a command using execve
 * @args: Array of arguments
 * Return: The execve value in the
 * child
 */

int _exec(char **args)
{
	pid_t pid;

	if (!args || !*args)
		return (-1);

	if (has_access(args[0]) == 1)
	{
		pid = fork();
		if (pid == 0)
		{
			{
				pid = execve(args[0], args, environ);
				if (pid == -1)
				{
					perror("./shell");
					kill(getpid(), SIGQUIT);
				}
			}
		}
	}
	wait(NULL);
	return (pid);
}

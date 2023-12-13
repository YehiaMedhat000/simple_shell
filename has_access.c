#include "main.h"

/**
 * has_access - Checks the
 * accessibility of prog
 * @prog: The program to search in path
 * Return: 1 if prog is accessible
 * -1 if not and errno is set properly
 */

int has_access(char *prog)
{
	int status = access(prog, F_OK | X_OK);

	if (status == -1)
	{
		perror("./shell");
		return (-1);
	}
	return (1);
}

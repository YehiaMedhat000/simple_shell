#include "main.h"

/**
 * main - Entry point
 * @argc: Arguments count
 * @av: Arguments values
 * Return: Int type
 */

int main(int argc, char **av)
{
	inf data[] = { INFINIT };
	int fdes = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fdes)
		: "r" (fdes));

	if (argc == 2)
	{
		fdes = open(av[1], O_RDONLY);
		if (fdes == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				eprt(av[0]);
				eprt(": 0: Can't open ");
				eprt(av[1]);
				eprtchr('\n');
				eprtchr(BUFLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		data->rdfd = fdes;
	}
	ppltenvlst(data);
	rdhst(data);
	shell(data, av);
	return (EXIT_SUCCESS);
}

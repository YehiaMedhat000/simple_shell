#include "main.h"

/**
 * main - Entry point
 * @argc: Argumet count
 * @argv: Argument values
 * Return: (0) success, (1) on failure
 */

int main(int argc, char **argv)
{
	info data[] = {INIT_INFO};
	int fdcr = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0" : "=r" (fdcr)
		: "r" (fdcr));
	if (argc == 2)
	{
		fdcr = open(argv[1], O_RDONLY);
		if (fdcr == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENONET)
			{
				eprt(argv[0]);
				eprt(": 0: Can't open");
				eprt(argv[1]);
				eprtchr('\n');
				eprtchr(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		data->rdfd = fdcr;
	}
	pplt_env_lst(data);
	rd_hst(data);
	shell(data, argv);
	return (EXIT_SUCCESS);
}

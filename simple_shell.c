#include "main.h"

#define USAGE ""

/**
 * main - Main function for the
 * simple shell project
 * Return: (0) Always
 */

int main(void)
{
	char **args, *prompt;
	size_t n = 0;
	int check = 0;

	do {
		printf("#cisfun$ ");
		check = getline(&prompt, &n, stdin);
		if (check == -1)
		{
			break;
		}
		args = get_args(prompt);
		_exec(args);
	} while (check != EOF);
	/* Problem when using C^d: perror gets executed */
	return (0);
}

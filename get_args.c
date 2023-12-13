#include "main.h"

/**
 * get_args - Gets Arguments and
 * tokenizes them from the prompt
 * @prompt: The line passed to the
 * prompt
 * Return: Array of the arguments
 * NULL otherwise
 */

char **get_args(char *prompt)
{
	char **args = malloc(sizeof(char **));
	int i = 0;

	if (!prompt)
		return (NULL);

	*(prompt + strlen(prompt) - 1) = 0;

	/* Split the prompt using strtok() */
	*args = strtok(prompt, " ");
	while (*(args + i))
	{
		i++;
		*(args + i) = strtok(NULL, " ");
	}
	return (args);
}

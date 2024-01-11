#include "main.h"

/**
 * _memset - Prepares memory for use
 * @ptr: Char pointer
 * @byte: Char type
 * @siz: Number of bytes to use
 * Return: Char pointer
 */

char *_memset(char *ptr, char byte, unsigned int siz)
{
	unsigned int j;

	for (j = 0; j < siz; j++)
		ptr[j] = byte;
	return (ptr);
}

/**
 * hfree - Frees array of pointers
 * @pntrpntr: Char double pointer
 */

void hfree(char **pntrpntr)
{
	char **s = pntrpntr;

	if (!pntrpntr)
		return;
	while (*pntrpntr)
		free(*pntrpntr++);
	free(s);
}

/**
 * _realloc - Custom realloc function
 * @ptr: Address of memory
 * @vecsize: Old size of the block
 * @nuovsize: New size of the block
 * Return: Void pointer
 */

void *_realloc(void *ptr, unsigned int vecsize, unsigned int nuovsize)
{
	char *pointer;

	if (!ptr)
		return (malloc(nuovsize));
	if (!nuovsize)
		return (free(ptr), NULL);
	if (nuovsize == vecsize)
		return (ptr);

	pointer = malloc(nuovsize);
	if (!pointer)
		return (NULL);

	vecsize = vecsize < nuovsize ? vecsize : nuovsize;
	while (vecsize--)
		pointer[vecsize] = ((char *)ptr)[vecsize];
	free(ptr);
	return (pointer);
}

/**
 * buffree - Frees memory and
 * the address of the block
 * @pntrpntr: Double pntrpntr
 * Return: (1) success, (0) fail.
 */

int buffree(void **pntrpntr)
{
	if (pntrpntr && *pntrpntr)
	{
		free(*pntrpntr);
		*pntrpntr = NULL;
		return (1);
	}
	return (0);
}

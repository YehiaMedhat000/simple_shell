#include "main.h"

/**
 * _memset - Sets memory with constant
 * byte
 * @ptr: Pointer to the memory block
 * @byte: The byte to put in the block
 * @s: Number of bytes to set
 * Return: (ptr) Pointer to the set
 * block
 */

char *_memset(char *ptr, char byte, unsigned int s)
{
	unsigned int k;

	for (k = 0; k < s; k++)
		ptr[k] = byte;
	return (ptr);
}

/**
 * _free - Frees an allocated buffer
 * @buff: The allocated buffer to free
 * Return: Nothing (void)
 */

void _free(char **buff)
{
	char **ptr = buff;

	if (!ptr)
		return;
	while (*ptr)
		free(*ptr++);
	free(ptr);
}

/**
 * _realloc - Custom implementation of
 * realloc() function
 * @p: Pointer to the old block
 * @s1: The first size of the block
 * @s2: The new size of the block
 * Return: Pointer to the reallocated
 * block of memory
 */

void *_realloc(void *p, unsigned int s1, unsigned int s2)
{
	char *pntr;

	if (!p)
		return (malloc(s2));
	if (!s2)
		return (free(p), NULL);
	if (s1 == s2)
		return (p);
	pntr = malloc(s2);
	if (!pntr)
		return (NULL);
	s1 = s1 < s2 ? s1 : s2;
	while (s1--)
		pntr[s1] = ((char *)p)[s1];
	free(p);
	return (pntr);
}

/**
 * bffree - Frees a memory block and
 * the pointer to the block
 * @pntr: Pointer to the memory block
 * Return: (1) success, (0) otherwise
 */

int bffree(void **pntr)
{
	if (pntr && *pntr)
	{
		free(*pntr);
		*pntr = NULL;
		return (1);
	}
	return (0);
}

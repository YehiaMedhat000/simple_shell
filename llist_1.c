#include "main.h"

/**
 * lstln - Auxiliary function
 * @head: llist pointer
 * Return: size_t type
 */

size_t lstln(const llist *head)
{
	size_t j = 0;

	while (head)
	{
		head = head->next;
		j++;
	}
	return (j);
}

/**
 * lststr - Auxiliary function
 * @hd: llist pointer
 * Return: Char double pointer
 */

char **lststr(llist *hd)
{
	llist *nd = hd;
	size_t k = lstln(hd), i;
	char **strings;
	char *string;

	if (!hd || !k)
		return (NULL);
	strings = malloc(sizeof(char *) * (k + 1));
	if (!strings)
		return (NULL);
	for (k = 0; nd; nd = nd->next, k++)
	{
		string = malloc(_strlen(nd->s) + 1);
		if (!string)
		{
			for (i = 0; i < k; i++)
				free(strings[i]);
			free(strings);
			return (NULL);
		}

		string = _strcpy(string, nd->s);
		strings[k] = string;
	}
	strings[k] = NULL;
	return (strings);
}

/**
 * prtlst - Printing function
 * @head: llist pointer
 * Return: size_t type
 */

size_t prtlst(const llist *head)
{
	size_t j = 0;

	while (head)
	{
		_puts(convnum(head->n, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->s ? head->s : "(nil)");
		_puts("\n");
		head = head->next;
		j++;
	}
	return (j);
}

/**
 * ndstarts - Auxiliary function
 * @nd: llist pointer
 * @prfx: Char pointer
 * @chr: Char type
 * Return: llist pointer
 */

llist *ndstarts(llist *nd, char *prfx, char chr)
{
	char *pntr = NULL;

	while (nd)
	{
		pntr = find_substring(nd->s, prfx);
		if (pntr && ((chr == -1) || (*pntr == chr)))
			return (nd);
		nd = nd->next;
	}
	return (NULL);
}

/**
 * getndidx - Auxiliary function
 * @hd: llist pointer
 * @nd: llist pointer
 * Return: ssize_t type
 */

ssize_t getndidx(llist *hd, llist *nd)
{
	size_t j = 0;

	while (hd)
	{
		if (hd == nd)
			return (j);
		hd = hd->next;
		j++;
	}
	return (-1);
}

#include "main.h"

/**
 * addnd - Auxiliary function
 * @hd: llist double pointer
 * @string: Char pointer
 * @nbr: Int type
 * Return: llist pointer
 */

llist *addnd(llist **hd, const char *string, int nbr)
{
	llist *nhd;

	if (!hd)
		return (NULL);
	nhd = malloc(sizeof(llist));
	if (!nhd)
		return (NULL);
	_memset((void *)nhd, 0, sizeof(llist));
	nhd->n = nbr;
	if (string)
	{
		nhd->s = _strdup(string);
		if (!nhd->s)
		{
			free(nhd);
			return (NULL);
		}
	}
	nhd->next = *hd;
	*hd = nhd;
	return (nhd);
}

/**
 * addnden - Auxiliary function
 * @hd: llist double pointer
 * @string: Char pointer
 * @nbr: Int type
 * Return: llist pointer
 */

llist *addnden(llist **hd, const char *string, int nbr)
{
	llist *nnd, *nd;

	if (!hd)
		return (NULL);

	nd = *hd;
	nnd = malloc(sizeof(llist));
	if (!nnd)
		return (NULL);
	_memset((void *)nnd, 0, sizeof(llist));
	nnd->n = nbr;
	if (string)
	{
		nnd->s = _strdup(string);
		if (!nnd->s)
		{
			free(nnd);
			return (NULL);
		}
	}
	if (nd)
	{
		while (nd->next)
			nd = nd->next;
		nd->next = nnd;
	}
	else
		*hd = nnd;
	return (nnd);
}

/**
 * prtlstr - Printing function
 * @head: llist pointer
 * Return: size_t type
 */

size_t prtlstr(const llist *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(head->s ? head->s : "(nil)");
		_puts("\n");
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * dltndidx - Auxiliary function
 * @hd: llist double pointer
 * @idx: Unsigned int type
 * Return: Int type
 */

int dltndidx(llist **hd, unsigned int idx)
{
	llist *nd, *pvnd;
	unsigned int j = 0;

	if (!hd || !*hd)
		return (0);

	if (!idx)
	{
		nd = *hd;
		*hd = (*hd)->next;
		free(nd->s);
		free(nd);
		return (1);
	}
	nd = *hd;
	while (nd)
	{
		if (j == idx)
		{
			pvnd->next = nd->next;
			free(nd->s);
			free(nd);
			return (1);
		}
		j++;
		pvnd = nd;
		nd = nd->next;
	}
	return (0);
}

/**
 * frlst - Auxiliary function
 * @hdpntr: llist double pointer
 * Return: NULL type
 */

void frlst(llist **hdpntr)
{
	llist *nd, *nnd, *hd;

	if (!hdpntr || !*hdpntr)
		return;
	hd = *hdpntr;
	nd = hd;
	while (nd)
	{
		nnd = nd->next;
		free(nd->s);
		free(nd);
		nd = nnd;
	}
	*hdpntr = NULL;
}

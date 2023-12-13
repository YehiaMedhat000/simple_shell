#include "main.h"

/**
 * add_nd - Adds a node to a llist
 * @hd: Pointer to the head node
 * @s: String value of the node
 * @n: Number value of the node
 * Return: Size of the llist
 * NULL if it failed
 */

llist *add_nd(llist **hd, const char *s, int n)
{
	llist *nhd;

	if (!hd)
		return (NULL);
	nhd = malloc(sizeof(llist));
	if (!nhd)
		return (NULL);
	_memset((void *)nhd, 0, sizeof(llist));
	nhd->n = n;
	if (s)
	{
		nhd->s = _strdup(s);
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
 * add_nd_end - Adds a node at the end
 * of a llist
 * @h: Head
 * @s: String value
 * @n: Number value
 * Return: Size of the llist
 */

llist *add_nd_end(llist **h, const char *s, int n)
{
	llist *nnd, *nd;

	if (!h)
		return (NULL);
	nd = *h;
	nnd = malloc(sizeof(llist));
	if (!nnd)
		return (NULL);
	_memset((void *)nnd, 0, sizeof(llist));
	nnd->n = n;
	if (s)
	{
		nnd->s = _strdup(s);
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
		*h = nnd;
	return (nnd);
}

/**
 * prt_lst_str - Prints s from llist
 * nodes only
 * @head: Head
 * Return: Size of the llist
 */

size_t prt_lst_str(const llist *head)
{
	size_t j = 0;

	while (head)
	{
		_puts(head->s ? head->s : "(nil)");
		_puts("\n");
		head = head->next;
		j++;
	}
	return (j);
}

/**
 * dlt_nd_idx - Deletes node at the
 * given index
 * @h: Head
 * @idx: Index of the node
 * Return: 1 if deleted successfully,
 * 0 otherwise
 */

int dlt_nd_idx(llist **h, unsigned int idx)
{
	llist *nd, *pnd;
	unsigned int j = 0;

	if (!h || !*h)
		return (0);
	if (!idx)
	{
		nd = *h;
		*h = (*h)->next;
		free(nd->s);
		free(nd);
		return (1);
	}
	nd = *h;
	while (nd)
	{
		if (j == idx)
		{
			pnd->next = nd->next;
			free(nd->s);
			free(nd);
			return (1);
		}
		j++;
		pnd = nd;
		nd = nd->next;
	}
	return (0);
}

/**
 * fr_lst - Frees a whole llist
 * @head: Head
 * Return: Nothing (void)
 */

void fr_lst(llist **head)
{
	llist *nd, *nnd, *h;

	if (!head || !*head)
		return;
	h = *head;
	nd = h;
	while (nd)
	{
		nnd = nd->next;
		free(nd->s);
		free(nd);
		nd = nnd;
	}
	*head = NULL;
}

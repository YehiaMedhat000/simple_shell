#include "main.h"

/**
 * lst_ln - Gets the size of llist
 * @head: Head
 * Return: Size of list
 */

size_t lst_ln(const llist *head)
{
	size_t j = 0;

	while (head)
	{
		head = head->next;
		j++;
	}
	return (j);
}
lst_str
/**
 * lst_str - Gets the strings in llist
 * @h: Head
 * Return: Double pointer to the
 * strings extracted
 */

char **lst_str(llist *h)
{
	llist *nd = h;
	size_t j = lst_ln(h), i;
	char *strings;
	char *curstr;

	if (!h || !j)
		return (NULL);
	strings = malloc(sizeof(char *) * (j + 1));
	if (!strings)
		return (NULL);
	for (j = 0; nd; nd = nd->next, j++)
	{
		curstr = malloc(_strlen(nd->s) + 1);
		if (!curstr)
		{
			for (i = 0; i < j; i++)
				free(strings[i]);
			free(strings);
			return (NULL);
		}
		curstr = _strcpy(curstr, nd->s);
		strings[j] = curstr;
	}
	strings[j] = NULL;
	return (strings);
}

/**
 * prt_lst - Prints llist with all
 * contents of numbers and strings
 * @head: Head
 * Return: Size of the llist
 */

size_t prt_lst(const llist *head)
{
	size_t j = 0;

	while (head)
	{
		_puts(conv_d(head->n, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts("\n");
		head = head->next;
		j++;
	}
	return (j);
}

/**
 * nd_begins_with - Gets the node which
 * has a string that begins with pre
 * @head: Head
 * @pre: String to search for
 * @chr: The char after pre to check
 * Return: The node in consideration
 * or null
 */

llist *nd_begins_with(llist *head, char *pre, char chr)
{
	char *str = NULL;

	while (head)
	{
		str = begins_with(head->s, pre);
		if (str && ((chr == -1) || (*str == c)))
			return (head);
		head = head->next;
	}
	return (NULL);
}

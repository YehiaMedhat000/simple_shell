#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define RDBUF 1024
#define WRBUF 1024
#define BUFLUSH -1
#define SHNORM 0
#define SHOR 1
#define SHAND 2
#define SHCHAIN	3
#define CONVLWR	1
#define CONVUNSID	2
#define _GETLINE 0
#define _STRTOK 0
#define HSTF ".shell_project_hst_file"
#define HSTAX 4096

extern char **environ;

/**
 * struct llist - Auxiliary datatype
 * @n: Number
 * @s: String
 * @next: Pointer to the next node
 */

typedef struct llist
{
	int n;
	char *s;
	struct llist *next;
} llist;

/**
 * struct info - Auxiliary datatype
 * @agm: The getline() input
 * @av: Tokenized version of agm
 * @pth: Path of the program used
 * @ac: Argument count
 * @lc: The line count
 * @errn: The errno
 * @lcf: Line count flag
 * @file: The program's name
 * @env: llist with copy of environ
 * @envron: Generated from env
 * @hst: Node of a llist with history
 * @als: Node of llist of aliases
 * @chenv: Check if environ is changed
 * @sat: Status of last execve()
 * @buf: Used when chaining commands
 * @buf_type: Checks for buffer type
 * @rdfd: File describtor to read from
 * @hstc: History count per line
 */

typedef struct info
{
	char *agm;
	char **av;
	char *pth;
	int ac;
	unsigned int lc;
	int errn;
	int lcf;
	char *file;
	llist *env;
	llist *hst;
	llist *als;
	char **envron;
	int chenv;
	int sat;
	char **buf;
	int buf_type;
	int rdfd;
	int hstc;
} inf;

#define INFINIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct bltin_t - Auxiliary datatype
 * @tp: Type of command
 * @fn: Associated function
 */

typedef struct bltin_t
{
	char *tp;
	int (*fn)(inf *);
} bltin;


/* shell.c done */
int shell(inf *, char **);
int fbltin(inf *);
void fcmd(inf *);
void forsh(inf *);

/* path.c done */
int qbash(inf *, char *);
char *dupchr(char *, int, int);
char *fpth(inf *, char *, char *);

/* loop.c */
int lopsh(char **);

/* err_str_fn.c done */
void eprt(char *);
int eprtchr(char);
int prtfd(char c, int fd);
int prtchrfd(char *str, int fd);

/* str_func_0.c done */
int _strlen(char *);
int _strcmp(char *, char *);
char *find_substring(const char *, const char *);
char *_strcat(char *, char *);
char *_strncat(char *, char *, int);

/* str_func_1.c done */
char *_strcpy(char *, char *);
char *_strncpy(char *, char *, int);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* str_func_2.c done */
char *_strchr(char *, char);
char **_strtow(char *, char *);
char **_strtow2(char *, char);

/* mem_fn.c done */
char *_memset(char *, char, unsigned int);
void hfree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int buffree(void **);

/* utils_fn_0.c done */
int interact(inf *);
int qdelim(char, char *);
int qalpha(int);
int _atoi(char *);

/* utils_fn_1.c done */
int _etoi(char *);
void prterr(inf *, char *);
int prtd(int, int);
char *convnum(long int, int, int);
void rmcmnt(char *);

/* bltin_0.c done */
int _lexit(inf *);
int _lcd(inf *);
int _lhelp(inf *);

/* bltin_1.c done */
int _lhst(inf *);
int _lals(inf *);

/* getline.c done */
ssize_t getin(inf *);
int _getline(inf *, char **, size_t *);
void sgntndl(int);

/* info.c done */
void clinf(inf *);
void stinf(inf *, char **);
void frinf(inf *, int);

/* env_0.c done */
char *_getenv(inf *, const char *);
int _lenv(inf *);
int _lstenv(inf *);
int _lunstenv(inf *);
int ppltenvlst(inf *);

/* env_1.c done */
char **get_iron(inf *);
int _unstenv(inf *, char *);
int _stenv(inf *, char *, char *);

/* file_io_fn.c done */
char *gethstf(inf *info);
int wrthst(inf *info);
int rdhst(inf *info);
int bldhstlst(inf *info, char *buf, int linecount);
int rumberhst(inf *info);

/* llist_0.c done */
llist *addnd(llist **, const char *, int);
llist *addnden(llist **, const char *, int);
size_t prtlstr(const llist *);
int dltndidx(llist **, unsigned int);
void frlst(llist **);

/* llist_1.c done */
size_t lstln(const llist *);
char **lststr(llist *);
size_t prtlst(const llist *);
llist *ndstarts(llist *, char *, char);
ssize_t getndidx(llist *, llist *);

/* chain.c done */
int qchain(inf *, char *, size_t *);
void chkchn(inf *, char *, size_t *, size_t, size_t);
int rplcals(inf *);
int rplcvar(inf *);
int rplcstr(char **, char *);

#endif

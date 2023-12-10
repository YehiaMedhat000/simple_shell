#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <stddef.h>
#include <limits.h>
#include <fcntl.h>

/* Buffer macros */
#define R_BUF_S 1024
#define W_BUF_S 1024
#define BUF_FLUSH -1
/* Command macros */
#define BASH_NORM 0
#define BASH_OR 1
#define BASH_AND 2
#define BASH_CHAIN 3
/* Other macros */
#define CONV_LOWER 1
#define CONV_UNSGND 2
#define _GETLINE 0
#define _STRTOK 0
#define HIST_F ".shell_hist"
#define HIST_MAX 4096
#define INIT_INFO {NULL, NULL, NULL\
, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0\
, NULL, 0, 0, 0}

extern char **environ;

/**
 * struct llist - Singly linked list
 * for storing strings and integers
 * @n: The number to store
 * @s: The string to store
 * @next: Pointer to the next node
 */

typedef struct llist
{
	int n;
	char *s;
	struct llist *next;
} llist;

/**
 * struct command_info - Collects all needed
 * command info to be executed
 * @args: String has collect all
 * arguments for a command
 * @av: Array of strings of the
 * arguments
 * @path: String of the path of the
 * current command
 * @ac: Arguments count
 * @lcount: Error count
 * @error_n: The errorno of exit
 * @lcount_flag: line of input
 * @file: Name of the program
 * @env: copy of environ llist
 * @environ: modified copy from env
 * @hist: hist node
 * @als: alias from the node
 * @ch_env: defined if environ changed
 * @stat: return from last exec call
 * @bash_buf: Pointer to bash_buf if
 * @bash_buf_t: bash_type operators
 * @rdfd: fd which to read from
 * @histc: history line count
 */

typedef struct command_info
{
	char *args;
	char **av;
	char *path;
	int ac;
	unsigned int lcount;
	int error_n;
	int lcount_flag;
	char *file;
	llist env;
	char **environ;
	llist hist;
	llist als;
	int ch_env;
	int stat;
	char **bash_buf;
	int bash_buf_t;
	int rdfd;
	int histc;
} info;

/**
 * struct blt_in - Collects a string
 * and a function
 * @type: flag of the builtin command
 * @fn: function
 */

typedef struct blt_in
{
	char *type;
	int (*fn)(info *);
} blt_in;

/* shell.c */
int shell(info *, char **);
int f_bltin(info *);
void f_bash(info *);
void fork_bash(info *);

/* path.c */
int qbash(info *, char *);
char *chardup(char *, int, int);
char f_path(info *, char *, char *);

/* sh_loop.c */
int sh_loop(char **);

/* err_str_fn.c */
void eprt(char *);
int eprtchr(char);
int prtfd(char c, int fd);
int prtchr_fd(char *str, int fd);

/* str_fn_0.c */
int _strlen(char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
size_t _strspn(const char *s, const char *accept);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *s, int c);

/* str_fn_1.c */
char *_strtok_r(char *str, const char *delim, char **saveptr);
size_t _strcspn(const char *s, const char *reject);
int _strcmp(char *, char*);
char *begins_with(const char *, const char *);
char *_strcat(char *, char *);

/* str_fn_2.c */
char *_strcpy(char *, char*);
char *_strncpy(char *, char *, int);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* str_fn_3.c */
char *_strncat(char *, char*, int);
char **_strtow(char *, char *);
char **_strtowchr(char *, char);

/* mem.c */
char *_memset(char *, char, unsigned int);
void _free(char **);
void *_realloc(void *, unsigned int, unsigned int);
int bffree(void **);

/* func_0.c */
int interact(info *);
int qdelim(char, char*);
int qalpha(int);
int _atoi(char *);

/* func_1.c */
int _etoi(char *);
void prt_err(info *, char *);
int prt_d(int, int);
char *conv_d(long int, int, int);
void rm_comnt(char *);

/* bltin_emlatrs_0.c */
int _ext(info *);
int _cd(info *);
int _hlp(info *);

/* bltin_emlators_1.c */
int _hstr(info *);
int _als(info *);

/* _getline.c */
ssize_t get_in(info *);
int _getline(info *, char **, size_t *);
void sgnthndlr(int);

/* inf.c */
void clr_inf(info *);
void st_inf(info *, char **);
void fr_inf(info *, int);

/* env_0.c */
char *_getenv(info *, const char *);
int _env(info *);
int stenv(info *);
int unstenv(info *);
int pplt_env_lst(info *);

/* env_1.c */
char **get_envrn(info *);
int _unstenv(info *, char *);
int _stenv(info *, char *, char *);

/* file_io_fn.c */
char *get_hstfile(info *);
int wrt_hst(info *);
int rd_hst(info *);
int bld_hst_lst(info *, char *, int);
int rnmbr_hst(info *);

/* lst_str_0.c */
llist *add_nd(llist **, const char *, int);
llist *add_nd_end(llist **, const char *, int);
size_t prt_lst_str(const llist *);
int dlt_nd_idx(llist **, unsigned int);
void fr_lst(llist **);

/* lst_str_1.c */
size_t lst_ln(const llist *);
char **lst_str(llist *);
size_t prt_lst(const llist *);
llist *nd_begins_with(llist *, char *, char);
ssize_t get_nd_idx(llist *, llist *);

/* chn.c */
int qchn(info *, char *, size_t *);
void chk_chn(info *, char *, size_t *, size_t, size_t);
int rplc_als(info *);
int rplc_vars(info *);
int rplc_str(char **, char *);

#endif

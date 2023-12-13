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
,0,0,0,0,NULL,NULL,NULL,NULL,NULL,0,0\
,NULL,0,0,0}

extern char **environ;

char **get_args(char *prompt);
int _exec(char *args[]);
char *_getenv(const char *var);
int has_access(char *prog);

size_t _strlen(char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
size_t _strspn(const char *s, const char *accept);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *s, int c);

char *_strtok_r(char *str, const char *delim, char **saveptr);
size_t _strcspn(const char *s, const char *reject);
#endif

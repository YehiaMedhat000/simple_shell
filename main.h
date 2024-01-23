#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

/* MACROS */
#define BUFFSIZE 4096

/* string_1.c */
size_t _strlen(char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, const char *src);

/* string_2.c */
char *_strcat(char *dest, const char *src);

/*char *_strtok(char *str, char *delim);*/


#endif

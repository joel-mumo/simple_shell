#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
/**
 * aliases - struct
 * @a_name: alias name
 * @name: real name
 */
typedef struct aliases
{
	char *a_name;
	char *name;
} alias;

/**
 * builts - struct for builtins
 * @name: pointer to name
 */
typedef struct builts
{
	char *name;
	int (*func)(void);
} builts;

int execute(char **argv);
char *get_path(char *cmd);
void execmd(char **argv);
#endif /*MAIN_H*/

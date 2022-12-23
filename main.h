#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int execute(char **argv);
char *get_path(char *cmd);
void execmd(char **argv);
#endif /*MAIN_H*/

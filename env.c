#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the current environment
 * @argc: number of arguments
 * @argv: an array of argc arguments
 * @envp: Pointer to environment variables
 * Return: 0 on success
 */
int main(int argc, char *argv[], char *envp[])
{
	char **env;

	for (env = envp; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}

	return (0);
}

#include "main.h"

/**
 * main - prompts user for input and parses commands
 * @argc: Number of arguments
 * @argv: An array of argc arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *prompt = " $ ";
	char *lineptr = NULL, *lineptr_cp = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int tokens_num = 0;
	char *token;
	int i;
	(void)argc;
	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
			return (-1);
		lineptr_cp = malloc(sizeof(char) * nchars_read);
		if (lineptr_cp == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(lineptr_cp, lineptr);
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			tokens_num++;
			token = strtok(NULL, delim);
		}
		tokens_num++;
		argv = malloc(sizeof(char *) * tokens_num);
		token = strtok(lineptr_cp, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		 argv[i] = NULL;
		 execmd(argv);
	} return (0);
}

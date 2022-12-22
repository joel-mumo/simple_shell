#include "main.h"

/**
 * execute - create process and executing program
 *@argv: pointer array
 *
 * Return: always 0
 */
int execute(char **argv)
{
	int status;
	pid_t pid;
	
	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error:");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}

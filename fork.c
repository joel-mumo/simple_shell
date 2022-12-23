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
	int x;

	pid = fork();
	if (pid == 0)
	{
		x = execve(argv[0], argv, NULL);
		if (x == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
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

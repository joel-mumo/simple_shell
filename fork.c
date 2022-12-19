#include "main.h"

/**
 * _execute - create process and executing program
 *@argv: pointer array
 *
 * Return: always 0
 */
int _execute(char **argv)
{
	int status;
	pid_t pid, wpid;

	pid = fork();
	if (pid == 0)
	{
		x = execve(argv[0], argv, env);
		if (x == -1)
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
			wpid = waitpid(pid, &status, WUNTRANCED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}

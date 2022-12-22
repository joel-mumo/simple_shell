#include "main.h"

/**
 * execute - executes program
 * @argv: args
 */
void execute(char **argv)
{
	char *cmd = NULL;

	if (argv)
	{
		cmd = argv[0];

		if (execve(cmd, argv, NULL) == -1)
		{
			perror("Error:");
		};
	}
}

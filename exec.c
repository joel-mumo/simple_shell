#include "main.h"

/**
 * execmd - gets path
 * @argv: An array of command line arguments
 */
void execmd(char **argv)
{
	char *cmd = NULL, *actual_cmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		actual_cmd = get_path(cmd);

		if (execve(actual_cmd, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}

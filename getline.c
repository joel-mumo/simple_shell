#include "main.h"

/**
 * read_line - prints prompt and reads a line
 *
 */

char read_line(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	int c;

	while (1)
	{
		printf("$ ");
		c = getline(&lineptr, &n, stdin);
		if (c == -1)
		{
			if (feof(stdin))
			{
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (lineptr);
}

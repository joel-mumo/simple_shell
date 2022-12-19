#include <stdio.h>
#include <string.h>

/**
 * main - Handle command lines with arguments
 * @argc: Number of command line address
 * @argv: An array argc arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *token;
	char *delimiter = " ";

	if (argc < 2)
	{
		printf("Error: No arguments provided\n");
		return (1);
	}

	token = strtok(argv[1], delimiter);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delimiter);
	}

	return (0);
}

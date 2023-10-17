#include "monty.h"

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: nothing
 */
int main(int argc, char **argv)
{
	if (argc == 2)
		handle_cmd(argv[1]);
	else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

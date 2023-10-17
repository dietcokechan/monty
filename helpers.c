#include "monty.h"

global_t global = {NULL, NULL};

/**
 * handle_cmd - handles commands in file
 * @argv: arg vector
 * Return: nothing
 */
void handle_cmd(char *argv)
{
	int count = 0, res = 0;
	size_t bufsize = 0;
	char *args = NULL, *i = NULL;
	stack_t *stack = NULL;

	global.fd = fopen(argv, "r");
	if (global.fd)
	{
		while (getline(&global.line, &bufsize, global.fd) != -1)
		{
			count++;
			args = strtok(global.line, " \n\t\r");
			if (args == NULL)
			{
				free(args);
				continue;
			}
			else if (*args == '#')
				continue;
			i = strtok(NULL, " \n\t\r");
			res = get_op(&stack, args, i, count);
			if (res == 1)
				push_error(global.fd, global.line, stack, count);
			else if (res == 2)
				ins_error(global.fd, global.line, stack, args, count);
		}
		free (global.line);
		free_dlist(stack);
		fclose(global.fd);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(1);
	}
}

/**
 * free_dlist - frees list
 * @stack: stack
 * Return: nothing
 */
void free_dlist(stack_t *stack)
{
	stack_t *curr = NULL;

	curr = stack;

	if (curr != NULL)
	{
		free_dlist(curr->next);
		free(curr);
	}
}
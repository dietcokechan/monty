#include "monty.h"

/**
 * add_node - add new node
 * @n: number
 * Return: new node
 */
stack_t *add_node(int n)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->next = NULL;
	node->prev = NULL;

	return (node);
}

/**
 * _isdigit - checks for digit 0-9
 * @c: char
 * Return: 0 or 1
 */
int _isdigit(char *c)
{
	char *dig = c;

	if (c == NULL)
		return (0);
	if (*dig == '-')
		dig++;

	for (; *dig != '\0'; dig++)
	{
		if ((*dig < '0' || *dig > '9'))
			return (0);
	}
	return (1);
}

/**
 * cleanup - frees mallocs and closes files
 * @stack: stack
 * Return: nothing
 */
void cleanup(stack_t **stack)
{
	stack_t *curr = *stack;

	for (; curr; curr = *stack)
	{
		*stack = (*stack)->next;
		free(curr);
	}
	fclose(global.fd);
	free(global.line);
}

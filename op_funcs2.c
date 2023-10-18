#include "monty.h"

/**
 * _pop - removes top element of stack
 * @stack: stack
 * @line_num: line number
 * Return: nothing
 */
void _pop (stack_t **stack, unsigned int line_num)
{
	stack_t *curr = NULL;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_num);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}

	curr = *stack;

	*stack = curr->next;
	if (curr->next != NULL)
		curr->next->prev = curr->prev;
	free(curr);
}

/**
 * _swap - swaps top two elements of stack
 * @stack: stack
 * @line_num: line number
 * Return: nothing
 */
void _swap(stack_t **stack, unsigned int line_num)
{
	stack_t *curr = *stack;
	int tmp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	tmp = curr->n;
	curr->n = curr->next->n;
	curr->next->n = tmp;
}

/**
 * _add - adds two integers
 * @stack: stack
 * @line_num: line number
 * Return: nothing
 */
void _add(stack_t **stack, unsigned int line_num)
{
	stack_t *curr = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	sum = curr->n + curr->next->n;
	curr->next->n = sum;
	_pop(stack, line_num);
}

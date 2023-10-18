#include "monty.h"

/**
 * _sub - subtracts top element from second element
 * @stack: stack
 * @line_num: line number
 * Return: nothing
 */
void _sub(stack_t **stack, unsigned int line_num)
{
	stack_t *curr = *stack;
	int sub = 0;

	if (!curr || !curr->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	sub = curr->next->n - curr->n;
	curr->next->n = sub;
	_pop(stack, line_num);
}

/**
 * _div - function div two number
 * @stack: Stack list
 * @line_number: Number of the line
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line_num)
{
	stack_t *curr = NULL;
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	div = curr->next->n / curr->n;
	curr->next->n = div;
	_pop(stack, line_num);
}

/**
 * _mul - multiplies the second top with the top element.
 * @stack: Stack.
 * @line_num: Number of line
 */
void _mul(stack_t **stack, unsigned int line_num)
{
	stack_t *curr = NULL;
	int mul = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;

	mul = curr->next->n * curr->n;
	_pop(stack, line_num);
	curr->next->n = mul;
}
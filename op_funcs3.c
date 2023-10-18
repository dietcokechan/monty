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

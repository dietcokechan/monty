#include "monty.h"

int val = 0;

/**
 * get_op - handle opcode
 * @stack: stack
 * @arg: arg
 * @i: item
 * @count: count
 * Return: nothing
 */
int get_op(stack_t **stack, char *arg, char *i, int count)
{
	int j = 0;
	int check_dig;

	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{NULL, NULL}};

	while (ops[j].opcode)
	{
		if (!strcmp(arg, ops[j].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				check_dig = _isdigit(i);
				if (check_dig == 1)
					val = atoi(i);
				else
					return (1);
			}
			ops[j].f(stack, (unsigned int)count);
			break;
		}
		j++;
	}
	if (!ops[j].opcode)
		return (2);
	return (0);
}

/**
 * _push - pushed an element to the stack
 * @stack: stack
 * @line_num: line number
 * Return: nothing
 */
void _push(stack_t **stack, unsigned int line_num)
{
	stack_t *node = NULL;
	(void)line_num;

	node = add_node(val);
	node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = node;
	*stack = node;
}

/**
 * _pall - print element stack
 * @stack: stack
 * @line_num: line number
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int line_num)
{
	stack_t *curr = NULL;
	(void)line_num;

	curr = *stack;

	while (curr != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * _pint - prints value at top of the stack
 * @stack: stack
 * @line_num: line number
 */
void _pint(stack_t **stack, unsigned int line_num)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_num);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	else
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}

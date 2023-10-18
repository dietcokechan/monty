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
#include "monty.h"

/**
 * sub_m - subtract the two most items on the top of the stack
 * @stack: the topmost item on the stack:
 * @line_number: the line from the .m file that is being executed
 * Return: Nothing
 */
void sub_m(stack_t **stack, unsigned int line_number)
{
	stack_t *item_top = *stack;
	stack_t *item_bottom;
	int total;

	total = 0;

	if (item_top == NULL)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	item_bottom = item_top->prev;

	if (item_bottom == NULL)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	total = item_bottom->n - item_top->n;
	item_bottom->n = total;
	pop_m(stack, line_number);
}

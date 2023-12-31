#include "monty.h"

/**
 * add_m - add  the two topmost items on a stack
 * and store result in second top element and remove the topmost
 * @stack: the topmost item on the stack:
 * @line_number: the line from the .m file that is being executed
 * Return: Nothing
 */
void add_m(stack_t **stack, unsigned int line_number)
{
	stack_t *item_top = *stack;
	stack_t *item_bottom;
	int total;

	total = 0;

	if (item_top == NULL)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	item_bottom = item_top->prev;

	if (item_bottom == NULL)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	total = item_top->n + item_bottom->n;
	item_bottom->n = total;
	pop_m(stack, line_number);
}

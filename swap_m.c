#include "monty.h"

/**
 * swap_m - add a new item on to the top a stack
 * @stack: the topmost item on the stack:
 * @line_number: the line from the .m file that is being executed
 * Return: Nothing
 */
void swap_m(stack_t **stack, unsigned int line_number)
{
	stack_t *item_top = *stack;
	stack_t *item_bottom;
	int temp;

	if (item_top == NULL)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	item_bottom = item_top->prev;

	if (item_bottom == NULL)
	{
		dprintf(2, "L%u: can't swap, stack to short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = item_top->n;
	item_top->n = item_bottom->n;
	item_bottom->n = temp;
	*stack = item_top;
}

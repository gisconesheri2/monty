#include "monty.h"

void swap_m(stack_t **stack, unsigned int line_number)
{
	stack_t *item_top = *stack;
	stack_t *item_bottom = item_top->prev;
	int temp;

	if (item_top == NULL || item_bottom == NULL)
	{
		dprintf(2, "L%u: can't swap, stack to short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = item_top->n;
	item_top->n = item_bottom->n;
	item_bottom->n = temp;
	*stack = item_top;
}

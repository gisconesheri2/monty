#include "monty.h"

void pchar_m(stack_t **stack, unsigned int line_number)
{
	stack_t *top_item = *stack;
	int num;

	if (top_item == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = top_item->n;

	if (num > 126 || num < 0)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	printf("%c\n", num);
}

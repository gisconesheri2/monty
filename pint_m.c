#include "monty.h"

/**
 * pint_m - print all the alements in a stack
 * @stack: the topmost item on the stack
 * @line_number: the line from the .m file that is being executed
 * Return: Nothing
 */
void pint_m(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		dprintf(2, "L%u: can't pint, stck empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", temp->n);

}

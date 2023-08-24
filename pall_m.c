#include "monty.h"

/**
 * pall_m - print all the alements in a stack
 * @stack: the topmost item on the stack
 * @line_number: the line from the .m file that is being executed
 * Return: Nothing
 */
void pall_m(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
		exit(0);

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}

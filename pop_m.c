#include "monty.h"
/**
 * pop_m - add a new item on to the top a stack
 * @stack: the topmost item on the stack
 * @line_number: the line from the .m file that is being executed
 * Return: Nothing
 */
void pop_m(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *head = *stack;
	stack_t *temp;

	if (head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = head;
	head = head->prev;
	free(temp);
	*stack = head;
}

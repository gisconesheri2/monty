#include "monty.h"
/**
 * pop_m - remove the topmost item on to the top a stack
 * @stack: the topmost item on the stack
 * @line_number: the line from the .m file that is being executed
 * Return: Nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *head = stack;
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->prev;
		free(temp);
	}
}

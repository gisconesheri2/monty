#include "monty.h"
/**
 * free_stack - remove the topmost item on to the top a stack
 * @stack: the topmost item on the stack
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

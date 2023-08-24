#include "monty.h"
/**
 * push_m - add a new item on to the top a stack
 * @stack: the topmost item on the stack:
 * @line_number: the line from the .m file that is being executed
 * Return: Nothing
 */
void push_m(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *head = *stack;
	stack_t *temp;

	if (data == 0 && true_zero == 0)
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (head == NULL)
	{
		temp->n = data;
		temp->next = NULL;
		temp->prev = NULL;
		*stack = temp;
	}
	else
	{
		temp->n = data;
		temp->prev = head;
		temp->next = NULL;
		*stack = temp;
	}
}

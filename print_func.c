#include "monty.h"

/**
 * pall - prints the value of all items on the stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void
 */
void pall(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

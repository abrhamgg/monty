#include "monty.h"

/**
 * opcode_getfunc - check for opcode and return the appropirate
 * function
 * @stack: pointer to stack
 * @line_number: line of opcode from user input
 * @opcode: tokenized string
 * Return: 0 on success, 1 on failure
 */

int opcode_getfunc(char *opcode, stack_t **stack, int line_number)
{
	int i;

	instruction_t op[] = {
		{"pall", pall},
		{"nop", nop},
		{"pint", pint},
		{"pstr", pstr},
		{"pop", pop},
		{NULL, NULL}
	};

	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, op[i].opcode) == 0)
		{
			(op[i].f)(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	printf("L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

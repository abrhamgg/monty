#include "monty.h"
#define _GNU_SOURCE
#include <stdio.h>
/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 if success, 1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	stack_t *stack = NULL;
	char *opcode;
	char *n;
	unsigned int line_number;
	char *line = malloc(512 * sizeof(char));

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 0;
	while (fgets(line, sizeof(line), fp))
	{
		line_number++;
		opcode = strtok(line, DELIMITERS);
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;
		while (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				n = strtok(NULL, DELIMITERS);
				push(&stack, line_number, n);
			}
			else
			{
				opcode_getfunc(opcode, &stack, line_number);
			}
			opcode = strtok(NULL, DELIMITERS);
		}
	}
	free(line);
	return (EXIT_SUCCESS);
}

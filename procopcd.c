#include "monty.h"

/**
 * process_opcode - Process a single Monty byte code line
 * @line: Monty byte code line
 * @line_number: Line number in the file
 * @stack: Pointer to the head of the stack
 * Return: 1 on success, 0 on failure
 */
int process_opcode(char *line, unsigned int line_number, stack_t **stack)
{
	char *line_copy, *line_copy_copy, *opcode, *argument;
	int value;

	line_copy = strdup(line);
	line_copy_copy = strdup(line);

	if (line_copy == NULL)
	{
		fprintf(stderr, "Error: strdup failed\n");
		return (0);
	}
	opcode = strtok(line_copy, " \t\n");

	if (opcode != NULL && opcode[0] != '#')
	{
		argument = strchr(line_copy_copy, ' ');

		if (argument != NULL)
		{
			while (*argument != '\0' && isspace(*argument))
				argument++;
			if (strcmp(opcode, "push") == 0)
			{
				value = strtol(argument, NULL, 10);
				push(stack, value);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(stack);
			}
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				free(line_copy);
				return (0);
			}
		}
	}
	free(line_copy);
	return (1);
}

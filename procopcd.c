#include "monty.h"

/**
 * get_opcode - Get the opcode from the given line
 * @line: The line containing the opcode and argument
 * Return: The opcode extracted from the line
 */
char *get_opcode(char *line)
{
	char *line_copy, *opcode, *opcode_str;

	line_copy = strdup(line);

	if (line_copy == NULL)
	{
		fprintf(stderr, "Error: strdup failed\n");
		exit(EXIT_FAILURE);
	}

	while (*line_copy != '\0' && isspace(*line_copy))
	{
		line_copy++;
	}

	opcode = strtok(line_copy, " \t\n$");

	opcode_str = strdup(opcode);

	if (opcode_str == NULL)
	{
		fprintf(stderr, "Error: strdup failed\n");
		exit(EXIT_FAILURE);
	}

	free(line_copy);

	return (opcode_str);
}

/**
 * get_argument - Get the argument from the given line
 * @line: The line containing the opcode and argument
 * Return: The argument extracted from the line
 */
int get_argument(char *line)
{
	char *line_copy, *argument, *newline_ptr;
	int arg_value;

	line_copy = strdup(line);

	if (line_copy == NULL)
	{
		fprintf(stderr, "Error: strdup failed\n");
		exit(EXIT_FAILURE);
	}

	while (*line_copy != '\0' && isspace(*line_copy))
		line_copy++;

	argument = strchr(line_copy, ' ');

	if (argument != NULL)
	{
		while (*argument != '\0' && isspace(*argument))
			argument++;


		newline_ptr = strchr(argument, '\n');

		if (newline_ptr != NULL)
			*newline_ptr = '\0';


		arg_value = atoi(argument);
	}
	else
	{
		arg_value = 0;
	}

	printf("Debug: Argument = %d\n", arg_value);

	free(line_copy);
	return (arg_value);
}


/**
 * process_instruction - Process a single Monty instruction
 * @opcode: The opcode to be processed
 * @line: Monty code line
 * @line_number: Line number in the file
 * @stack: Pointer to the head of the stack
 * Return: 1 on success, 0 on failure
 */
int process_instruction(
	char *opcode_ptr, char *line, unsigned int line_number, stack_t **stack)
{

	printf("Debug2: Opcode = \"%s\"\n", opcode_ptr);

	if (strcmp(opcode_ptr, "push") == 0)
	{
		push(stack, line);
	}
	else if (strcmp(opcode_ptr, "pall") == 0)
	{
		pall(stack);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode_ptr);
		return (0);
	}

	return (1);
}


/**
 * process_opcode - Process a single Monty byte code line
 * @line: Monty byte code line
 * @line_number: Line number in the file
 * @stack: Pointer to the head of the stack
 * Return: 1 on success, 0 on failure
 */
int process_opcode(char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode_ptr = get_opcode(line);
	int args = get_argument(line);

	printf("%d,\n", args);
	printf("%s\n", opcode_ptr);

	if (opcode_ptr != NULL && opcode_ptr[0] != '#')
	{
		return (process_instruction(opcode_ptr, line, line_number, stack));
	}

	return (1);
}

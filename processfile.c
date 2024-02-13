#include "monty.h"
#include <ctype.h>

/**
 * process_file - Process the Monty byte code file
 * @file_path: Path to the Monty byte code file
 * @stack: Pointer to the head of the stack
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int process_file(const char *file_path, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	int exit_status = EXIT_SUCCESS;

	FILE *file = fopen(file_path, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		return (EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		if (!process_opcode(line, line_number, stack))
		{
			exit_status = EXIT_FAILURE;
			break;
		}
	}

	free(line);
	fclose(file);
	free_stack(*stack);
	return (exit_status);
}

#include "monty.h"

/**
 * main - Entry point for the Monty program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	int exit_status;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	exit_status = process_file(argv[1], &stack);

	return (exit_status);
}

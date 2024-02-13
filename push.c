#include "monty.h"
#include <ctype.h>

/**
 * print_stack - Prints the contents of the stack
 * @stack: Pointer to the head of the stack
 *
 * Description: This function prints the contents of the stack, starting from
 * the top element, down to the bottom. It iterates through each element of
 * the stack and prints its value.
 */

void print_stack(stack_t *stack)
{
	stack_t *temp = stack;

	printf("Stack contents:\n");
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * push - Pushes an integer onto the stack
 * @stack: Pointer to the head of the stack
 * @line: Monty code line
 * @line_number: Line number in the Monty byte code file
 *
 * Description: This function implements the `push` opcode, which pushes an
 * integer onto the top of the stack. If the argument is not an integer or
 * cannot be converted to an integer, it prints an error message and exits
 * with failure status.
 */
void push(stack_t **stack, char *line)
{
	int argument = get_argument(line);
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = argument;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

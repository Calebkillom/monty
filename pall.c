#include "monty.h"
/**
 * pall - Implementation of the pall opcode
 * @stack: Pointer to the head of the stack
 */
void pall(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * is_integer - Check if a string represents a valid integer
 * @str: String to check
 * Return: 1 if str is a valid integer, 0 otherwise
 */

int is_integer(const char *str)
{
	if (str == NULL || *str == '\0' || (*str == '-' && *(str + 1) == '\0'))
		return (0);

	for (; *str != '\0'; str++)
	{
		if (*str < '0' || *str > '9')
			return (0);
	}

	return (1);
}

/**
 * free_stack - Free a doubly linked list (stack)
 * @stack: Pointer to the head of the stack
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

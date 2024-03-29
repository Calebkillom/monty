#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <ctype.h>
#include <limits.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, char *line);
void pall(stack_t **stack);
int is_integer(const char *str);
void free_stack(stack_t *stack);
int process_opcode(char *line, unsigned int line_number, stack_t **stack);
int process_file(const char *file_path, stack_t **stack);
void print_stack(stack_t *stack);
int process_instruction(
	char *opcode, char *line, unsigned int line_number, stack_t **stack);
char *get_opcode(char *line);
int get_argument(char *line);

#endif /* MONTY_H */

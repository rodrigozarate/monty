#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

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


typedef void (*point_f)(stack_t **, unsigned int);
stack_t *new_node(int n);
void error_handle(int error_code, ...);
void error_handle1(int error_code, ...);
void open_file(char *file_name);
void parse_file(FILE *monty_file);
int parse_line(char *p_line, int line_number, int mode);
void select_function(char *opcode, char *data, int line_number, int mode);
void call_function(point_f f, char opcode, char *data, int line_number, int mode);
void push(stack_t **stack, unsigned int line_number, int number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */

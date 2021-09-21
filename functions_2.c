/*
* monty.c - interpret monty opcodes
* Autor: Cristian Oliveros and Rodrigo Zárate A.
* Date: September 20, 2021
*/

#include "header_monty.h"

/**
 * sub - Subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: Struct with the element's stack.
 * @line_number: Struct with the element's stack.
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int count = 1;

	while (*stack)
	{
		count++;
		*stack = *stack->next;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	*stack = *current->next;
	*stack->next->n -= stack->n;
	if (*current->next)
		*current->next->prev = NULL;
	free(current);
}

/**
 * div - Divides the second top element of
 * the stack by the top element of the stack.
 * @stack: Struct with the element's stack.
 * @line_number: Struct with the element's stack.
 * Return: void
 */
void div(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int count = 1;

	while (*stack)
	{
		count++;
		*stack = *stack->next;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	*stack = *current->next;
	*stack->next->n = *stack->next->n / stack->n;
	if (*current->next)
		*current->next->prev = NULL;
	free(current);
}

/**
 * mul - Multiplies the second top element of
 * the stack with the top element of the stack.
 * @stack: Struct with the element's stack.
 * @line_number: Struct with the element's stack.
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int count = 1;

	while (*stack)
	{
		count++;
		*stack = *stack->next;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	*stack = *current->next;
	*stack->next->n = *stack->next->n * stack->n;
	if (*current->next)
		*current->next->prev = NULL;
	free(current);
}

/**
 * mod - Computes the rest of the division of
 * the second top element of the stack by the
 * top element of the stack.
 * @stack: Struct with the element's stack.
 * @line_number: Struct with the element's stack.
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int count = 1;

	while (*stack)
	{
		count++;
		*stack = *stack->next;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	*stack = *current->next;
	*stack->next->n = *stack->next->n % stack->n;
	if (*current->next)
		*current->next->prev = NULL;
	free(current);
}

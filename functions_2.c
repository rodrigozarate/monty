/*
* functions_2.c - File with helper functions.
* Autor: Cristian Oliveros and Rodrigo Zárate A.
* Date: September 20, 2021
*/

#include "monty.h"

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

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(current);
}

/**
 * _div - Divides the second top element of
 * the stack by the top element of the stack.
 * @stack: Struct with the element's stack.
 * @line_number: Struct with the element's stack.
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
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

	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
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

	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(current);
}

/**
 * pchar - Prints the char at the top of the
 * stack, followed by a new line.
 * @stack: Struct with the element's stack.
 * @line_number: Struct with the element's stack.
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if (tmp->n < 32 || tmp->n > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}

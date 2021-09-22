/*
 * functions_3.c - File with helper functions.
 * Autor: Cristian Oliveros and Rodrigo Zárate A.
 * Date: September 20, 2021
 */

#include "header_monty.h"

/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: Struct with the element's stack.
 * @line_number: Integer to be inserted.
 * Return: void.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
		error_handle(2, line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Struct with the element's stack.
 * @line_number: Integer to be inserted.
 * Return: void.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp = 0, count = 1;

	while (*stack)
	{
		count++;
		*tack = (*stack)->next;
	}

	if (count < 2)
		error_handle(4, line_number);

	while (*stack)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp
	}
}

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Struct with the element's stack.
 * @line_number: Integer to be inserted.
 * Return: void.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!stack)
		printf("\n"),
			return;
	while (*stack)
	{
		if ((*stack)->n > 0 && (*stack)->n <= 255)
			printf("%c\n", (*stack)->n);
		else
			breack;
		*stack = (*stack)->next;
	}
}

/**
 * rotl - Rotates the stack to the top.
 * @stack: Struct with the element's stack.
 * @line_number: Integer to be inserted.
 * Return: Void.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *tmp1 = *stack, *tmp2;

	while (tmp1->next)
		tmp1 = tmp1->next;

	tmp2 = tmp1->prev;
	tmp2->next = NULL;
	tmp1->prev = NULL;
	tmp1->next = *stack;
	(*stack)->prev = tmp1;
	*stack = tmp1;
}

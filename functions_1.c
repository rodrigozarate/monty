/*
* functions_1.c - File with helper functions.
* Autor: Cristian Oliveros and Rodrigo Zárate A.
* Date: September 20, 2021
*/

#include "header_monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Struct with the element's stack.
 * @line_number: Number to push in the stack.
 * @number: Integer to be inserted.
 * Return: void.
 */
void push(stack_t **stack, unsigned int line_number, int number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		error_handle(6, line_number);

	new_node->n = number;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: Struct with the element's stack.
 * @line_number: Number to push in the stack.
 * Return: void.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}

/**
 * pop - Removes the top element of the stack.
 * @stack: Struct with the element's stack.
 * @line_number: Number to push in the stack.
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!stack)
		error_handle(3, line_number);

	*stack = current->next;
	if (current->next)
		current->next->prev = NULL;
	free(current);

}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Struct with the element's stack.
 * @line_number: Number to push in the stack.
 * Return: void.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int count = 1;

	while (*stack)
	{
		count++;
		*stack = (*stack)->next;
	}

	if (count < 2)
		error_handle(5, line_number);

	*stack = current->next;
	(*stack)->next->n += (*stack)->n;
	if (current->next)
		current->next->prev = NULL;
	free(current);
}

/**
 * nop - Doesn’t do anything.
 * @stack: Struct with the element's stack
 * @line_number: Number to push in the stack.
 * Return: void.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

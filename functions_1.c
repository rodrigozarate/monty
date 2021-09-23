/*
* functions_1.c - File with helper functions.
* Autor: Cristian Oliveros and Rodrigo Zárate A.
* Date: September 20, 2021
*/

#include "monty.h"


/**
 * push - Pushes an element to the stack.
 * @stack: Struct with the element's stack.
 * @line_number: Number to push in the stack.
 * Return: void.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node_to_stack;

	(void) line_number;
	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);

	/* head is empty */
	if (stk_head == NULL)
	{
		stk_head = *stack;
		return;
	}
	node_to_stack = stk_head;
	stk_head = *stack;
	stk_head->next = node_to_stack;
	node_to_stack->prev = stk_head;
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
	stack_t *tmp1;

	(void)line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);

	tmp1 = *stack;
	while (tmp1 != NULL)
	{
		printf("%d\n", tmp1->n);
		tmp1 = tmp1->next;
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

	if (!stack || !*stack)
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

	if (!*stack || !stack || !(*stack)->next)
		error_handle(5, line_number);

	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
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

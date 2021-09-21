/*
* monty.c - interpret monty opcodes
* Autor: Cristian Oliveros and Rodrigo Zárate A.
* Date: September 20, 2021
*/

#include "header_monty.h"

/**
* add_node - add node to the top
* @stack: pointer header
* @n: value int
* Return: void
*/

void add_node(stack_t **stack, const int n)
{
	/* add node to the top of stack */
	stack_t *newnode;

	newnode = malloc(sizeof(struct));
	if (newnode == NULL)
		return (1);
	newnode->prev = NULL;
	newnode->next = *stack;
	newnode->n = n;

	if (*stack != NULL)
		(*stack)->prev = newnode;
	*stack = newnode;
}

/**
* print_list - print list from top
* @stack: pointer to head
* Return: void
*/

void print_list(stack_t **stack)
{
	int i;
	/* print nodes from top to bottom */
	for (i = 0; stack != NULL; i++)
	{
		printf("%d\n", stack->n);
	}
}

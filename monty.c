/*
* monty.c - interpret monty opcodes
* Autor: Cristian Oliveros and Rodrigo Zárate A.
* Date: September 20, 2021
*/

#include "monty.h"
stack_t *stk_head = NULL;

/**
* main - Entry Point
* @argc: counter arguments
* @argv: Array of arguments
* Return: 0
*/

int main(int argc, char **argv)
{
	/* too much or too many arguments */
	if (argc < 2 || argc > 2)
		error_handle1(10);

	/* Reach this point read the file */
	open_file(argv[1]);
	free_stack();
	return (0);
}

/**
* new_node - Create a space in memory
* @n: int
* Return: pointer or NULL
*/

stack_t *new_node(int n)
{
	stack_t *node;
	/* here the data is saved in node */
	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error_handle(6);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_stack - frees the stack
 */
void free_stack(void)
{
	stack_t *tmp1;
	if (stk_head == NULL)
		return;
	/* walk nodes in stack */
	while (stk_head != NULL)
	{
		tmp1 = stk_head;
		stk_head = stk_head->next;
		/* free Willi */
		free(tmp1);
	}
}

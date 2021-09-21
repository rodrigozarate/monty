/*
* monty.c - interpret monty opcodes
* Autor: Cristian Oliveros and Rodrigo Zárate A.
* Date: September 20, 2021
*/

#include "header_monty.h"

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
		error_handling1(10);

	/* Reach this point read the file */
	open_file(argv[1]);
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

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error_handling(6);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

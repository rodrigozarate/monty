/*
* file_parser.c - interpret monty opcodes
* Autor: Cristian Oliveros and Rodrigo Zárate A.
* Date: September 21, 2021
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header_monty.h"

/**
* open_file - Open monty files .m
* @file_name: path to files
* Return: void
*/

void open_file(char *file_name)
{
	FILE *monty_file;
	int file_exists;

	file_exists = access(file_name, F_OK);
	if (file_exists == -1)
	{
		printf("Error: ");
		error_handle(7, file_name);
	}
	if (file_name == NULL)
	{
		printf("Error: ");
		error_handle(7, file_name);
	}
	monty_file = fopen(file_name, "r");
	if (monty_file == NULL)
	{
		printf("Error: ");
		error_handle(7, file_name);
	}
	/* reach this point */
	/* convert file into instructions */
	parse_file(monty_file);
	/* close file */
	fclose(monty_file);
}

void parse_file(FILE *monty_file)
{
	int line_number;
	size_t buf;
	/* default mode stack */
	int mode;
	char *p_line;

	mode = 0;
	p_line = NULL;
	buf = 0;

	/* cant open file */
	if (monty_file == NULL)
	{
		printf("Error: ");
		error_handle(7, monty_file);
	}

	/* walk file */
	for (line_number = 1;
		getline(&p_line, &buf, monty_file) != EOF; line_number++)  
	{
		parse_line(p_line, line_number, mode);
	}
	free(p_line);
}


int parse_line(char *p_line, int line_number, int mode)
{
	char *opcode;
	char *data;
	const char *separator;

	if (p_line == NULL)
		error_handle(6);

	separator ="\n ";
	/* get opcode first token */
	opcode = strtok(p_line, separator);

	/* no content in line */
	if (opcode == NULL)
		return (0);
	/* get data next token in line */
	data = strtok(NULL, separator);
	/* select mode */
	if (strcmp(opcode, "queue") == 0)
	{
		mode = 1;
		return (1);
	}
	else if (strcmp(opcode, "stack") == 0)
	{
		mode = 0;
		return (0);
	}

	/* if no mode selected use default */
	/* select function */
	select_function(opcode, data, line_number, mode);
	return (mode);
}


void select_function(char *opcode, char *data, int line_number, int mode)
{
	/* push pall and friends */
	int i;
	/* function not found */
	int fnf; 

	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pint", pint},
		{"swap", swap},
		{"pstr", pstr},
		{"rotl", rotl},
		{"push_queue", push_queue},
		{NULL, NULL}
	};

	/* comment */
	/* dont go further skip and parse next line */
	if (opcode[0] == '#')
		return;

	for (i = 0, fnf = 1; functions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, functions[i].opcode) == 0)
		{
			call_function(functions[i].f, opcode,
					data, line_number, mode);
			/* function match */
			fnf = 0;
		}
	}
	/* reach this point */
	/* fnf still 1 = error */
	if (fnf == 1)
		error_handle(8, line_number, opcode);
}

void call_function(point_f f, char *opcode, char *data, int line_number, int mode)
{
	stack_t *node;

	if (mode == 1)
	{
		/* send mode to function */
		/* will queue */
	}
	else
	{
		/* continue stack */
	}

	if (strcmp(opcode, "push") == 0)
	{
		if (data == NULL)
			error_handle(6);

		node = new_node(atoi(data));
		if (mode == 0)
		{	
			f(&node, line_number);
		}
		if (mode == 1)
		{
			push_queue(&node, line_number);
		}
	}
	else
	{
		f(&stk_head, line_number);
	}
}

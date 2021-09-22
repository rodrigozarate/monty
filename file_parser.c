/*
* file_parser.c - interpret monty opcodes
* Autor: Cristian Oliveros and Rodrigo Zárate A.
* Date: September 21, 2021
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"

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
		error_handle(7, file_name);
	}
	if (file_name == NULL)
	{
		error_handle(7, file_name);
	}
	monty_file = fopen(file_name, "r");
	if (monty_file == NULL)
	{
		error_handle(7, file_name);
	}
	/* reach this point */
	/* convert file into instructions */
	parse_file(monty_file);
	/* close file */
	fclose(monty_file);
}

/**
 * parse_file - cut file into lines
 * @monty_file: file to be cutted
 */
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
		error_handle(7, monty_file);
	}

	/* walk file */
	for (line_number = 1;
			getline(&p_line, &buf, monty_file) != EOF;
			line_number++)
	{
		mode = parse_line(p_line, line_number, mode);
	}
	free(p_line);
}

/**
 * parse_line - cut line into tokens
 * @p_line: pointer to buffer with line
 * @line_number: int
 * @mode: mode LIFO or FIFO
 * Return: int - mode
 */
int parse_line(char *p_line, int line_number, int mode)
{
	char *opcode;
	char *data;
	const char *separator;

	if (p_line == NULL)
		error_handle(6);

	separator = "\n ";
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

/**
 * select_function - Select function based on opcode
 * @opcode: pointer
 * @data: info in node
 * @line_number: int
 * @mode: FIFO or LIFO
 */
void select_function(char *opcode, char *data,
		int line_number, int mode)
{
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
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"push_queue", push_queue},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	for (i = 0, fnf = 1; functions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, functions[i].opcode) == 0)
		{
			call_function(functions[i].f, opcode, data,
					line_number, mode);
			fnf = 0;
		}
	}
	if (fnf == 1)
		error_handle(8, line_number, opcode);
}

/**
 * call_function - Execute function
 * @f: function
 * @opcode: char
 * @data: char
 * @line_number: int
 * @mode: FIFO or LIFO
 */
void call_function(point_f f, char *opcode, char *data,
		int line_number, int mode)
{
	int i = 0;

	stack_t *node;

	if (strcmp(opcode, "push") == 0)
	{	
		if (data == NULL)
			error_handle(6);

		while (data[i] != '\0')
		{
			if (isdigit(data[i]) == 0)
				error_handle(1, line_number);
			i++;
		}
		node = new_node(atoi(data) * sign);
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

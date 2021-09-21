/*
* monty.c - interpret monty opcodes
* Autor: Cristian Oliveros and Rodrigo Zárate A.
* Date: September 20, 2021
*/

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
		error_handle(5, file_name);

	if (file_name == NULL)
		error_handle(5, file_name);

	monty_file = fopen(file_name, "r");
	if (monty_file == NULL)
		error_handle(5, file_name);

	/* reach this point */
	/* convert file into instructions */
	parse_file(monty_file);
	/* close file */
	fclose(monty_file);
}

void parse_file(FILE *monty_file)
{
	int line;
	size_t buf;
	/* default mode stack */
	mode = 0;
	
	/* check for errors */
	for (line = 1; getline(&p_line, &buf, monty_file != EOF; line++)  
	{
		line_slice = parse_line(p_line, line, mode);
	}
	free(p_line);
}


int parse_line(char *p_line, int line, line_slice)
{

	/* do the strok  */
	/* select function */


	return (int);
}


void select_function()
{
	/* push pall and friends */
	int i;
	/* function not found */
	int fnf; 

	instruction_t functions[] = {
		{"push", add_node},
		{"pall", print_list}
	};

	for (/*nodes in instructions */)
	{
		if (/* item in instructions == opcode */)
		{
			call_function(functions[i].f, opcode, value, line, mode);
		}
	}
}

void call_function(/* params from select */)
{
	/* do stuff */
	pall(n, line*, opcode)
}

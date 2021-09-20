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

	if (filename == NULL)
		error_handle(X, file_name);

	monty_file = fopen(file_name, "r");
	if (monty_file == NULL)
		error_handle(X, file_name);

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
	
	/* check for errors */
	for (line = 1; getline(&p_line, &buf, monty_file != EOF; line++)  
	{
		line_slice = parse_line(p_line, line, 0);
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
}

void call_function()
{
	/* do stuff */
}

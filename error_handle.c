/*
* error_handle.c - Mesage errors according code
* Author: Cristian Oliveros and Rodrigo Zarate A.
* Date: September 20, 2021
*/

/*
* If the user does not give any file or more than one argument to your program,
* print the error message USAGE: monty file, followed by a new line,
*  and exit with the status EXIT_FAILURE
*
* If, for any reason, it’s not possible to open the file,
* print the error message Error: Can't open file <file>,
* followed by a new line, and exit with the status EXIT_FAILURE
* where <file> is the name of the file
*
* If the file contains an invalid instruction, print the error message
*  L<line_number>: unknown instruction <opcode>, followed by a new line,
* and exit with the status EXIT_FAILURE
* where is the line number where the instruction appears.
* Line numbers always start at 1
*
* If you can’t malloc anymore, print the error message
*  Error: malloc failed, followed by a new line,
* and exit with status EXIT_FAILURE.
*/

#include "header_monty.h"

/**
* error_handle - Shows erros acordingly to code
* @error_code: code to select error to show
* Return: Error
*
*/

void error_handle(int error_code, ...)
{
	va_list error_list;
	char *text_line;
	int line_number;

	va_start(error_list, error_code);
	switch (error_code)
	{
	case 1:
		fprintf(stderr, "L%d: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
		break;
	case 2:
		fprintf(stderr, "L%d: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
		break;
	case 3:
		fprintf(stderr, "L%d: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
		break;
	case 4:
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
		break;
	case 5:
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
		break;
	case 6:
		fprintf(stderr, "L%d: malloc fail\n",
			line_number);
		exit(EXIT_FAILURE);
		break;
	case 7:
		printf("Error: Can't open file %s\n",
		       va_arg(error_list, char *));
		exit(EXIT_FAILURE);
	default;
	break;
	/* free list nodes */
	/* exit */
	exit(EXIT_FAILURE);
}

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
		break;
	case 2:
		fprintf(stderr, "L%d: can't pint, stack empty\n",
			line_number);
		break;
	case 3:
		fprintf(stderr, "L%d: can't pop an empty stack\n",
			line_number);
		break;
	case 4:
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		break;
	case 5:
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		break;
	case 6:
		fprintf("Error: malloc failed\n");
		break;
	case 7:
		printf("Error: Can't open file %s\n",
		       va_arg(error_list, char *));
	case 8:
		line_number = va_arg(error_list, int);
		opcode = va_arg(error_list, char *);
		printf("L%d: unknown instruction %s\n", line_number, opcode);
	default;
	break;
	/* free list nodes */
	/* exit */
	exit(EXIT_FAILURE);
}

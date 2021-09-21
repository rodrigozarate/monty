/*
* error_handle.c - Mesage errors according code
* Author: Cristian Oliveros and Rodrigo Zarate A.
* Date: September 20, 2021
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
		printf(stderr, "L%d: usage: push integer\n",
			line_number);
		break;
	case 2:
		printf(stderr, "L%d: can't pint, stack empty\n",
			line_number);
		break;
	case 3:
		printf(stderr, "L%d: can't pop an empty stack\n",
			line_number);
		break;
	case 4:
		printf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		break;
	case 5:
		printf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		break;
	case 6:
		fprintf("Error: malloc failed\n");
		break;
	case 7:
		printf("Error: Can't open file %s\n",
		       va_arg(error_list, char *));
		break;
	case 8:
		line_number = va_arg(error_list, int);
		opcode = va_arg(error_list, char *);
		printf("L%d: unknown instruction %s\n", line_number, opcode);
		break;
	default;
		break;
	}
	/* To do free list nodes */
	/* exit */
	exit(EXIT_FAILURE);
}

/**
* error_handle1 - Shows erros acordingly to code
* @error_code: code to select error to show
* Return: Error
*
*/

void error_handle1(int error_code, ...)
{
        va_list error_list;
        char *text_line;
        int line_number;

        va_start(error_list, error_code);
        switch (error_code)
        {
	case 10:
		printf("USAGE: monty file\n");
		break;
	default;
		break;
	}
	exit(EXIT_FAILURE);
}




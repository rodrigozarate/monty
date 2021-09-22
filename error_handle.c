/*
* error_handle.c - Mesage errors according code
* Author: Cristian Oliveros and Rodrigo Zarate A.
* Date: September 20, 2021
*/

#include "monty.h"

/**
* error_handle - Shows erros acordingly to code
* @error_code: code to select error to show
* Return: Error
*
*/

void error_handle(int error_code, ...)
{
	va_list error_list;
	int line_number;
	char *opcode;

	va_start(error_list, error_code);
	line_number = va_arg(error_list, int);
	opcode = va_arg(error_list, char *);
	switch (error_code)
	{
	case 1:
		printf("L%d: usage: push integer\n",
			line_number);
		break;
	case 2:
		printf("L%d: can't pint, stack empty\n",
			line_number);
		break;
	case 3:
		printf("L%d: can't pop an empty stack\n",
			line_number);
		break;
	case 4:
		printf("L%d: can't swap, stack too short\n",
			line_number);
		break;
	case 5:
		printf("L%d: can't add, stack too short\n",
			line_number);
		break;
	case 6:
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
		break;
	case 7:
		printf("Can't open file %s\n",
		       va_arg(error_list, char *));
		break;
	case 8:
		opcode = va_arg(error_list, char *);
		printf("L%d: unknown instruction %s\n", line_number, opcode);
		break;
	default:
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
        char *opcode;
        int line_number;

	line_number = va_arg(error_list, int);
	opcode = va_arg(error_list, char *);

        va_start(error_list, error_code);
        switch (error_code)
        {
	case 10:
		printf("USAGE: monty file\n");
		break;
	case 11:
		printf("L%d", line_number);
		break;
	case 12:
		printf("L%s", opcode);
		break;
	default:
		break;
	}
	exit(EXIT_FAILURE);
}

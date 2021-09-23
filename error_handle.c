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
	int lin_n;
	char *err_c;
	va_start(error_list, error_code);

	switch (error_code)
	{
	case 1:
		fprintf(stderr, "L%d: usage: push integer\n",
				va_arg(error_list, int));
		break;
	case 2:
		fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(error_list, int));
		break;
	case 3:
		fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(error_list, int));
		break;
	case 4:
		fprintf(stderr, "L%d: can't swap, stack too short\n",
				va_arg(error_list, int));
		break;
	case 5:
		fprintf(stderr, "L%d: can't add, stack too short\n",
				va_arg(error_list, int));
		break;
	case 6:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 7:
		fprintf(stderr, "Can't open file %s\n",
				va_arg(error_list, char *));
		break;
	case 8:
		lin_n = va_arg(error_list, int);
		err_c = va_arg(error_list, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n",
				lin_n, err_c);
		break;
	default:
		break;
	}
	/* To do free list nodes */
	va_end(error_list);
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

	va_start(error_list, error_code);

        switch (error_code)
        {
	case 10:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 11:
		fprintf(stderr, "L%d", va_arg(error_list, int));
		break;
	case 12:
		fprintf(stderr, "L%s", va_arg(error_list, char *));
		break;
	default:
		break;
	}
	va_end(error_list);
	exit(EXIT_FAILURE);
}

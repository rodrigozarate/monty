#include ".h"


void add_node(**stack, const int n)
{
	/* add node to the top of stack */
	struct *newnode;
	newnode = malloc(sizeof(struct));
	if (newnode == NULL)
		return (1);
	newnode->prev = NULL;
	newnode->next = *stack;
	newnode->n = n;

	if (*stack != NULL)
		(*stack)->prev = newnode;
	*stack = newnode;
}

void print_list(**stack)
{
	int i;
	/* print nodes from top to bottom */
	for (i = 0; stack != NULL; i++)
	{
		printf("%d\n", stack->n);
	}
}

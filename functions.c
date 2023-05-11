#include "monty.h"
void _push(stack_t **stack, unsigned int line_number)
{
    char *token = strtok(NULL, DELIM);
	
    if (!token || !isdigit(*token))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = atoi(token);
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *line = *stack;
	(void)line_number;
	
	while (line)
	{
		printf("%d\n", line->n);
		line = line->next;
	}
}

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
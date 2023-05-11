#include "monty.h"
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *line = malloc(sizeof(stack_t));
	char *token = strtok(NULL, DELIM);

	if (!line) {
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!token || !_digit(token)) {
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	line->n = atoi(token);
	line->prev = NULL;
	line->next = *stack;
	if (*stack) {
		(*stack)->prev = line;
	}
	*stack = line;
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
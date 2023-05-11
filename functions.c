#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *line = malloc(sizeof(stack_t));
	char *token = strtok(NULL, DELIM);

	if (!line) {
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!token || _digit(token) == 0 || !stack) {
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
	if (!(*stack))
		return;
	while (line->next)
	{
		line = line->next;
	}
	while (line)
	{
		printf("%d\n", line->n);
		line = line->prev;
	}
}

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	printf("%d\n", tmp->n);
}
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (tmp->next == NULL)
	{
		free(tmp);
		*stack = NULL;
	}
	tmp = (*stack)->next;
		free(*stack);
	*stack = tmp;
	if (!(*stack))
		return;
	(*stack)->prev = NULL;
}

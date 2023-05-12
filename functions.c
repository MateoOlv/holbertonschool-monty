#include "monty.h"

/**
 * _push - Adds a new node at the beginning of a stack_t stack.
 *
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 *
 * Return: Nothing.
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *token = strtok(NULL, DELIM);
	stack_t *line;
	int n2 = 0;

	if (!token || _digit(token) == 0 || !stack)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	 n2 = atoi(token);

	line = malloc(sizeof(stack_t));
	if (!line)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	line->n = n2;
	line->prev = NULL;
	line->next = *stack;

	if (line->next !=NULL)
	{	
		(line->next)->prev = line;
	}
	*stack = line;
}

/**
* _pall - prints all the elements in the stack
* @stack: double pointer to the head of the stack
* @line_number: line number of the opcode in the Monty bytecodes file
* Return: void
*/
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
/**
 * _pint - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being executed
 *
 * Return: void
 */
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

/**
 * _pop - removes the top element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being executed
 *
 * Return: void
 */

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
}

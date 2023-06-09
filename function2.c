#include "monty.h"
/**
*_nop - does nothing
*@stack: pointer to a pointer to the top node of the stack
*@line_number: current line number in the Monty file being interpreted
*Return: void
*/
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
*_swap - swaps the top two elements of the stack
*@stack: pointer to a pointer to the top node of the stack
*@line_number: current line number in the Monty file being interpreted
*Return: void
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	int x;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	x = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = x;
}
/**
*_add - adds the top two elements of the stack
*@stack: pointer to a pointer to the top node of the stack
*@line_number: current line number in the Monty file being interpreted
*Return: void
*/
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int x;

	if (*stack == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	x = tmp->n;
	*stack = (*stack)->next;
	free(tmp);
	(*stack)->prev = NULL;
	(*stack)->n = (*stack)->n + x;
}

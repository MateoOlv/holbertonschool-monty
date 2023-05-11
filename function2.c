void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void _swap(stack_t **stack, unsigned int line_number)
{
	int x;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	x = (*stack)->n;
	(*stack)-> = (*stack)->next->n;
	(*stack)->next->n = x;
}

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int x;

	if(!(*stack) || !(stack)->next)
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

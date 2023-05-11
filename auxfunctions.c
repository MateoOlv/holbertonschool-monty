#include "monty.h"

/**
 * _digit - Checks if a string is a digit
 * @string: The string to check
 *
 * Return: 1 if @string is a digit, 0 otherwise
 */

int _digit(char string[])
{
	int i;

	if (!string)
		return (0);
	for (i = 0; string[i]; i++)
	{
		if (string[i] == '-')
			i++;
		if (isdigit(string[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/**
* frees - Frees a stack_t stack.
* @stack: A pointer to the top node of the stack to free.
*/
void frees(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

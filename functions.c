#include "monty.h"
void _push(stack_t **stack, unsigned int line_number)
{
    stack_t *line = malloc(sizeof(stack_t));
    (void)line_number;
    
    if (!line)
    {
        fprint(stderr, "error que no me acuerdo");
        free(line);
        return (-1);
    }
    if(*stack)
        (*stack)->prev = line;
    line->n = 0;
    line->next = *stack;
    *stack = line;
}

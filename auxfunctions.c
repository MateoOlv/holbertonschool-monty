#include "monty.h"

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

void frees(stack_t **stack)
{
    stack_t *current, *next;

    if (!stack || !*stack)
    {
        return;
    }
    current = *stack;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}

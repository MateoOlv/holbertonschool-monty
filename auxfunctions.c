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
    }
    return (0);
}
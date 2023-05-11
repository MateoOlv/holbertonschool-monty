#include "monty.h"
void (*get_func(char *op))(stack_t **stack, unsigned int line_number)
{
	int i;

		instruction_t func[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
        {"pint", _swap},
        {"pint", _add},
        {"pint", _nop},
		{NULL, NULL}
	};
    for (i = 0; func[i].opcode != NULL; i++)
    {
        if (strcmp(func[i].opcode, op) == 0)
            return func[i].f;
    }
	exit(EXIT_FAILURE);
}
int main(int argc, char **argv)
{
    char *line = NULL, *token;
    size_t size = 0;
    ssize_t readline;
    FILE *arch;
    void (*f)(stack_t **stack, unsigned int line_number);
    int cont = 0;
    stack_t *stack = NULL;

    if(argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }
    arch = fopen(argv[1], "r");
    if (!arch)
    {
    fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
    return (EXIT_FAILURE);
    }
    while((readline = getline(&line, &size, arch)))
    {
        cont++;
        token = strtok(line, DELIM);
        if (!token)
        continue;
        f = get_func(token);
        if (!f)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", cont, token);
            return (EXIT_FAILURE);
        }
        f(&stack, cont);
    }
    fclose(arch);
    free(token);
    frees(stack);
    return(EXIT_SUCCESS);
}
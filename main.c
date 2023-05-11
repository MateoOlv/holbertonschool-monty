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
	void (*f)(stack_t **stack, unsigned int cont);
	char *buffer = NULL, *token = NULL;
	size_t bufsize = 0;
	stack_t *stack = NULL;
    FILE *file = NULL;
	int i = 0;

	if (argc != 2)
    {
		fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE); }
	file = fopen(argv[1], "r");
	if (!file)
		{
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE); }
	while (getline(&buffer, &bufsize, file) != -1)
	{
		i++;
		token = strtok(buffer, DELIM);
		if (!token)
			continue;
		f = get_func(token);
		if (!f)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", i, token);
			exit(EXIT_FAILURE);
		}
		f(&stack, i);
	}
	free(buffer);
	fclose(file);
    return(0);
}
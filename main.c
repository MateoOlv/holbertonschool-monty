#include "main.h"
int main(int argv, char args[])
{

}
int get_function(stack_t **stack)
{
    int i = 0;
    instruction_t func {
		{"pall", _pall},
		{"push", _push},
		{"pint", _pint},
		{"pop", _pop},
		{NULL, NULL}
	};
    	int i = 0;

	while (i < 4)
	{
		if (strcmp(s, func[i].opcode) == 0)
		{
			return (func[i].f);
		}
		i++;
	}
	printf("Error\n");
	exit(99);

}
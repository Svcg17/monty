#include "monty.h"

int getCoco(char *str, stack_t **stack, unsigned int line_number)
{
	size_t i;

	instruction_t ops[] = {
		{"add", _add},
		{"pint", _pint},
		{"pop", _pop},
		{"pall", _pall},
		{"swap", _swap},
		{"nop", _nop},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
		if (strcmp(ops[i].opcode, str) == 0)
		{
			ops[i].f(stack, line_number);
			return (1);
		}
	return (0);
}

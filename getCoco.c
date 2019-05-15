#include "monty.h"

int getCoco(char *str, stack_t **stack, unsigned int line_number)
{
	size_t i;

	instruction_t ops[] = {
//		{"push", _pErro}
		/*
		{"pop", _pop},
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"swap", _swap}
		{"add", _add},
		{"nop", _nop},*/
		{"pall", _pall},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
		if (strcmp(ops[i].opcode, str) == 0)
		{
			printf("Calling %s\n", ops[i].opcode);
			ops[i].f(stack, line_number);
			return (1);
		}
	return (0);
}

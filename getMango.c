#include "monty.h"

void (*get_line(char *str))(stack_t **stack, unsigned int line_number)
{
	size_t i;

	instruction_t ops[] = {
		{"pop", _pop},
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"swap", _swap}
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
		if (strcmp(ops[i].opcode, str))
			return (ops[i].f);
	return (NULL);
}

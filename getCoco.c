#include "monty.h"

/**
 *getCoco - checks for input and calls functions depending on the string
 *@str: The input name
 *@stack: The linked list
 *@lineN: Line number from input
 *Return: returns 1 If it's a success, else it returns 0
 */
int getCoco(char *str, stack_t **stack, unsigned int lineN)
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
			ops[i].f(stack, lineN);
			return (1);
		}
	if (ops[i].opcode == NULL)
	{
		fprintf(stderr, "L<%u>: unknown instruction <%s>\n", lineN, str);
		exit(EXIT_FAILURE);
	}
	return (0);
}

#include "monty.h"

int main(int argc, char **argv)
{
	stack_t *head;
	stack_t stack = {8, NULL, NULL};

	head = &stack;
	if (argc < 1)
		exit(9);
	if (read_input(argv[1], &head) == 0)
		printf("bad\n");
	return (0);
}

#include "monty.h"
/**
 * free_dstack - free a dstack_t list
 * @head: list to be freed.
 */
void free_dstack(stack_t *head)
{
	stack_t *t;

	while (head != NULL)
	{
		t = head;
		head = head->next;
		free(t);
	}
}

/**
 *main - takes arguments and opens a file
 *@argc: Argument count
 *@argv: A string of arguments
 *Return: returns exit success if all goes well
 */
int main(int argc, char **argv)
{
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (read_input(argv[1], &head) == 0)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	free_dstack(head);
	return (EXIT_SUCCESS);
}

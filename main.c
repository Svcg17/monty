#include "monty.h"

int main(void)
{

	char *buff = NULL;
	char *tokens;
	ssize_t n;
	size_t nLines, i;
	stack_t *head;


	head = NULL;
	nLines = 0;
	n = getline(&buff, 0, stdin);
	if (buff == NULL)
		exit(99);
	for (i = 0; buff[i] != NULL; i++)
		;
	if (i < 2)
	{
		exit(111);
	}
	tokens = strtok(buff, " \t");
	while (tokens != NULL)
	{
		(*get_line(tokens))(&head, nLines)
			continue;
		tokens = strtok(NULL, " \t");
		if (strcmp(tokens, "\n") == 0)
		{
			nLines++;
			continue;
		}
	}
	return (0);
}

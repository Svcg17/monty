#include "monty.h"

int read_input(char *input, stack_t **head)
{
	char *buff = NULL;
	size_t buff_size = 0;
	int line_count = 0;
	ssize_t line_size = 0;
	FILE *fp = NULL;

	fp = fopen("bytecodes/00.m", "r");
	if (fp == NULL)
	{
		printf("Bad reading\n");
		exit(101);
	}
	line_size = getline(&buff, &buff_size, fp);
	while (line_size >= 0)
	{
		line_count += 1;
		if (tokenize_input(buff, head, line_count) == 0)
			return (0);
		line_size = getline(&buff, &buff_size, fp);
	}
	free(buff);
	fclose(fp);
	return (1);
}


int tokenize_input(char *input, stack_t **head, unsigned int lineNum)
{
	char *tok, *num;
	int number;

	tok = strtok(input, " \t\n");
	num = strtok(NULL, " \t\n");
	if (strtok(NULL, " \t\n") != NULL)
	{
		printf("Something is wrong\n");
		return (0);
	}

	if (num != NULL && strcmp(tok, "push") == 0)
	{
		number = atoi(num);
		if (number != 0 || (strcmp(num, "0") == 0))
			_push(head, number);
		else
			printf("Error\n");
	}
	else if (tok != NULL)
	{
		printf("Calling Coco with tok: %s\n", tok);
		getCoco(tok, head, lineNum);
	}
	return (1);
}

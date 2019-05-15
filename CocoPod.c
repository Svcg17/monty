#include "monty.h"
#include <errno.h>
/**
 * read_input - opens and reads a file
 * @input: input from first command line argument
 * @head: pointer to the first node in the list
 * Return: 1 or 0
 */
int read_input(char *input, stack_t **head)
{
	char *buff = NULL;
	size_t buff_size = 0;
	int line_count = 0;
	ssize_t line_size = 0;
	FILE *fp = NULL;

	fp = fopen(input, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", input);
		exit(EXIT_FAILURE);
	}
	line_size = getline(&buff, &buff_size, fp);
	if (line_size < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", input);
		exit(EXIT_FAILURE);
	}
	while (line_size >= 0)
	{
		line_count += 1;
		tokenize_input(buff, head, line_count);
		line_size = getline(&buff, &buff_size, fp);
	}
	free(buff);
	fclose(fp);
	return (1);
}

/**
 * tokenize_input - tokenizes input read and checks for push
 * @input: input from first argument in command line.
 * @head: pointer to the first node of the list
 * @lineNum: number of lines
 * Return: 1 or 0
 */
int tokenize_input(char *input, stack_t **head, unsigned int lineNum)
{
	char *tok, *num;
	int number;

	tok = strtok(input, " \t\n");
	num = strtok(NULL, " \t\n");
	if (strtok(NULL, " \t\n") != NULL)
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	if (num != NULL && strcmp(tok, "push") == 0)
	{
		number = atoi(num);
		if (number != 0 || (strcmp(num, "0") == 0))
			_push(head, number);
		else
		{
			fprintf(stderr, "L<%d>: usage: push integer\n", lineNum);
			exit(EXIT_FAILURE);
		}
	}
	else if (num == NULL)
	{
		fprintf(stderr, "L<%u>: usage: push integer\n", lineNum);
		exit(EXIT_FAILURE);
	}
	else if (tok != NULL)
	{
		getCoco(tok, head, lineNum);
	}
	return (1);
}

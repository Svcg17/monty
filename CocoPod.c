#include "monty.h"
#include <errno.h>
/**
 * checkNum - checks if token passed is a number
 * @str: token
 * Return: 0 if there's a match
 */
int checkNum(char *str)
{
	size_t i;

	for (i = str[0] == '-' ? 1 : 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
/**
 * read_input - opens and reads a file
 * @input: input from first command line argument
 * @head: pointer to the first node in the list
 * Return: 1 or 0
 */
int read_input(char *input, stack_t **head)
{
	char *buff = NULL;
	int ret;
	size_t buff_size = 0;
	int line_count = 0;
	ssize_t line_size = 0;
	FILE *fp = NULL;

	ret = 0;
	fp = fopen(input, "r");
	if (fp == NULL)
		print_errors(1, input, 0, *head);
	line_size = getline(&buff, &buff_size, fp);
	if (line_size == -1)
	{
		free(buff);
		fclose(fp);
		print_errors(1, NULL, line_count, *head);
	}
	while (line_size >= 0)
	{
		line_count += 1;
		ret = tokenize_input(buff, head, line_count);
		if (ret == -1)
		{
			free(buff);
			fclose(fp);
			print_errors(2, NULL, line_count, *head);
		}
		else if (ret == -2)
		{
			free(buff);
			fclose(fp);
			print_errors(7, buff, line_count, *head);
		}
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
	if (tok == NULL)
		return (1);
	if (num != NULL && strcmp(tok, "push") == 0)
	{
		if (!checkNum(num))
		{
			return (-1);
		}
		number = atoi(num);
		if (number != 0 || (strcmp(num, "0") == 0))
			_push(head, number);
		else
			return (-1);
	}
	else if (num == NULL && strcmp(tok, "push") == 0)
	{
		return (-1);
	}
	else if (tok != NULL)
	{
		if (getCoco(tok, head, lineNum) == -1)
			return (-2);
	}
	return (1);
}

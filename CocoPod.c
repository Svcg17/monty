#include "monty.h"
#include <ctype.h>
#include <errno.h>

/**
 *isComt - Checks if string is a comment
 *@str: The string to check for #
 *Return: returns 1 if str is a comment, else returns 0
 */
int isComt(char *str)
{
	size_t i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isspace(str[i]))
			continue;
		if (str[i] == '#')
			return (1);
		else
			return (0);
	}
	return (0);
}

/**
 *closePoint - Closes and free pointers from memory
 *@fp: The File pointer
 *@buff: The allocated string from getline
 */
void closePoint(FILE *fp, char *buff)
{
	fclose(fp);
	free(buff);
}

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
	int ret = 0;
	size_t buff_size = 0;
	int line_count = 0;
	ssize_t line_size = 0;
	FILE *fp = NULL;

	fp = fopen(input, "r");
	if (fp == NULL)
		print_errors(1, input, 0, *head);
	line_size = getline(&buff, &buff_size, fp);
	if (line_size == -1)
	{
		closePoint(fp, buff);
		print_errors(1, NULL, line_count, *head);
	}
	while (line_size >= 0)
	{
		if (isComt(buff) == 1)
		{
			line_size = getline(&buff, &buff_size, fp);
			continue;
		}
		line_count += 1;
		ret = tokenize_input(buff, head, line_count);
		if (ret == -1)
		{
			closePoint(fp, buff);
			print_errors(2, NULL, line_count, *head);
		}
		else if (ret == -2)
		{
			closePoint(fp, buff);
			exit(EXIT_FAILURE);
		}
		line_size = getline(&buff, &buff_size, fp);
	}
	closePoint(fp, buff);
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
			return (-1);
		number = atoi(num);
			_push(head, number);
	}
	else if (num == NULL && strcmp(tok, "push") == 0)
	{
		return (-1);
	}
	else if (tok != NULL)
	{
		if (getCoco(tok, head, lineNum) == -1)
		{
			print_errors(7, tok, lineNum, *head);
			return (-2);
		}
	}
	return (1);
}

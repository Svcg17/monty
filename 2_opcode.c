#include "monty.h"
/**
 * _pop - removes the top element of the stack.
 * @head: pointer to the first node of a list.
 * @lineN: number of lines.
 */
void _pop(stack_t **head, unsigned int lineN)
{
	stack_t *temp = NULL;

	if (*head == NULL)
		print_errors(6, NULL, lineN, NULL);
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
/**
 * _swap - swaps the top two elements of the stack.
 * @head: pointer to the first node of the list.
 * @lineN: line number
 */
void _swap(stack_t **head, unsigned int lineN)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
		print_errors(5, NULL, lineN, NULL);
	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}
/**
 * _nop - doesn't do anything
 * @head: pointer to the first node of the list
 * @lineN: number of lines
 */
void _nop(stack_t **head, unsigned int lineN)
{
	(void)(head);
	(void)(lineN);
}
/**
 * print_errors - function that prints an error depending of given integer
 * @error: integer that matches with error msg
 * @str: string to string to pass to error msg
 * @line: int to pass to error msg
 * @head: pointer to stack
 */
void print_errors(int error, char *str, unsigned int line, stack_t *head)
{
	if (head != NULL)
		free_dstack(head);

	if (error == 0)
		fprintf(stderr, "USAGE: monty file\n");
	if (error == 1)
		fprintf(stderr, "Error: Can't open file %s\n", str);
	else if (error == 2)
		fprintf(stderr, "L%d: usage: push integer\n", line);
	else if (error == 3)
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
	else if (error == 4)
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
	else if (error == 5)
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
	else if (error == 6)
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
	else if (error == 7)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, str);
		return;
	}
	exit(EXIT_FAILURE);
}

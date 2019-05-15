#include "monty.h"
/**
 * _push - pushes an element to the stack
 * @head: pointer to the first node of the list
 * @num: integer to push
 */
void _push(stack_t **head, int num)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (head == NULL || new == NULL)
		return;
	new->n = num;
	new->prev = NULL;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return;
	}
	(*head)->prev = new;
	new->next = *head;
	*head = new;
}
/**
 * _pall - prints all the values on the stack
 * @head: pointer to the first node of the list
 * @lineN: number of lines
 */
void _pall(stack_t **head, unsigned int lineN)
{
	stack_t *temp = *head;

	while (temp != NULL)
	{
		printf("%d\n", (temp)->n);
		temp = temp->next;
	}
	lineN = lineN;
}
/**
 * _pint - prints the value at the top of the stack
 * @head: pointer to the first node of the list
 * @lineN: number of  lines.
 */
void _pint (stack_t **head, unsigned int lineN)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", lineN);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*head)->n);
}

/**
 * _add - adds the top two elements of the stack
 * @head: pointer to the first node of the list
 * @lineN: number of lines
 */
void _add(stack_t **head, unsigned int lineN)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't swap, stack too short\n", lineN);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->n;
	_pop(head, lineN);
	(*head)->n = (*head)->n + temp;
}

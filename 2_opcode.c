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
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", lineN);
		exit(EXIT_FAILURE);
	}
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
	{
		fprintf(stderr, "L<%d>: can't swap, stack too short\n", lineN);
		exit(EXIT_FAILURE);
	}
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

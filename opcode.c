#include "monty.h"
void _push (stack_t **head, int num)
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

void _pall (stack_t **head, unsigned int lineN)
{
	stack_t *temp = *head;
	while (temp != NULL)
	{
		printf("%d\n", (temp)->n);
		temp = temp->next;
	}
	lineN = lineN;
}

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

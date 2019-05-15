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
	}
	(*head)->prev = new;
	new->next = *head;
	*head = new;
}

void _pall (stack_t **head, unsigned int lineN)
{
	printf("Here\n");
	while (*head != NULL)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
	}
}

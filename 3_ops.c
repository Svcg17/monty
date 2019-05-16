#include "monty.h"

/**
 *_sub - subtracts the top two nodes into one
 *@head: The linked list
 *@lineN: The line number that this command occured
 */
void _sub(stack_t **head, unsigned int lineN)
{
	int temp;

	if (*head == NULL || ((*head)->prev == NULL && (*head)->next == NULL))
		print_errors(8, NULL, lineN, *head);
	temp = (*head)->n;
	_pop(head, lineN);
	(*head)->n = (*head)->n - temp;
}

/**
 *_div - divides the top two nodes into one
 *@head: The linked list
 *@lineN: The line number for this command
 */
void _div(stack_t **head, unsigned int lineN)
{
	int temp;

	if (*head == NULL || ((*head)->prev == NULL && (*head)->next == NULL))
		print_errors(9, NULL, lineN, *head);
	temp = (*head)->n;
	if (temp == 0)
		print_errors(10, NULL, lineN, *head);
	_pop(head, lineN);
	(*head)->n = (*head)->n / temp;
}

/**
 *_mul - Multiplies the top two nodes into one
 *@head: The linked list
 *@lineN: The line number this command was given
 */
void _mul(stack_t **head, unsigned int lineN)
{
	int temp;

	if (*head == NULL || ((*head)->prev == NULL && (*head)->next == NULL))
		print_errors(11, NULL, lineN, *head);
	temp = (*head)->n;
	_pop(head, lineN);
	(*head)->n = (*head)->n * temp;
}

/**
 *_mod - Uses module to recive the remainder of the top two nodes into one
 *@head: The linked list
 *@lineN: The line number this command was given
 */
void _mod(stack_t **head, unsigned int lineN)
{
	int temp;

	if (*head == NULL || ((*head)->prev == NULL && (*head)->next == NULL))
		print_errors(12, NULL, lineN, *head);
	temp = (*head)->n;
	if (temp == 0)
		print_errors(13, NULL, lineN, *head);
	_pop(head, lineN);
	(*head)->n = (*head)->n % temp;
}

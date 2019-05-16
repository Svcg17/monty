#ifndef __MONTY__
#define __MONTY__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void _push(stack_t **head, int value);
int tokenize_input(char *str, stack_t **head, unsigned int line_num);
int getCoco(char *str, stack_t **stack, unsigned int line_number);
int read_input(char *input, stack_t **head);
void _pall(stack_t **head, unsigned int lineN);
void _pint(stack_t **head, unsigned int lineN);
void _pop(stack_t **head, unsigned int lineN);
void _swap(stack_t **head, unsigned int lineN);
void _add(stack_t **head, unsigned int lineN);
void print_errors(int error, char *str, unsigned int line, stack_t *head);
void free_dstack(stack_t *head);
void _nop(stack_t **head, unsigned int lineN);
void _sub(stack_t **head, unsigned int lineN);
void _div(stack_t **head, unsigned int lineN);
void _mul(stack_t **head, unsigned int lineN);
void _mod(stack_t **head, unsigned int lineN);
void closePoint(FILE *fp, char *buff);

#endif

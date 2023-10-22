#include "monty.h"

/**
 * push - Pushes an integer onto the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode is executed
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *arg;
	int push_arg;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		printf("Error: malloc failed\n");
		error_exit(stack);
	}

	arg = strtok(NULL, "\n ");
	if (arg != NULL && isdigit(arg))
	{
		push_arg = atoi(arg);
	}
	else
	{
		printf("line %d: usage: push integer\n", line_number);
		error_exit(stack);
	}

	new_node->n = push_arg;
	new_node->prev = NULL;

	if (queueMode == 1)
	{
		new_node->next = NULL;
		if (*stack != NULL)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
}

/**
 * pall - Prints all elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode is executed
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *current_node = *stack;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

/**
 * pint - Prints the integer at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode is executed
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("line %d: can't pint, stack empty\n", line_number);
		error_exit(stack);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode is executed
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("line %d: can't swap, stack too short\n", line_number);
		error_exit(stack);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * pop - Deletes the top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode is executed
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_node;

	if (*stack == NULL)
	{
		printf("line %d: can't pop an empty stack\n", line_number);
		error_exit(stack);
	}

	temp_node = (*stack)->next;
	free(*stack);
	*stack = temp_node;
}

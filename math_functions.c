#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode occurs
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("line %d: can't add, stack too short\n", line_number);
		error_exit(stack);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * sub - Subtracts the top element from the second top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode occurs
 */

void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("line %d: can't sub, stack too short\n", line_number);
		error_exit(stack);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - Multiplies the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode occurs
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("line %d: can't mul, stack too short\n", line_number);
		error_exit(stack);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _div - Divides the second top element by the top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode occurs
 */

void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("line %d: can't div, stack too short\n", line_number);
		error_exit(stack);
	}

	if ((*stack)->n == 0)
	{
		printf("line %d: division by zero\n", line_number);
		error_exit(stack);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - Computes the modulus of the second top
 * element by the top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode occurs
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("line %d: can't mod, stack too short\n", line_number);
		error_exit(stack);
	}

	if ((*stack)->n == 0)
	{
		printf("line %d: division by zero\n", line_number);
		error_exit(stack);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

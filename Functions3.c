#include "monty.h"

/**
 * error_exit - frees the stack and exits
 * @stack: pointer to the stack
 */

void error_exit(stack_t **stack)
{
	free_list(*stack);
	exit(EXIT_FAILURE);
}

/**
 * isDigit - Checks if the given string is digit
 * @str: String that passed to function
 * Return: 1 if string is a digit, 0 otherwise
 */

int isDigit(char *str)
{
    unsigned int i;

    if (str == NULL)
        return (0);

    for (i = 0; str[i]; i++)
    {
        if (str[0] == '-' && i == 0)
            continue;
        if (!isdigit(str[i]))
            return (0);
    }
    return (1);
}

/**
 * _rotl - Rotates the list to the left
 * @stack: Pointer to the stack
 * @line_number: The current line
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
    stack_t *last_node;
    int first_node_value;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    last_node = *stack;
    while (last_node->next)
		last_node = last_node->next;

    first_node_value = (*stack)->n;
    (*stack)->n = last_node->n;
    last_node->n = first_node_value;
}

/**
 * _rotr - Rotates the list to the right
 * @stack: Pointer of the stack
 * @line_number: The current line
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
    stack_t *last_node;
    int first_node_value;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    last_node = *stack;
    while (last_node->next)
        last_node = last_node->next;

    first_node_value = (*stack)->n;
    (*stack)->n = last_node->n;
    last_node->n = first_node_value;
}

#include "monty.h"

/**
 * add_node_to_start - Adds a node to the start of the list
 * @head: Pointer to the first node
 * @n: Node data
 * Return: Pointer to the first node
 */
stack_t *add_node_to_start(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = (*head == NULL) ? NULL : *head;
	new_node->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;

	return (*head);
}

/**
 * delete_node_at_index - Deletes a node at a specific index
 * @head: Pointer to the first node on list
 * @index: Position to delete
 * Return: 1 if successful, -1 if failure
 */
int delete_node_at_index(stack_t **head, unsigned int index)
{
	stack_t *current_node;
	stack_t *next_node;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	current_node = *head;

	if (index == 0)
	{
		*head = current_node->next;
		if (current_node->next != NULL)
			current_node->next->prev = NULL;
		free(current_node);
		return (1);
	}

	for (i = 0; i < index - 1; i++)
	{
		if (current_node == NULL)
			return (-1);
		current_node = current_node->next;
	}

	next_node = current_node->next->next;
	if (current_node->next->next != NULL)
		current_node->next->next->prev = current_node;
	free(current_node->next);
	current_node->next = next_node;

	return (1);
}

/**
 * add_node_to_end - Adds a node to the end of the list
 * @head: Pointer to the first node
 * @n: Node data
 * Return: Pointer to the first node
 */
stack_t *add_node_to_end(stack_t **head, const int n)
{
	stack_t *current_node;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		current_node = *head;
		while (current_node->next != NULL)
			current_node = current_node->next;

		current_node->next = new_node;
		new_node->prev = current_node;
	}

	return (new_node);
}

/**
 * free_list - Frees a list
 * @head: Pointer to the first node
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

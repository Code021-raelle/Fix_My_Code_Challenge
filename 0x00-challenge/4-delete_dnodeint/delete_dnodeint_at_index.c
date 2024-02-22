#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int count;

	if (*head == NULL)
	{
		return (-1);
	}

	current = *head;
	count = 0;
	while (current != NULL && count < index)
	{
		current = current->next;
		count++;
	}

	if (current == NULL)
	{
		return (-1);
	}

	if (current->prev != NULL)
	{
		current->prev->next = current->next;
	}
	if (current->next != NULL)
	{
		current->next->prev = current->prev;
	}

	if (current == *head)
	{
		*head = current->next;
	}

	free(current);
	return (1);
}


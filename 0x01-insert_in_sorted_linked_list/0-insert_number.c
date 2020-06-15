#include <stdlib.h>
#include "lists.h"

/**
 * add_node - inserts a number into a sorted singly linked list.
 * @head: pointer to pointer
 * @num: integer
 * Return: new node
 * 
 */

listint_t *insert_node(listint_t **head, int num)
{
	listint_t *new, *crt;

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = num;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	
	for (crt = *head; crt != NULL; crt = crt->next)
		{
			if (crt == *head)
			{
				if (num < crt->n)
				{
					new->next = *head;
					*head = new;
					return (*head);
				}
			}
			else if (crt->next == NULL)
			{
				crt->next = new;
				return (*head);
			}

			if (num < crt->next->n)
			{
				new->next = crt->next;
				crt->next = new;
				return (*head);
			}
		}
	return (NULL);
}

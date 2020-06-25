#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - is or not linked list is palindorme
 * @head: pointer to pointer
 * Return: 0 if is palinfrome, 1 if not
 */

int is_palindrome(listint_t **head)
{
	int one = 0, two = 0;
	listint_t *move = *head;
	int array[1000000];

	if (*head == NULL)
		return (1);
	if (head == NULL)
		return (0);

	while (move != NULL)
	{
		array[one++] = move->n;
		move = move->next;
	}

	while (two < one)
	{
		if (array[two] != array[one - 1 - two])
			return (0);
		two++;
	}
	return (1);
}

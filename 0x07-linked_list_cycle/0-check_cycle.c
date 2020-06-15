#include "lists.h"
/**
 * check_cycle - check cycle list
 * @list: pointer of list
 * Return: 1 cycle or 0 no cycle
 *
 */

int check_cycle(listint_t *list)
{
	listint_t *mov1 = list, *mov2= list->next;

	if (list == NULL)
		return (0);
	
	while (mov2 != NULL && mov2->next != NULL && mov1 != NULL)
	{
		if (mov1 == mov2)
			return (1);
		
		mov1 = mov1->next;
		mov2 = mov2->next->next;
	}
	return (0);
}

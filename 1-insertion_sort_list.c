#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of the intgers
 * in ascending order using the insertion sort algorithm
 * @list: the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *temp, *next, *temp_next, *temp_prev;

	if (list == NULL || (*list)->next == NULL)
		return;
	ptr = *list;
	ptr = ptr->next;
	while (ptr)
	{
		temp = ptr;
		next = ptr->next;
		temp_next = temp->next;
		temp_prev = temp->prev;

		while (temp->prev && temp_prev->n > temp->n)
		{
			if (temp_next != NULL)
			{
				temp_next->prev = temp_prev;
			}
			temp_prev->next = temp_next;
			if (temp_prev->prev == NULL)
			{
				temp_prev->prev = temp;
				*list = temp;
				temp->prev = NULL;
			}
			else
			{
				temp->prev = temp_prev->prev;
				temp_prev->prev->next = temp;
				temp_prev->prev = temp;
			}
			temp->next = temp_prev;
			temp_prev = temp->prev;
			temp_next = temp->next;
			print_list(*list);
		}
		ptr = next;
	}

}

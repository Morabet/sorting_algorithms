#include "sort.h"

/**
 * swap_nodes_ahead - swap two nodes in doubly linked list
 * @list: pointer to the head of the list
 * @end: pointer to the tail of the list
 * @node: the node to swap with (node)->next
 * Return: void
 */
void swap_nodes_ahead(listint_t **list, listint_t **end, listint_t **node)
{
	listint_t *c, *t;

	c = *node;
	t = (*node)->next;

	c->next = t->next;
	t->prev = c->prev;

	if (c->prev)
		c->prev->next = t;
	else
		*list = t;

	if (t->next)
		t->next->prev = c;
	else
		*end = c;

	c->prev = t;
	t->next = c;

	c = t;
}

/**
 * swap_nodes_behind - swap two nodes in doubly linked list
 * @list: pointer to the head of the list
 * @end: pointer to the tail of the list
 * @node: the node to swap with (node)->prev
 * Return: void
 */
void swap_nodes_behind(listint_t **list, listint_t **end, listint_t **node)
{
	listint_t *c, *t;

	c = *node;
	t = (*node)->prev;

	t->next = c->next;
	c->prev = t->prev;

	if (t->prev)
		t->prev->next = c;
	else
		*list = c;

	if (c->next)
		c->next->prev = t;
	else
		*end = t;

	t->prev = c;
	c->next = t;

	c = t;
}

/**
 * cocktail_sort_list - Cocktail shaker sort algorithm
 * @list: pointer to head list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *end, *beg;
	bool sorted = false;

	if (!list)
		return;

	current = *list;
	while (current->next)
		current = current->next;

	end = current;
	beg = *list;
	while (sorted == false)
	{
		sorted = true;
		current = beg;
		while (current != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes_ahead(list, &end, &current);
				sorted = false;
				print_list(*list);
				continue;
			}
			current = current->next;
		}
		current = current->prev;
		while (current != beg && current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes_behind(list, &end, &current);
				sorted = false;
				print_list(*list);
				continue;
			}
			current = current->prev;
		}
	}
}

#include "sort.h"
/**
* insertion_sort_list - insertion sort algoritm
* @list: pointer to doubly linked list
* Return: nothing
*/
void insertion_sort_list(listint_t **list)
{
listint_t *head, *next_node, *prev_node, *current;

if (!list || !*list)
	exit(1);
head = *list;
while ((*list)->next)
{
	if ((*list)->n > (*list)->next->n)
	{
		current = *list;
		next_node = (*list)->next;
		prev_node = (*list)->prev;
		if (next_node->next == NULL && prev_node != NULL)
		{
			swap_end(current, next_node, prev_node);
			*list = head;
		}
		else if (prev_node == NULL)
		{
			swap_head(current, next_node);
			head = next_node;
			*list = head;
		}
		else
		{
			prev_node->next = next_node;
			next_node->prev = prev_node;
			next_node->next->prev = current;
			current->next = next_node->next;
			next_node->next = current;
			current->prev = next_node;
			*list = head;
		}
		print_list(*list);
	}
	else
		*list = (*list)->next;
}
*list = head;
}
/**
 * swap_end - swap last nodes
 * @c: current node
 * @n: next node
 * @p: previous node
 * Return: nothing
*/
void swap_end(listint_t *c, listint_t *n, listint_t *p)
{
p->next = n;
n->prev = p;
c->next = NULL;
n->next = c;
c->prev = n;
}
/**
 * swap_head - swap last nodes
 * @c: current node
 * @n: next node
 * Return: nothing
*/
void swap_head(listint_t *c, listint_t *n)
{

if (n->next == NULL)
{
	n->prev = NULL;
	c->next = NULL;
	n->next = c;
	c->prev = n;
}
else
{
	n->prev = NULL;
	n->next->prev = c;
	c->next = n->next;
	n->next = c;
	c->prev = n;
}
}

#include "list.h"
#include <stdlib.h>

listT *createList()
{
	listT *list;
	list = (listT*)malloc(sizeof(listT));
	list->head = NULL;
	return list;
}

void addFirst(listT *list, trio data)
{
	node3 *node;
	node = (node3*)malloc(sizeof(node3));
	node->data = data;
	node->next = list->head;
	list->head = node;
}

void freeList(listT *list)
{
	node3 *node;
	node = list->head;
	while (list->head)
	{
		list->head = node->next;
		free(node);
		node = list->head;
	}
	free(node);
	free(list);
}

void printList(listT *list)
{
	node3 *node;
	if (list->head)
	{
		node = list->head;
		while (node->next)
		{
			printf("sum: %d\ti: %d\tj: %d\n", node->data.sum, node->data.i, node->data.j);
			node = node->next;
		} 
		printf("sum: %d\ti: %d\tj: %d\n", node->data.sum, node->data.i, node->data.j);
	}
}
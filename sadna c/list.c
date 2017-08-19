#include "list.h"
#include <stdlib.h>

listT *newList()
{
	listT *list;
	list = (listT*)malloc(sizeof(listT));
	list->head = NULL;
	return list;
}

void addFirst3(listT *list, trio data)
{
	node3 *node;
	node = (node3*)malloc(sizeof(node3));
	node->data = data;
	node->next = list->head;
	list->head = node;
}

void freeList3(listT *list)
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

void printList3(listT *list)
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

void addFirst(listT *list, int x)
{
	nodeT *node;
	node = (nodeT*)malloc(sizeof(nodeT));
	node->next = list->head;
	node->data = x;
	list->head = node;
}

void freeList(listT *list)
{
	nodeT *node;
	node = list->head;
	while (list->head)
	{
		list->head = node->next;
		free(node);
		node = list->head;
	}
}

void printList(listT *list)
{
	nodeT *node;
	listT temp;
	if (list->head == NULL)
		printf("the list is empty");

	node = list->head;
	temp.head = list->head;
	while (temp.head)
	{
		temp.head = node->next;
		printf("%d, ", node->data);
		node = temp.head;
	}
}

void freeSingle(listT *list, nodeT *node)
{
	nodeT temp;
	if (node->next == NULL)
	{
		list->head = NULL;
		return;
	}
	temp.next = node->next;
	node->data = node->next->data;
	node->next = node->next->next;
	free(temp.next);
}

void freeLast(nodeT *node)
{
	free(node->next);
	node->next = NULL;
}

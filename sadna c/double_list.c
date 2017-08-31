#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

doubleList *newDoubleList()
{
	doubleList *list;
	list = (doubleList*)malloc(sizeof(doubleList));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

void dlistInsertFirst(doubleList *list, int x)
{
	nodeDL *node;
	node = (nodeDL*)malloc(sizeof(nodeDL));
	node->data = x;
	if (list->size == 0)
		list->tail = node;
	else
		list->head->prev = node;
	node->next = list->head;
	node->prev = NULL;
	list->head = node;
	list->size++;
}

void dlistInsertLast(doubleList *list, int x)
{
	nodeDL *node;
	node = (nodeDL*)malloc(sizeof(nodeDL));
	node->data = x;
	if (list->size == 0)
		list->head = node;
	else
		list->tail->next = node;
	node->next = NULL;
	node->prev = list->tail;
	list->tail = node;
	list->size++;
}

void dlistPrintFwd(doubleList *list)
{
	int i;
	nodeDL *node;
	if (list->size == 0)
	{
		printf("The list is empty\n");
		return;
	}
	node = list->head;
	for (i = 1;i <= list->size;i++)
	{
		printf("Node %d is %d\n", i, node->data);
		node = node->next;
	}
}

void dlistPrintBck(doubleList *list)
{
	int i;
	nodeDL *node;
	if (list->size == 0)
	{
		printf("The list is empty\n");
		return;
	}
	node = list->tail;
	for (i = list->size;i > 0;i--)
	{
		printf("Node %d is %d\n", i, node->data);
		node = node->prev;
	}
}

void dlistDeleteSingle(doubleList *list, nodeDL *node)
{
	if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else if (node->prev == NULL)
	{
		list->head = node->next;
		node->next->prev = node->prev;
	}
	else if (node->next = NULL)
	{
		list->tail = node->prev;
		node->prev->next = node->next;
	}
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
	list->size--;
	free(node);
}

void dlistFree(doubleList *list)
{
	nodeDL *node;
	node = list->head;
	while (list->size) //free every single node
	{
		list->head = node->next;
		free(node);
		node = list->head;
		list->size--;
	}
	free(list); //free the list header
}
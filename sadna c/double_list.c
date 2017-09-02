#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

polynomial *newPolynomial()
{
	polynomial *list;
	list = (polynomial*)malloc(sizeof(polynomial));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

void polyInsertFirst(polynomial *list, int num, int pow)
{
	nodeDL *node;
	node = (nodeDL*)malloc(sizeof(nodeDL));
	node->num = num;
	node->pow = pow;
	if (list->size == 0)
		list->tail = node;
	else
		list->head->prev = node;
	node->next = list->head;
	node->prev = NULL;
	list->head = node;
	list->size++;
}

void polyInsertLast(polynomial *list, int num, int pow)
{
	nodeDL *node;
	node = (nodeDL*)malloc(sizeof(nodeDL));
	node->num = num;
	node->pow = pow;
	if (list->size == 0)
		list->head = node;
	else
		list->tail->next = node;
	node->next = NULL;
	node->prev = list->tail;
	list->tail = node;
	list->size++;
}

void polyPrintFwd(polynomial *list)
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
		if (node->pow == 0)
			printf("%d", node->num);
		else if (node->pow == 1)
			if (node->num == 1)
				printf("X");
			else
				printf("%dX", node->num);
		else
			printf("%dX^%d", node->num, node->pow);
		node = node->next;
	}
}

void polyPrintBck(polynomial *list)
{
	int i;
	nodeDL *node;
	if (list->size == 0)
	{
		printf("Zero (empty polynomal)\n");
		return;
	}
	node = list->tail;

	for (i = list->size; i > 0; i--)
	{
		if (node->pow == 0)
		{
			if (i < list->size  && node->num > 0)
				printf("+%d", node->num);
			else
				printf("%d", node->num);
		}
		else if (node->pow == 1)
		{
			if (i < list->size && node->num == 1)
				printf("+X");
			else if (node->num == -1)
				printf("-X");
			else if (i < list->size && node->num > 1)
				printf("+%dX", node->num);
			else
				printf("%dX", node->num);
		}
		else
		{
			if (i < list->size && node->num == 1)
				printf("+X^%d", node->pow);
			else if (node->num == -1)
				printf("-X^%d", node->pow);
			else if (i < list->size && node->num > 1)
				printf("+%dX^%d", node->num, node->pow);
			else
				printf("%dX^%d", node->num, node->pow);
		}
		node = node->prev;
	}
}

void polyDeleteSingle(polynomial *list, nodeDL *node)
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
	else if (node->next == NULL)
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

void freePoly(polynomial *list)
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
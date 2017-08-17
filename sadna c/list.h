#pragma once

typedef struct
{
	int sum;
	int i;
	int j;
}trio;

typedef struct list
{
	struct list *head;
}listT;

typedef struct node
{
	trio data;
	struct node *next;
}node3;



listT *createList();

void addFirst(listT *list, trio data);

void freeList(listT *list);

void printList(listT *list);
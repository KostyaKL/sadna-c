#pragma once

typedef struct list
{
	struct list *head;
}listT;

typedef struct node
{
	int sum;
	int i;
	int j;
	struct node *next;
}node3;

listT *createList();

void addFirst(listT *list, int sum, int i, int j);

void freeList(listT *list);

void printList(listT *list);
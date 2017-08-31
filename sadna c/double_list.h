#pragma once

typedef struct nodedl
{
	int data;
	struct nodedl *next;
	struct nodedl *prev;
}nodeDL;

typedef struct
{
	nodeDL *head;
	nodeDL *tail;
	int size;
}doubleList;

doubleList *newDoubleList();

void dlistInsertFirst(doubleList *list, int x);

void dlistInsertLast(doubleList *list, int x);

void dlistPrintFwd(doubleList *list);

void dlistPrintBck(doubleList *list);

void dlistDeleteSingle(doubleList *list, nodeDL *node);

void dlistFree(doubleList *list);
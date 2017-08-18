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

typedef struct node_3
{
	trio data;
	struct node_3 *next;
}node3;

typedef struct node_t
{
	int data;
	struct node_t *next;
}nodeT;



listT *newList();

void addFirst3(listT *list, trio data);

void freeList3(listT *list);

void printList3(listT *list);

void addFirst(listT *list, int x);

void freeList(listT *list);

void printList(listT *list);

void freeSingle(listT *list, nodeT *node);

void freeLast(listT *list, nodeT *node);
#pragma once

typedef struct //define type trio
{
	int sum;
	int i;
	int j;
}trio;

typedef struct list //define type listT for list header
{
	struct list *head;
}listT;

typedef struct node_3 //define type node3 for node of list of 'trio' type itms
{
	trio data;
	struct node_3 *next;
}node3;

typedef struct node_t //define type nodeT for node of list of integers
{
	int data;
	struct node_t *next;
}nodeT;



listT *newList(); //function to create a new empty list

void addFirst3(listT *list, trio data); //function to add first node to list of 'trio'

void freeList3(listT *list); //function to free the memory was allocated for list of 'trio'

void printList3(listT *list); //function to print a list of 'trio'

void addFirst(listT *list, int x); //function to add first node to list of integers

void freeList(listT *list); //function to free a list of integers

void printList(listT *list); //function to print a list of integers

void freeSingle(listT *list, nodeT *node); //functin to remove a single node from list of integers

void freeLast(nodeT *node); //function to remove the last node in a list of integers
/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Roi Zimon 61108-61
Targil: Ester Amiti 661108-65/69
*/

#include "list.h"
#include <stdlib.h>

listT *newList() //function to create a new empty list
{
	listT *list;
	list = (listT*)malloc(sizeof(listT)); //alocate memory for the list header
	list->head = NULL;
	return list; //return the list address
}

void addFirst3(listT *list, trio data) //function to add a first node to a list of 'trio'
{
	node3 *node;
	node = (node3*)malloc(sizeof(node3)); //allocate memory for the new node
	node->data = data;
	node->next = list->head;
	list->head = node;
}

void freeList3(listT *list) //function to free the memory was alocated to list of 'trio'
{
	node3 *node;
	node = list->head;
	while (list->head) //free every single node
	{
		list->head = node->next;
		free(node);
		node = list->head;
	}
	free(node);
	free(list); //free the list header
}

void printList3(listT *list) //function to print a list of 'trio'
{
	node3 *node;
	if (list->head)
	{
		node = list->head;
		while (node->next) //print every single node
		{
			printf("sum: %d\ti: %d\tj: %d\n", node->data.sum, node->data.i, node->data.j);
			node = node->next;
		} 
		printf("sum: %d\ti: %d\tj: %d\n", node->data.sum, node->data.i, node->data.j);
	}
	else
		printf("the list is empty");
}

void addFirst(listT *list, int x) //function to add a first node to list of integers
{
	nodeT *node;
	node = (nodeT*)malloc(sizeof(nodeT)); //allocate memory for the new node
	node->next = list->head;
	node->data = x;
	list->head = node;
}

void freeList(listT *list) //free a list of integers
{
	nodeT *node;
	node = list->head;
	while (list->head) //free every single node
	{
		list->head = node->next;
		free(node);
		node = list->head;
	}
	free(node);
	free(list); //free the list header
}

void printList(listT *list) //print a list of integers
{
	nodeT *node;
	listT temp;
	if (list->head == NULL)
		printf("the list is empty");

	node = list->head;
	temp.head = list->head;
	while (temp.head) //print every single node
	{
		temp.head = node->next;
		printf("%d, ", node->data);
		node = temp.head;
	}
}

void freeSingle(listT *list, nodeT *node) //remove a single node fron list
{
	nodeT temp;
	if (node->next == NULL) //if there is only one node then free it and return an empty list
	{
		list->head = NULL;
		free(node);
		return;
	}

	//otherwise move the data of the next node to the current node and free the next node
	temp.next = node->next;
	node->data = node->next->data;
	node->next = node->next->next;
	free(temp.next);
}

void freeLast(nodeT *node) //remove the last node from list
{
	free(node->next);//free the last node and point the current node to NULL
	node->next = NULL;
}

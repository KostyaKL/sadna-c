/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Costa Mirkin 61104-62
Targil: Shimon Aviram 661104-61 / Lior Levi 661104-63
*/

#include "dlist_b.h"

///////////////////////////////////////////////////////////////

bstList *newBSTlist() { //function to create a new list
	bstList *list;
	list = (bstList*)malloc(sizeof(bstList)); //allocate memmory for new list
	list->head = NULL; //zeroize the values
	list->tail = NULL;
	list->size = 0;
	return list; //return list address
}

///////////////////////////////////////////////////////////////

void insertBSTlistLast(bstList *list, bstNodeT *item) { //function to insert item in the end of the list
	nodeBSTlist *last;
	last = (nodeBSTlist*)malloc(sizeof(nodeBSTlist)); //allocate mammory for a new node
	last->item = item; //insert the data to the node
	if (!list->size) { //if list is empty
		list->head = last; //head of list is the new node
	}
	else {
		list->tail->next = last; //tail of list is the new node
	}
	last->next = NULL; //the new node is the last one
	last->prev = list->tail; //the prev tail pointing to the new node
	list->tail = last; //tail of list is the new node
	list->size++; //increase the size of list by one
}

///////////////////////////////////////////////////////////////

void insertBSTlistFirst(bstList *list, bstNodeT *item) { //function to insert item in the beginning of the list
	nodeBSTlist *first;
	first = (nodeBSTlist*)malloc(sizeof(nodeBSTlist)); //allocate mammory for a new node
	first->item = item; //insert the data to the node
	if (!list->size) { //if list is empty
		list->tail = first; //tail of list is the new node
	}
	else {
		list->head->prev = first; //head of list is the new node
	}
	first->prev = NULL; //the new node is the first one
	first->next = list->head; //the prev head pointing to the new node
	list->head = first; //head of list is the new node
	list->size++; //increase the size of list by one
}

///////////////////////////////////////////////////////////////

void deleteFirstBSTlist(bstList *list) { //function to delete the first item in the list
	nodeBSTlist *temp; //use temporary node
	if (list->size == 1) { //if the list size is ine
		free(list->head); //free the mmemory of the item and zeroize list values
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
		return;
	}
	temp = list->head;
	list->head = list->head->next; //head of list is the second item
	list->head->prev = NULL;
	list->size--; //decrease size of list by one
	free(temp); //free the mommory allocated to the first item
}

///////////////////////////////////////////////////////////////
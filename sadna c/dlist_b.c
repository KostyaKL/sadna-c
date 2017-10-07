/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Costa Mirkin 61104-62
Targil: Shimon Aviram 661104-61 / Lior Levi 661104-63
*/

#include "dlist_b.h"

bstList *newBSTlist() {
	bstList *list;
	list = (bstList*)malloc(sizeof(bstList));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

///////////////////////////////////////////////////////////////

void insertBSTlistLast(bstList *list, bstNodeT *item) {
	nodeBSTlist *last;
	last = (nodeBSTlist*)malloc(sizeof(nodeBSTlist));
	last->item = item;
	if (!list->size) {
		list->head = last;
	}
	else {
		list->tail->next = last;
	}
	last->next = NULL;
	last->prev = list->tail;
	list->tail = last;
	list->size++;
}

///////////////////////////////////////////////////////////////

void insertBSTlistFirst(bstList *list, bstNodeT *item) {
	nodeBSTlist *first;
	first = (nodeBSTlist*)malloc(sizeof(nodeBSTlist));
	first->item = item;
	if (!list->size) {
		list->tail = first;
	}
	else {
		list->head->prev = first;
	}
	first->prev = NULL;
	first->next = list->head;
	list->head = first;
	list->size++;
}

///////////////////////////////////////////////////////////////

void deleteFirstBSTlist(bstList *list) {
	nodeBSTlist *temp;
	if (list->size == 1) {
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
		return;
	}
	temp = list->head;
	list->head = list->head->next;
	list->head->prev = NULL;
	list->size--;
	free(temp);
}
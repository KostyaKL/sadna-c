/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Costa Mirkin 61104-62
Targil: Shimon Aviram 661104-61 / Lior Levi 661104-63
*/

#pragma once
#include "binary_srch_tree.h"

typedef struct node_bst_list {
	bstNodeT *item;
	struct node_bst_list *next;
	struct node_bst_list *prev;
}nodeBSTlist;

typedef struct {
	nodeBSTlist *head;
	nodeBSTlist *tail;
	int size;
}bstList;

bstList *newBSTlist();

void insertBSTlistLast(bstList *list, bstNodeT *item);

void insertBSTlistFirst(bstList *list, bstNodeT *item);

void deleteFirstBSTlist(bstList *list);
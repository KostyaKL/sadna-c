/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Costa Mirkin 61104-62
Targil: Shimon Aviram 661104-61 / Lior Levi 661104-63
*/

#include <stdio.h>
#include "binary_srch_tree.h"
#include "dlist_b.h"

bsTree *newTree() {
	bsTree *tree;
	tree = (bsTree*)malloc(sizeof(bsTree));
	tree->root = NULL;
	return tree;
}
void insertBSTNode(bsTree *tree, int data) {
	bstNodeT *tmp;
	tmp = (bstNodeT*)malloc(sizeof(bstNodeT));
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	if (!tree->root) {
		tree->root = tmp;
		tmp->father = NULL;
	}
	else {
		insertToNode(tree->root, tmp);
	}
}

void insertToNode(bstNodeT *theNode, bstNodeT *tmp) {
	if (tmp->data < theNode->data) {
		if (!theNode->left) {
			theNode->left = tmp;
			tmp->father = theNode;
		}
		else {
			insertToNode(theNode->left, tmp);
		}
	}
	else {
		if (!theNode->right) {
			theNode->right = tmp;
			tmp->father = theNode;
		}
		else {
			insertToNode(theNode->right, tmp);
		}
	}
}

void printInorder(bsTree *tree) {

}

void printInArray(bsTree *tree) {
	bstList *list;
	list = newBSTlist();
	if (!tree->root) {
		printf("the tree is empty\n");
		return;
	}
	insertBSTlistLast(list, *tree->root);
	while (list->size) {
		printf("%d,", list->head->item.data);
		if (list->head->item.left) {
			insertBSTlistLast(list, *list->head->item.left);
		}
		if (list->head->item.right) {
			insertBSTlistLast(list, *list->head->item.right);
		}
		deleteFirstBSTlist(list);
	}
	printf("\n");
	free(list);
}

void freeTree(bsTree *tree) {

}

void clearStdi()
{
	char input;
	while ((input = getchar()) != '\n' && input != EOF); //clear stdin buffer as long there is items there and entered is pressed
}
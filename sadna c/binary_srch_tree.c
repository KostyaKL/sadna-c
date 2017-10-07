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

///////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////

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
	else if (tmp->data > theNode->data){
		if (!theNode->right) {
			theNode->right = tmp;
			tmp->father = theNode;
		}
		else {
			insertToNode(theNode->right, tmp);
		}
	}
}

///////////////////////////////////////////////////////////////

void printInorder(bsTree *tree) {
	bstList *list;
	bstNodeT tmpNode;
	int flag;
	list = newBSTlist();
	if (!tree->root) {
		printf("the tree is empty\n");
		return;
	}
	
	insertBSTlistFirst(list, tree->root);
	flag = 1;
	while (list->size) {
		if (list->head->item->left && flag) {
			insertBSTlistFirst(list, list->head->item->left);
		}
		else {
			printf("%d, ", list->head->item->data);
			flag = 0;
			if (list->head->item->right) {
				tmpNode = *list->head->item;
				deleteFirstBSTlist(list);
				insertBSTlistFirst(list, tmpNode.right);
				flag = 1;
			}
			else {
				deleteFirstBSTlist(list);
			}
		}
	}
	free(list);
}

///////////////////////////////////////////////////////////////

void printInArray(bsTree *tree) {
	bstList *list;
	list = newBSTlist();
	if (!tree->root) {
		printf("the tree is empty\n");
		return;
	}
	insertBSTlistLast(list, tree->root);
	while (list->size) {
		printf("%d,", list->head->item->data);
		if (list->head->item->left) {
			insertBSTlistLast(list, list->head->item->left);
		}
		if (list->head->item->right) {
			insertBSTlistLast(list, list->head->item->right);
		}
		deleteFirstBSTlist(list);
	}
	printf("\n");
	free(list);
}

///////////////////////////////////////////////////////////////

void freeTree(bsTree *tree) {
	bstList *list;
	list = newBSTlist();
	if (!tree->root) {
		free(tree);
		return;
	}
	insertBSTlistLast(list, tree->root);
	while (list->size) {
		if (list->head->item->left) {
			insertBSTlistLast(list, list->head->item->left);
		}
		if (list->head->item->right) {
			insertBSTlistLast(list, list->head->item->right);
		}
		free(list->head->item);
		deleteFirstBSTlist(list);
	}
	free(list);
	free(tree);
}

///////////////////////////////////////////////////////////////

int getInput() {
	int strSize, i, x, flag, exp;
	char str[MAX_C];
	clearStdi();
	scanf("%s", str);
	strSize = strlen(str);
	flag = 0;
	exp = 1;
	x = 0;
	i = 0;
	if (str[i] == '-') {
		flag = 1;
		i = 1;
	}
	for (i = strSize - 1;i >= flag;i--) {
		str[i] -= 48;
		if (str[i] < 0 || str[i] >9) {
			return MIN_INT;
		}
		x += str[i] * exp;
		exp *= 10;
	}
	if (flag) {
		x *= -1;
	}
	return x;
}

///////////////////////////////////////////////////////////////

void clearStdi()
{
	char input;
	while ((input = getchar()) != '\n' && input != EOF); //clear stdin buffer as long there is items there and entered is pressed
}
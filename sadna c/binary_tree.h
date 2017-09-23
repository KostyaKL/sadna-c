#pragma once

#include <stdlib.h>

typedef struct bt_node {
	int data;
	int level;
	struct bt_node *left;
	struct bt_node *right;
}btNodeT;

typedef struct {
	btNodeT *root;
	int size;
}binTree;

binTree *newTree() {
	binTree *tree;
	tree = (binTree*)malloc(sizeof(binTree));
	tree->root = NULL;
	tree->size = 0;
	return tree;
}

void insertBTNode(binTree *tree, int data) {
	btNodeT *node;
	btNodeT temp;
	node = (btNodeT*)malloc(sizeof(btNodeT));
	node->data = data;
	temp = *(tree->root);
	if (data > temp.data) {
		
	}
}
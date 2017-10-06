/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Costa Mirkin 61104-62
Targil: Shimon Aviram 661104-61 / Lior Levi 661104-63
*/

#pragma once

#include <stdlib.h>

typedef struct bst_node {
	int data;
	struct bst_node *left;
	struct bst_node *right;
	struct bst_node *father;
}bstNodeT;

typedef struct {
	bstNodeT *root;
}bsTree;

bsTree *newTree();

void insertBSTNode(bsTree *tree, int data);

void printInorder(bsTree *tree);

void printInArray(bsTree *tree);

void freeTree(bsTree *tree);
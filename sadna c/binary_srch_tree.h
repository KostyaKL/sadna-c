/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Costa Mirkin 61104-62
Targil: Shimon Aviram 661104-61 / Lior Levi 661104-63
*/

#pragma once

#include <stdlib.h>

#define MAX_C 100
#define MIN_INT 1<<31

typedef struct bst_node {
	int data;
	struct bst_node *left;
	struct bst_node *right;
	struct bst_node *father;
}bstNodeT;

typedef struct {
	bstNodeT *root;
}bsTree;

bsTree *newTree(); //function to create a new tree

void insertBSTNode(bsTree *tree, int data); //function to insert new value into the tree

void insertToNode(bstNodeT *theNode, bstNodeT *tmp); //function to determine where too put the new value in the tree

void printInorder(bsTree *tree); //function to print the tree inorder

void printInArray(bsTree *tree); //function nto print the three as an array

void freeTree(bsTree *tree); //function to free the memmory that was allocated to the tree

int getInput(); //function to get input values from user

void clearStdi(); //function to clear the system input buffer
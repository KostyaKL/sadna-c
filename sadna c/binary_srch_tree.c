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

///////////////////////////////////////////////////////////////

bsTree *newTree() { //function to create a new tree
	bsTree *tree;
	tree = (bsTree*)malloc(sizeof(bsTree)); //allocate memmory for the tree
	tree->root = NULL; //zeroise the root
	return tree; //return the address
}

///////////////////////////////////////////////////////////////

void insertBSTNode(bsTree *tree, int data) { //function to insert new value into the tree
	bstNodeT *tmp;
	tmp = (bstNodeT*)malloc(sizeof(bstNodeT)); //allocate memmory for a new node
	tmp->data = data; //put the data in the node
	tmp->left = NULL; //zeroise left and right branches of the new node
	tmp->right = NULL;
	if (!tree->root) { //if the tree is empty put the new node as the root of the tree
		tree->root = tmp;
		tmp->father = NULL;
	}
	else { //else deside where to put the new node using insertToNode() function
		insertToNode(tree->root, tmp);
	}
}

///////////////////////////////////////////////////////////////

void insertToNode(bstNodeT *theNode, bstNodeT *tmp) { //function to determine where too put the new value in the tree
	if (tmp->data < theNode->data) { //if the data of the new node is smaller than the current junction
		if (!theNode->left) { //if there is no left branch then put the new node there
			theNode->left = tmp;
			tmp->father = theNode;
		}
		else {
			insertToNode(theNode->left, tmp); //continue search recursivley for place to put the new node
		}
	}
	else if (tmp->data > theNode->data) { //if the data of the new node is smaller than the current junction
		if (!theNode->right) { //if there is no right branch then put the new node there
			theNode->right = tmp;
			tmp->father = theNode;
		}
		else {
			insertToNode(theNode->right, tmp); //continue search recursivley for place to put the new node
		}
	}
	else { //if the value of the current node already exist in the tree the release it
		free(tmp);
	}
}

///////////////////////////////////////////////////////////////

void printInorder(bsTree *tree) { //function to print the tree inorder
	bstList *list; //use list as stack
	bstNodeT tmpNode;
	int flag; //flag - determine if to go for left branch or not
	list = newBSTlist(); //create new list as stack
	if (!tree->root) { //if the tree is empty
		printf("the tree is empty\n");
		return;
	}
	
	insertBSTlistFirst(list, tree->root); //push the root to the stack
	flag = 1;
	while (list->size) { //as long as the stack is not empty
		if (list->head->item->left && flag) { //as long as there is left branch insert it to the stack
			insertBSTlistFirst(list, list->head->item->left); //push left branches ito the stack
		}
		else {
			printf("%d, ", list->head->item->data); //print the top item in the stack
			flag = 0; //stop pushing left branches
			if (list->head->item->right) { //if there is a right branch to the item
				tmpNode = *list->head->item;
				deleteFirstBSTlist(list); //pop the last item from stack
				insertBSTlistFirst(list, tmpNode.right); //push the right branch item into the stack
				flag = 1; //cuntinue to push left branches
			}
			else {
				deleteFirstBSTlist(list); //pop the first item in the stack
			}
		}
	}
	free(list); //free the mmemory allocated for the list
}

///////////////////////////////////////////////////////////////

void printInArray(bsTree *tree) { //function nto print the three as an array
	bstList *list; //use list as queu
	list = newBSTlist(); //create new list as queu
	if (!tree->root) { //if the tree is empty
		printf("the tree is empty\n");
		return;
	}
	insertBSTlistLast(list, tree->root); //insert the root to the queu
	while (list->size) { //as long as the queu is not empty
		printf("%d,", list->head->item->data); //print the first item in the queu
		if (list->head->item->left) { //if there is a left branch the insert it into the queu
			insertBSTlistLast(list, list->head->item->left);
		}
		if (list->head->item->right) { //if there is a right branch the insert it into the queu
			insertBSTlistLast(list, list->head->item->right);
		}
		deleteFirstBSTlist(list); //remove the next item from the queu
	}
	printf("\n");
	free(list); //free the mmemory allocated for the list
}

///////////////////////////////////////////////////////////////

void freeTree(bsTree *tree) { //function to free the memmory that was allocated to the tree
	bstList *list; //use list as queu
	list = newBSTlist(); //create new list as queu
	if (!tree->root) { //if the tree is empty
		free(tree); //free the mmemory allocated for the tree 
		return;
	}
	insertBSTlistLast(list, tree->root); //insert the root to the queu
	while (list->size) { //as long as the queu is not empty
		if (list->head->item->left) { //if there is a left branch the insert it into the queu
			insertBSTlistLast(list, list->head->item->left);
		}
		if (list->head->item->right) { //if there is a right branch the insert it into the queu
			insertBSTlistLast(list, list->head->item->right);
		}
		free(list->head->item); //free the memmory that was allocated for the node that is next in the queu
		deleteFirstBSTlist(list); //remove the next item from the queu
	}
	free(list); //free the mmemory allocated for the list
	free(tree); //free the mmemory allocated for the tree 
}

///////////////////////////////////////////////////////////////

int getInput() { //function to get input values from user
	int strSize, i, x, flag, exp; //strSize - size of input string, i - index, x - return value, flag - determine if num is +/-, exp - exponent*10
	char str[MAX_C]; //string to get input from user
	clearStdi(); //clear stdin buffer
	scanf("%s", str); //get string from user
	strSize = strlen(str); //get string size
	flag = 0;
	exp = 1;
	x = 0;
	i = 0;
	if (str[i] == '-') { //if first char in string is '-'
		if (strSize == 1) {
			return MIN_INT;
		}
		flag = 1; //flag that the number will be negative
	}
	for (i = strSize - 1;i >= flag;i--) { //check all chars in string
		str[i] -= 48; //change the char to a number (ASCII)
		if (str[i] < 0 || str[i] >9) { //if one of the chars in string is not a number than return a non number flag
			return MIN_INT;
		}
		x += str[i] * exp; //create the numerical value of the input
		exp *= 10;
	}
	if (flag) { //if number is negative
		x *= -1;
	}
	return x; //return input number
}

///////////////////////////////////////////////////////////////

void clearStdi() { //function to clear the system input buffer
	char input;
	while ((input = getchar()) != '\n' && input != EOF); //clear stdin buffer as long there is items there and entered is pressed
}

///////////////////////////////////////////////////////////////
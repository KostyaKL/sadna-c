/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Costa Mirkin 61104-62
Targil: Shimon Aviram 661104-61 / Lior Levi 661104-63
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_srch_tree.h"
#include "dlist_b.h"


//declaration of functions:
void h3_ex1_m(bsTree **tree); //function for excercise 1

void h3_ex2_m(bsTree *tree); //function for excercise 2

void h3_ex3_m(bsTree *tree); //function for excercise 3

void h3_ex4_m(bsTree **tree); //function for excercise 4

void printMenu3(); //function to print the menu


void hagasha_3_mivne() {
	int select = 0; //select - value to choose an exercise to display
	bsTree *tree; //a binary search tree to be used in the exersice
	tree = NULL;
	srand(time(NULL));//initialize random number generator (to be used later in the program)
	system("cls");
	printMenu3(); //print menu
	do {
		do {
			select = 0;
			printf("please select 0-5 : ");
			scanf("%d", &select);
		} while ((select < 0) || (select > 5));//loop to get a correct input from the user to choose the exercise to show
		printf("\n");
		switch (select) {//main menu switch case
		case 1: h3_ex1_m(&tree);//calling the function for ex 1
			break;
		case 2: h3_ex2_m(tree);//calling the function for ex 2
			break;
		case 3: h3_ex3_m(tree);//calling the function for ex 4
			break;
		case 4: h3_ex4_m(&tree);//calling the function for ex 5
			break;
		case 5: system("cls");//clear screen
			break;

		}
	} while (select); //determin if the program will return to main menu at the end of an exersice or it will exit
	return main();
}

///////////////////////////////////////////////////////////////

void printMenu3() {
	printf("Welcome to Binary Tree Menu\n"
		"---------------------------\n"
		"1 - Create binary tree\n"
		"2 - Print tree inorder\n"
		"3 - Print tree in levels\n"
		"4 - Free tree\n\n"
		"5 - Clear screen\n\n"
		"0 - Exit\n\n");
}

///////////////////////////////////////////////////////////////

void h3_ex1_m(bsTree **tree) {
	int x,i; //x - number to enter into the tree
	if (!*tree) { //if the tree does not exist
		*tree = newTree(); //create new tree
		printf("Enter numbers into binary search tree\n"
			"(enter non number to finnish input)\n");
		x = 0;
		while (x != MIN_INT) { //get input from user as long as x has a legal value
			x = getInput(); //get input from user using getInput() function
			if (x == MIN_INT) {
				printf("Input is finnished\n\n");
			}
			else {
				insertBSTNode(*tree, x); //insert the input into the tree
			}
		}

		/*for (i = 0;i < 15;i++) {
			x = rand() % 100;
			insertBSTNode(*tree, x);
			printf("%d, ", x);
		}*/
	}
	else { //if the tree already exist print massege
		printf("the tree already exist, print/free it using menu options 2-4\n");
	}
	printf("\n");
	system("pause");
	printf("\n\n");
}

///////////////////////////////////////////////////////////////

void h3_ex2_m(bsTree *tree) {
	printf("the tree printed inorder:\n");
	printInorder(tree); //print the tree inorder using printInorder() function (explained in binary_srch_tree.c file)

	printf("\n");
	system("pause");
	printf("\n\n");
}

///////////////////////////////////////////////////////////////

void h3_ex3_m(bsTree *tree) {
	printf("the tree as an array:\n");
	printInArray(tree); //print the tree as an array using printInArray() function (explained in binary_srch_tree.c file)

	printf("\n");
	system("pause");
	printf("\n\n");
}

///////////////////////////////////////////////////////////////

void h3_ex4_m(bsTree **tree) {

	freeTree(*tree); //free the memmory that was alocated to the tree using freeTree() function (explained in binary_srch_tree.c file)
	*tree = NULL;

	printf("you have released the tree\n");

	printf("\n");
	system("pause");
	printf("\n\n");
}

///////////////////////////////////////////////////////////////
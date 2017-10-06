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

void h3_ex2_m(); //function for excercise 2

void h3_ex3_m(bsTree *tree); //function for excercise 3

void h3_ex4_m(bsTree **tree); //function for excercise 4

void printMenu3();


void hagasha_3_mivne() {
	int select = 0; //select - value to choose an exercise to display
	bsTree *tree;
	tree = NULL;
	srand(time(NULL));//initialize random number generator (to be used later in the program)
	printMenu3();
	system("cls");
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
		case 2: h3_ex2_m();//calling the function for ex 2
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
	int x;
	if (!*tree) {
		*tree = newTree();
		printf("Enter numbers into binary search tree\n"
			"(enter non number to finnish input)\n");
		x = 0;
		while (x != MIN_INT) {
			x = getInput();
			if (x == MIN_INT) {
				printf("Input is finnished\n\n");
			}
			else {
				insertBSTNode(*tree, x);
			}
		}
		/*for (i = 0;i < 15;i++) {
			x = rand() % 100;
			insertBSTNode(*tree, x);
			printf("%d, ", x);
		}*/
	}
	else {
		printf("the tree already exist, print/free it using menu options 2-4\n");
	}
	printf("\n");
	system("pause");
	printf("\n\n");
}

///////////////////////////////////////////////////////////////

void h3_ex2_m() {

	printf("\n");
	system("pause");
	printf("\n\n");
}

///////////////////////////////////////////////////////////////

void h3_ex3_m(bsTree *tree) {

	printInArray(tree);

	printf("\n");
	system("pause");
	printf("\n\n");
}

///////////////////////////////////////////////////////////////

void h3_ex4_m(bsTree **tree) {

	freeTree(*tree);
	*tree = NULL;

	printf("you have released the tree\n");

	printf("\n");
	system("pause");
	printf("\n\n");
}

///////////////////////////////////////////////////////////////
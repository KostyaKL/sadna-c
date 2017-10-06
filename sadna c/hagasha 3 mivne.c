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

#define MAX_C 100

//declaration of functions:
void h3_ex1_m(bsTree **tree); //function for excercise 1

void h3_ex2_m(); //function for excercise 2

void h3_ex3_m(bsTree *tree); //function for excercise 3

void h3_ex4_m(); //function for excercise 4

void printMenu3();


void hagasha_3_mivne() {
	int select = 0; //select - value to choose an exercise to display
	bsTree *tree;
	tree = NULL;
	srand(time(NULL));//initialize random number generator (to be used later in the program)

	system("cls");
	do {
		printMenu3();
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
		case 4: h3_ex4_m();//calling the function for ex 5
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
	int strSize, i, x, flag, exp;
	char str[MAX_C];
	if (!*tree) {
		*tree = newTree();
		printf("Enter number into binary search tree\n"
			"Enter non number to terminate input\n");
		while (1) {
			clearStdi();
			gets(str);
			clearStdi();
			strSize = strlen(str);
			flag = 0;
			exp = 1;
			x = 0;
			i = 0;
			if (str[i] == '-') {
				flag = 1;
				i = 1;
			}
			for (i=strSize-1;i > flag;i--) {
				str[i] -= 48;
				if (str[i] < 0 || str[i] >9) {
					printf("you have entere illegal char there for the input was terminated\n");
					return;
				}
				x += str[i] * exp;
				exp *= 10;
			}
			if (flag) {
				x *= -1;
			}
			insertBSTNode(*tree, x);
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

void h3_ex4_m() {

	printf("\n");
	system("pause");
	printf("\n\n");
}

///////////////////////////////////////////////////////////////
/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Roi Zimon 61108-61
Targil: Ester Amiti 661108-65/69
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercise_3.h"


void h3_ex1_s(); //function for excercise 1

void h3_ex2_s(); //function for excercise 2

void h3_ex3_s(); //function for excercise 3

void h3_ex4_s(); //function for excercise 3



void hagasha_3_sadna()
{
	h3_ex4_s();

	printf("\n\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void h3_ex1_s()
{
	int select = 0; //select - value to choose an exercise to display
	char filename[MAX_FN];
	float threshold;
	system("cls");
	printf("Welcome to Employee salary menue!\n"
		"----------------------------\n"
		"Enter your file name: ");
	clearStdi(); //clear stdin buffer
	scanf("%s", filename); //get string from user
	printf("\n"
		"1 - Enter eployee data\n"
		"2 - Increase employee salary\n"
		"3 - Print employee data\n\n"
		"0 - Main menu\n\n");
	do
	{
		do {
			select = 0;
			printf("please select 0-3 : ");
			scanf("%d", &select);
		} while ((select < 0) || (select > 3));//loop to get a correct input from the user to choose the exercise to show
		printf("\n");
		switch (select) {//main menu switch case
		case 1: enterEmployee(filename);
			break;
		case 2: printf("\n"
			"Enter salary threshold: ");
			scanf("%lf", &threshold);
			updateSalary(filename, threshold);
			break;
		case 3: printEmployeeFile(filename);
			break;
		}
	} while (select); //determin if the program will return to main menu at the end of an exersice or it will exit
	printf("\n\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void h3_ex2_s()
{
	int select = 0; //select - value to choose an exercise to display
	char dig_str[MAX_FN], *short_dig_str;
	system("cls");
	printf("Welcome to Short string menue!\n"
		   "----------------------------\n"
		"1 - Code short string\n"
		"2 - Print short string\n\n"
		"0 - Main menu\n\n");
	do
	{
		do {
			select = 0;
			printf("please select 0-2 : ");
			scanf("%d", &select);
		} while ((select < 0) || (select > 2));//loop to get a correct input from the user to choose the exercise to show
		printf("\n");
		switch (select) {//main menu switch case
		case 1: printf("\n"
			"Enter a positive number: ");
			clearStdi();
			scanf("%s", dig_str);
			short_dig_str = codingToShortString(dig_str);
			break;
		case 2: displayShortString(short_dig_str);
			break;
		}
	} while (select); //determin if the program will return to main menu at the end of an exersice or it will exit
	printf("\n\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void h3_ex3_s()
{
	int select = 0; //select - value to choose an exercise to display
	board bin_board;
	unsigned long long coded_bin_board;
	srand(time(NULL));//initialize random number generator (to be used later in the program)
	system("cls");
	printf("Welcome to Char board menue!\n"
		   "----------------------------\n"
		"1 - Fill board\n"
		"2 - Board to number\n"
		"3 - Number to board\n\n"
		"0 - Main menu\n\n");
	do
	{
		do {
			select = 0;
			printf("please select 0-3 : ");
			scanf("%d", &select);
		} while ((select < 0) || (select > 3));//loop to get a correct input from the user to choose the exercise to show
		printf("\n");
		switch (select) {//main menu switch case
		case 1: fillBoard(bin_board);
			break;
		case 2: coded_bin_board = boardToBits(bin_board);
			break;
		case 3: displayBinaryBoard(coded_bin_board);
			break;
		}
	} while (select); //determin if the program will return to main menu at the end of an exersice or it will exit
	printf("\n\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void h3_ex4_s() {
	int select = 0; //select - value to choose an exercise to display
	srand(time(NULL));//initialize random number generator (to be used later in the program)
	do
	{
		system("cls");
		printf("Welcome to exercise 3 menue!\n"
			"----------------------------\n"
			"1 - Employee salary\n"
			"2 - Short string\n"
			"3 - Char board\n\n"
			"4 - Exit\n\n");
		do {
			select = 0;
			printf("please select 0-3 : ");
			scanf("%d", &select);
		} while ((select < 0) || (select > 3));//loop to get a correct input from the user to choose the exercise to show
		printf("\n");
		switch (select) {//main menu switch case
		case 1: h3_ex1_s();//calling the function for ex 1
			break;
		case 2: h3_ex2_s();//calling the function for ex 2
			break;
		case 3: h3_ex3_s();//calling the function for ex 3
			break;
		}
	} while (select); //determin if the program will return to main menu at the end of an exersice or it will exit
	printf("\n\n");
	system("pause");
}

///////////////////////////////////////////////////////////////
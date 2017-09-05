/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"
#include "double_list.h"

//declaration of functions:
void h1_ex1_m(); //function for excercise 1

void h1_ex2_m(); //function for excercise 2
void userNumPow(int *num, int *pow); //function to get a number and power from the user
void printMenu(); //function to print the menu of ex 2


void hagasha_2_mivne()
{

	int select = 0, i, all_Ex_in_loop = 0;
	/*
	select - value to choose an exercise to display
	i - index to print the menu
	all_ex_in_loop - value to choose if the program will return to main menu at the end of an exersice or it will exit
	*/

	srand(time(NULL));//initialize random number generator (to be used later in the program)

	system("cls");
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1) // determin if the value for loop condition is a number, if not exit the program
		do
		{
			system("cls");
			printf("Choose exercise number: \n");
			for (i = 1; i <= 2; i++)//loop to print the main menu
				printf("Ex%d--->%d\n", i, i);
			printf("\nEXIT-->0\n\n");
			do {
				select = 0;
				printf("please select 0-2 : ");
				scanf("%d", &select);
			} while ((select < 0) || (select > 5));//loop to get a correct input from the user to choose the exercise to show
			printf("\n");
			switch (select) {//main menu switch case
			case 1: h1_ex1_m();//calling the function for ex 1
				break;
			case 2: h1_ex2_m();//calling the function for ex 2
				break;
			}
		} while (all_Ex_in_loop && select); //determin if the program will return to main menu at the end of an exersice or it will exit
		return main();
}

///////////////////////////////////////////////////////////////

void h1_ex1_m()
{
	stackCT opr, act; //opr - stack for operators, act - stack for actions
	stackRT result; //result - stack for result line for each action
	newCStack(&opr); //initialize new stack
	newCStack(&act); //initialize new stack
	newRStack(&result); //initialize new stack

	printf("Enter your expression:\n");
	if (expressionInterpreter(&opr, &act, &result)) //if the function expressionInterpreter() returns 1 then print the result, expressionInterpreter() explained in stack.c file
		printRStack(&result); //function to print the result
	else
		printf("Ilegal char was entered\n");

	printf("\n\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void h1_ex2_m()
{
	int select = 0; //value to choose a function to run
	int num, pow; //values for X multiplier and power
	int constant; //value to moltiply a polynomial by
	polynomial *p1, *p2, *send, *result; //p1, p2 - polynomial linked lists, send - a list to be used after user choise, result - result of arithmatic action on p1 and p2
	//initial values for p1,p2,result
	p1 = NULL; 
	p2 = NULL;
	result = NULL;

	printMenu(); //print the menu of functions

	do 
	{
		do 
		{
			select = 0;
			printf("please select 0-10 : ");
			scanf("%d", &select);
		} while ((select < 0) || (select > 10)); //loop to get a correct input from the user to choose the function to run
		printf("\n");
		send = NULL; //zeroise send list
		//function menu 'if' function
		if (select == 1)
		{
			printf("Create empty polynomial\n"
				   "-----------------------\n");
			if (send = polySend(&p1, &p2, result)) //if user selected p1 or p2
			{
				emptyPoly(send);//update the list items
			} 
		}
		else if (select == 2)
		{
			printf("Add item to polynomial\n"
				   "----------------------\n");
			if (send = polySend(p1, p2, result)) //if user selected p1 or p2
			{
				userNumPow(&num, &pow); //get multiplier and power from user
				polyAddNum(send, num, pow); //add a*X^b number to the polynomial
			}
		}
		else if (select == 3)
		{
			printf("Sum of polynomial applied: result = p1 + p2\n\n");
			if (result) //zeroise result list
				freePoly(result);
			result = polySum(p1, p2); //add p1+p2
			if (p1 && p2 && result) //print the result
			{
				polyPrintBck(p1);
				printf(" + ");
				polyPrintBck(p2);
				printf(" = ");
				polyPrintBck(result);
				printf("\n\n");
			}
		}
		else if (select == 4)
		{
			printf("Substract polynomial applied: result = p1 - p2\n\n");
			if (result) //zeroise result list
				freePoly(result);
			result = polySub(p1, p2); //substract p1-p2
			if (p1 && p2 && result) //print the result
			{
				polyPrintBck(p1);
				printf(" - ");
				polyPrintBck(p2);
				printf(" = ");
				polyPrintBck(result);
				printf("\n\n");
			}
		}
		else if (select == 5)
		{
			printf("Multiply polynomial by constant\n"
				   "-------------------------------\n");
			printf("Enter a constant you want to multiply by: ");
			scanf("%d", &constant);
			if (send = polySend(p1, p2, result)) //if user selected p1 or p2
			{
				printf("result = p * %d\n\n", constant);
				result = polyMultiConst(send, constant); //multiply chooesn polynomial by constant
			}
			if (send && result) //print the result
			{
				if (send->size)
				{
					printf("(");
					polyPrintBck(send);
					printf(") * %d", constant);
				}
				else
				{
					printf("Zero (empty polynomal) * %d", constant);
				}
				printf(" = ");
				polyPrintBck(result);
				printf("\n\n");
			}
		}
		else if (select == 6)
		{
			printf("Size of polynomial\n"
				   "------------------\n");
			if (send = polySend(p1, p2, result)) //if user selected p1 or p2
				printf("The size of the polynome is: %d\n", polySize(send)); //print the size of chosen polynomial
		}
		else if (select == 7)
		{
			printf("Zeroise polynomial\n"
				   "------------------\n"); 
			if (send = polySend(p1, p2, result)) //if user selected p1 or p2
				zeroPoly(send); //zeroise the choosen polynomial
		}
		else if (select == 8)
		{
			printf("Print polynomial\n"
				   "----------------\n");
			if (send = polySend(p1, p2, result)) //if user selected p1 or p2
			{
				printf("Polinomal:\n");
				polyPrintBck(send); //print the chosen polynomial
				printf("\n\n");
			}
		}
		else if (select == 9)
		{
			printf("Multiply polynomial applied: result = p1 * p2\n\n");
			if (result) //zeroise result list
				freePoly(result);
			result = polyMulti(p1, p2); //multiply p1*p2
			if (p1 && p2 && result) //print the result
			{
				polyPrintBck(p1);
				printf(" * ");
				polyPrintBck(p2);
				printf(" = ");
				polyPrintBck(result);
				printf("\n\n");
			}
		}
		else if (select == 10)
			printMenu(); 

	} while (select); //determin if the program will return to main menu at the end of an exersice or it will exit
					  //return main();

	if (p1) //if p1 was used the release the memory was allocated to it
		freePoly(p1);
	if (p2) //if p2 was used the release the memory was allocated to it
		freePoly(p2);
	if (result) //if result was used the release the memory was allocated to it
		freePoly(result);
	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void userNumPow(int *num, int *pow) //function to get a number and power from the user
{
	printf("Enter X multiplier and X power:\n");
	printf("mult: ");
	do //the multiplier cannot be equal to zero
	{
		scanf("%d", num);
		if (*num == 0)
			printf("The multiplier cannot be ZERO, try again: ");
	} while (*num == 0);

	printf("power: ");
	do //the power must be a non negative integer
	{
		scanf("%d", pow);
		if (*pow < 0)
			printf("The power cannot be negative, try again: ");
	} while (*pow < 0);
	printf("\n");
}

///////////////////////////////////////////////////////////////

void printMenu() //function to print the menu of ex 2
{
	printf("Polynomal\n");
	printf("Choose polynomal function: \n");
	printf("1 - Empty polynomal\n"
		"2 - Add item to polynomal\n"
		"3 - Sum of polynimal\n"
		"4 - Substract polynimal\n"
		"5 - Multiply polinimal by constant\n"
		"6 - Size of polynomal\n"
		"7 - Zeroise polynomal\n"
		"8 - Print polynomal\n"
		"9 - Multiply polynomal\n"
		"10 - Print Menu\n");
	printf("\n0 - EXIT\n\n");
}
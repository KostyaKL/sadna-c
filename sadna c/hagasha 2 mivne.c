/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

//declaration of functions:
void h1_ex1_m(); //function for excercise 1
int expressionInterpreter(stackCT *opr, stackCT *act, stackRT *rslt);


void h1_ex2_m(); //function for excercise 2



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
	char input;
	stackCT opr, act;
	stackRT result;
	newCStack(&opr);
	newCStack(&act);
	newRStack(&result);

	printf("Enter your expression:\n");
	if (expressionInterpreter(&opr, &act, &result))
	{
		printRStack(&result);
		printf("\n\n");
	}
	else
		printf("Ilegal char was entered\n");

	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

int expressionInterpreter(stackCT *opr, stackCT *act, stackRT *rslt)
{
	char input=NULL ,temp;
	int actFlag = 0;
	resT line;
	char res = 90;
	getchar();
	while (1)
	{
		input = getchar();
		if ((input >= 48 && input <= 57) || (input >= 65 && input <= 72))
		{
			pushC(opr, input);
			actFlag = 0;
		}
		//42 - *, 43 - +, 45 - -, 47 - /, 94 - ^
		else if (input == 42 || input == 43 || input == 45 || input == 47 || input == 94)
			if (actFlag || emptyCStack(opr))
			{
				while ((input = getchar()) != '\n' && input != EOF);
				return 0;
			}
			else
			{
				if (emptyCStack(act) || input == 94 || (input == 42 || input == 47) && (topC(act) == 43 || topC(act) == 45))
				actFlag = pushC(act, input);
				else
				{
					temp = input;
					while ((input == 43 || input == 45) || ((input == 42 || input == 47) && (input == 42 || input == 47 || input == 94)))
					{
						line.act = popC(act);
						line.opr1 = popC(opr);
						line.opr2 = popC(opr);
						line.rslt = res;
						pushR(rslt, line);
						pushC(opr, res);
						res--;
						input = topC(act);
					}
					actFlag = pushC(act, temp);
				}
			}
		else if (input == 32);
		else if (input == 10)
		{
			if (actFlag)
				return 0;
			while (emptyCStack(act) != 1 && emptyCStack(opr) != 1)
			{
				line.act = popC(act);
				line.opr1 = popC(opr);
				line.opr2 = popC(opr);
				line.rslt = res;
				pushR(rslt, line);
				pushC(opr, res);
				res--;
			}
			return 1;
		}
		else
		{
			while ((input = getchar()) != '\n' && input != EOF);
			return 0;
		}
	} 
}

///////////////////////////////////////////////////////////////

void h1_ex2_m()
{
	
	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

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
int expressionInterpreter(stackCT *opr, stackCT *act, stackRT *rslt);
void writeLine(stackCT *opr, stackCT *act, stackRT *rslt, char *resIndex);
void clearStdi();
void inputPush(stackCT *act, char input, int *flagOne, int *flagNull);

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
		printRStack(&result);
	else
		printf("Ilegal char was entered\n");

	printf("\n\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

int expressionInterpreter(stackCT *opr, stackCT *act, stackRT *rslt)
{
	char input ,prevIn;
	int actFlag, oprFlag;
	char resIndex;
	clearStdi();
	resIndex = 90;
	actFlag = 0;
	oprFlag = 0;
	while (1)
	{
		input = getchar();
		if ((input >= 48 && input <= 57) || (input >= 65 && input <= 72))
		{
			if(oprFlag)
			{
				clearStdi();
				return 0;
			}
			inputPush(opr, input, &oprFlag, &actFlag);
		}
		//42 - *, 43 - +, 45 - -, 47 - /, 94 - ^
		else if (input == 42 || input == 43 || input == 45 || input == 47 || input == 94)
			if (actFlag || emptyCStack(opr))
			{
				clearStdi();
				return 0;
			}
			else
			{
				if (emptyCStack(act) || input == 94)
					inputPush(act, input, &actFlag, &oprFlag);
				else
				{
					prevIn = input;
					while ((input == 43 || input == 45) ||
						((input == 42 || input == 47) && (topC(act) == 42 || topC(act) == 47 || topC(act) == 94)) ||
						(input == 94 && topC(act) == 94))
					{
						if ((input == 43 || input == 45) && (prevIn == 42 || prevIn == 47 || prevIn == 94))
							input = -1;
						else
						{
							writeLine(opr, act, rslt, &resIndex);
							input = topC(act);
						}
					}
					inputPush(act, prevIn, &actFlag, &oprFlag);
				}
			}
		else if (input == 32);
		else if (input == 10)
		{
			if (actFlag)
				return 0;
			while (emptyCStack(act) != 1 && emptyCStack(opr) != 1)
				writeLine(opr, act, rslt, &resIndex);
			return 1;
		}
		else
		{
			clearStdi();
			return 0;
		}
	} 
}

///////////////////////////////////////////////////////////////

void writeLine(stackCT *opr, stackCT *act, stackRT *rslt, char *resIndex)
{
	resT line;
	line.act = popC(act);
	line.opr2 = popC(opr);
	line.opr1 = popC(opr);
	line.rslt = *resIndex;
	pushR(rslt, line);
	pushC(opr, *resIndex);
	(*resIndex)--;
}

///////////////////////////////////////////////////////////////

void clearStdi()
{
	char input;
	while ((input = getchar()) != '\n' && input != EOF);
}

///////////////////////////////////////////////////////////////

void inputPush(stackCT *stack, char input, int *flagOne, int *flagNull)
{
	*flagOne = pushC(stack, input);
	*flagNull = 0;
}

///////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////

void h1_ex2_m()
{
	doubleList *list;
	list = newDoubleList();
	dlistInsertFirst(list, 1);
	dlistInsertFirst(list, 2);
	dlistInsertFirst(list, 3);

	dlistInsertLast(list, 7);
	dlistInsertLast(list, 8);
	dlistInsertLast(list, 9);

	printf("\n");
	printf("\n");
	dlistPrintFwd(list);
	printf("\n");
	printf("\n");
	dlistPrintBck(list);
	printf("\n");
	dlistFree(list);

	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

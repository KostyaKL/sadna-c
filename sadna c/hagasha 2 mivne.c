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
void emptyPoly(polynomial **p1);
void polyAddNum(polynomial *p1, int num, int pow);
nodeDL *findPow(polynomial *p1, int pow);
nodeDL *findNextPow(polynomial *p1, int pow);
void userNumPow(int *num, int *pow);
void printMenu();


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
	int select = 0;
	int num, pow;
	polynomial *p1, *p2;
	p1 = newPolynomial();
	p2 = newPolynomial();

	printMenu();
	
		do
		{
			do {
				select = 0;
				printf("please select 0-9 : ");
				scanf("%d", &select);
			} while ((select < 0) || (select > 9));//loop to get a correct input from the user to choose the exercise to show
			printf("\n");
			switch (select) {
			case 1:
				emptyPoly(&p1);
				break;
			case 2:
				userNumPow(&num, &pow);
				polyAddNum(p1, num, pow);
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			case 6:
				
				break;
			case 7:
				
				break;
			case 8:
				printf("\n\nPolinomal:\n");
				polyPrintBck(p1);
				printf("\n\n");
				break;
			case 9:
				printMenu();
				break;
			}
		} while (select); //determin if the program will return to main menu at the end of an exersice or it will exit
		return hagasha_2_mivne();


	freePoly(p1);
	freePoly(p2);
	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////


void emptyPoly(polynomial **p1)
{
	freePoly(*p1);
	*p1 = newPolynomial();
	polyInsertFirst(*p1, 0, 0);
}

void polyAddNum(polynomial *p1, int num, int pow)
{
	nodeDL *node, *insert;
	if (p1->size == 0)
	{
		polyInsertFirst(p1, num, pow);
		return;
	}
	node = findPow(p1, pow);
	if (node)
		node->num += num;
	else
	{
		node = findNextPow(p1, pow);
		if (node)
			if (node->prev == NULL)
				polyInsertFirst(p1, num, pow);
			else
			{
				insert = (nodeDL*)malloc(sizeof(nodeDL));
				insert->num = num;
				insert->pow = pow;
				insert->prev = node->prev;
				insert->next = node;
				node->prev->next = insert;
				node->prev = insert;
				p1->size++;
			}
		else
			polyInsertLast(p1, num, pow);
	}
}

nodeDL *findPow(polynomial *p1, int pow)
{
	int i;
	nodeDL *node;
	node = p1->head;
	if (p1->size == 0)
		return NULL;
	else
		for (i = 0;i < p1->size;i++)
			if (node->pow == pow)
				return node;
			else
				node = node->next;
	return NULL;
}

nodeDL *findNextPow(polynomial *p1, int pow)
{
	int i;
	nodeDL *node;
	node = p1->head;
	if (p1->size == 0)
		return NULL;
	else
		for (i = 0;i < p1->size;i++)
			if (node->pow > pow)
				return node;
			else
				node = node->next;
	return NULL;
}

void userNumPow(int *num, int *pow)
{
	printf("Enter X multiplier and X power:\n");
	
	printf("mult: ");
	do
	{
		scanf("%d", num);
		if (*num == 0)
			printf("The multiplier cannot be ZERO, try again: ");
	} while (*num == 0);

	printf("power: ");
	do
	{
		scanf("%d", pow);
		if (*pow < 0)
			printf("The power cannot be negative, try again: ");
	} while (*pow < 0);
}

void printMenu()
{
	printf("Polynomal\n");
	printf("Choose polynomal function: \n");
	printf("1 - Empty polynomal\n"
		"2 - Add item to polynomal\n"
		"3 - XXX\n"
		"4 - XXX\n"
		"5 - XXX\n"
		"6 - XXX\n"
		"7 - XXX\n"
		"8 - Print polynomal\n\n"
		"9 - Print Menu\n");
	printf("\n0 - EXIT\n\n");
}
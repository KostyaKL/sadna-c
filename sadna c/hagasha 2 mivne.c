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
polynomial *polySend(polynomial *p1, polynomial *p2, polynomial *result);
void zeroPoly(polynomial *p1);
polynomial *polySum(polynomial *p1, polynomial *p2);


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
	char input, prevIn;
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
			if (oprFlag)
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
	polynomial *p1, *p2, *send, *result;
	p1 = NULL;
	p2 = NULL;
	result = NULL;

	printMenu();

	do
	{
		do
		{
			select = 0;
			printf("please select 0-10 : ");
			scanf("%d", &select);
		} while ((select < 0) || (select > 10));//loop to get a correct input from the user to choose the exercise to show
		printf("\n");

		if (select == 1)
		{
			printf("Create empty polynomial\n"
				   "-----------------------\n");
			if (send = polySend(&p1, &p2, result))
				emptyPoly(send);
		}
		else if (select == 2)
		{
			printf("Add item to polynomial\n"
				   "----------------------\n");
			if (send = polySend(p1, p2, result))
			{
				userNumPow(&num, &pow);
				polyAddNum(send, num, pow);
			}
		}
		else if (select == 3)
		{
			printf("Sum of polynomial applied: result = p1 + p2\n\n");
			if (result)
				freePoly(result);
			result = polySum(p1, p2);
		}
		else if (select == 4)
		{
			printf("Substract polynomial applied: result = p1 - p2\n\n");
		}
		else if (select == 5)
		{
			printf("Multiply polynomial by constant\n"
				   "-------------------------------\n");
		}
		else if (select == 6)
		{
			printf("Size of polynomial\n"
				   "------------------\n");
			if (send = polySend(p1, p2, result))
				printf("The size of the polynome is: %d\n", polySize(send));
		}
		else if (select == 7)
		{
			printf("Zeroise polynomial\n"
				   "------------------\n");
			if (send = polySend(p1, p2, result))
				zeroPoly(send);
		}
		else if (select == 8)
		{
			printf("Print polynomial\n"
				   "----------------\n");
			if (send = polySend(p1, p2, result))
			{
				printf("\n\nPolinomal:\n");
				polyPrintBck(send);
				printf("\n\n");
			}
		}
		else if (select == 9)
		{
			printf("Multiply polynomial applied: result = p1 * p2\n\n");
		}
		else if (select == 10)
			printMenu();

	} while (select); //determin if the program will return to main menu at the end of an exersice or it will exit
					  //return main();

	if (p1)
		freePoly(p1);
	if (p2)
		freePoly(p2);
	if (result)
		freePoly(result);
	printf("\n");
	printf("You have exited exersise 2\n\n");
	system("pause");
}

///////////////////////////////////////////////////////////////


void emptyPoly(polynomial **p1)
{
	*p1 = newPolynomial();
	printf("you have created a new polynimial\n\n");
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
	{
		node->num += num;
		if (node->num == 0)
			polyDeleteSingle(p1, node);
	}
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
		for (i = 0; i < p1->size; i++)
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
		for (i = 0; i < p1->size; i++)
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
	printf("\n");
}

void printMenu()
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

polynomial *polySend(polynomial *p1, polynomial *p2, polynomial *result)
{
	int choise;
	polynomial *send;
	
	printf("choose to which polynomial apply the func?\n"
		"p1\t- choose 1\n"
		"p2\t- choose 2\n"
		"result\t- choose 3\n"
		"cancel\t- choose 0\n\n"
		"choise: ");
	do
	{
		scanf("%d", &choise);
		if (choise < 0 || choise > 3)
			printf("your choise must be 0/1/2/3, try again: ");
	} while (choise < 0 || choise > 3);
	if (choise == 1)
	{
		send = p1;
		if (send == NULL)
			printf("you must create a polynomial, choose function 1 in main menu\n");
	}
	else if (choise == 2)
	{
		send = p2;
		if (send == NULL)
			printf("you must create a polynomial, choose function 1 in main menu\n");
	}
	else if (choise == 3)
	{
		send = result;
		if (send == NULL)
			printf("result polynomial does not exist, choose function 3/4/5 in main menu to create it\n");
	}
	else
		send = NULL;
	printf("\n");
	return send;
}

int polySize(polynomial *p1)
{
	if (p1->size)
		return p1->size;
	return -1;
}

void zeroPoly(polynomial *p1)
{
	nodeDL *node;
	if (p1->size == 0)
		return;
	for (node = p1->head; p1->size > 0; node = p1->head)
		polyDeleteSingle(p1, node);

}

polynomial *polySum(polynomial *p1, polynomial *p2)
{
	int i, j, highP1, highP2;
	polynomial *result;
	nodeDL *node1, *node2;

	result = newPolynomial();

	if (p1 == NULL || p2 == NULL)
	{
		printf("you must initialize polinomial 1 and 2, use function 1\n");
		return NULL;
	}
	else if (p1->size == 0 && p2->size == 0)
	{
		return result;
	}
	
	node1 = p1->tail;
	node2 = p2->tail;

	i = p1->size;
	j = p2->size;

	if (node1 == NULL)
	{
		highP1 = -1;
		highP2 = node2->pow;
	}
	else if (node2 == NULL)
	{
		highP1 = node1->pow;
		highP2 = -1;
	}
	else
	{
		highP1 = node1->pow;
		highP2 = node2->pow;
	}

	while (i > 0 || j > 0)
	{
		if (highP1 == highP2)
		{
			if (node1->num + node2->num)
			{
				polyAddNum(result, node1->num + node2->num, highP1);
			}
			if (i == 1 && j == 1)
			{
				highP1 = -1;
				highP2 = -1;
			}
			else if (i == 1)
			{
				highP1 = -1;
			}
			else if (j == 1)
			{
				highP2 = -1;
			}
			else
			{
				node1 = node1->prev;
				node2 = node2->prev;
				highP1 = node1->pow;
				highP2 = node2->pow;
			}
			i--;
			j--;
		}
		else if (highP1 > highP2)
		{
			polyAddNum(result, node1->num, highP1);
			if (i == 1)
			{
				highP1 = -1;
			}
			else
			{
				node1 = node1->prev;
				highP1 = node1->pow;
			}
			i--;
		}
		else if (highP2 > highP1)
		{
			polyAddNum(result, node2->num, highP2);
			if (j == 1)
			{
				highP2 = -1;
			}
			else
			{
				node2 = node2->prev;
				highP2 = node2->pow;
			}
			j--;
		}
	}
	return result;
}
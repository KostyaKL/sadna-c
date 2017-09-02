#include <stdio.h>
#include "stack.h"


void newCStack(stackCT *stack)
{
	stack->top = -1;
}

///////////////////////////////////////////////////////////////

unsigned int pushC(stackCT *stack, char x)
{
	if (stack->top == MAX-1)
		return 0;
	stack->top++;
	stack->items[stack->top] = x;
	return 1;
}

///////////////////////////////////////////////////////////////

char popC(stackCT *stack)
{
	if (stack->top == -1)
		return -1;
	stack->top--;
	return stack->items[stack->top+1];
}

///////////////////////////////////////////////////////////////

char topC(stackCT *stack)
{
	if (stack->top == -1)
		return -1;

	return stack->items[stack->top];
}

///////////////////////////////////////////////////////////////

int emptyCStack(stackCT *stack)
{
	if (stack->top == -1)
		return 1;
	return 0;
}

///////////////////////////////////////////////////////////////

int fullCStack(stackCT *stack)
{
	if (stack->top == MAX)
		return 1;
	return 0;
}

///////////////////////////////////////////////////////////////

void printCStack(stackCT *stack)
{
	int i;
	if (stack->top == -1)
	{
		printf("The stack is empty\n");
		return;
	}
	for (i = 0;i <= stack->top;i++)
		printf("%c, ", stack->items[i]);
}

///////////////////////////////////////////////////////////////

void newRStack(stackRT *stack)
{
	stack->top = -1;
}

///////////////////////////////////////////////////////////////

int pushR(stackRT *stack, resT x)
{
	if (stack->top == MAX - 1)
		return 0;
	stack->top++;
	stack->items[stack->top] = x;
	return 1;
}

///////////////////////////////////////////////////////////////

resT popR(stackRT *stack)
{
	resT fail;
	fail.act = -1;
	fail.opr1 = -1;
	fail.opr2 = -1;
	fail.rslt = -1;

	if (stack->top == -1)
		return fail;
	stack->top--;
	return stack->items[stack->top + 1];
}

///////////////////////////////////////////////////////////////

resT topR(stackRT *stack)
{
	resT fail;
	fail.act = -1;
	fail.opr1 = -1;
	fail.opr2 = -1;
	fail.rslt = -1;

	if (stack->top == -1)
		return fail;

	return stack->items[stack->top];
}

///////////////////////////////////////////////////////////////

int emptyRStack(stackRT *stack)
{
	if (stack->top == -1)
		return 1;
	return 0;
}

///////////////////////////////////////////////////////////////

int fullRStack(stackRT *stack)
{
	if (stack->top == MAX)
		return 1;
	return 0;
}

///////////////////////////////////////////////////////////////

void printRStack(stackRT *stack)
{
	int i;
	if (stack->top == -1)
	{
		printf("The stack is empty\n");
		return;
	}
	printf("\n"
		   "Operation\tOperand1\tOperand2\tResult\n"
		   "---------\t--------\t--------\t------\n");
	for (i = 0;i <= stack->top;i++)
	{
		printf("%c\t\t%c\t\t%c\t\t%c", stack->items[i].act, stack->items[i].opr1, stack->items[i].opr2, stack->items[i].rslt);
		printf("\n");
	}
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
		else if (input == 32)
			input = -1;
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

void inputPush(stackCT *stack, char input, int *flagOne, int *flagNull)
{
	*flagOne = pushC(stack, input);
	*flagNull = 0;
}

///////////////////////////////////////////////////////////////

void clearStdi()
{
	char input;
	while ((input = getchar()) != '\n' && input != EOF);
}
/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Costa Mirkin 61104-62
Targil: Shimon Aviram 661104-61 / Lior Levi 661104-63
*/

#include <stdio.h>
#include "stack.h"


void newCStack(stackCT *stack)
{
	stack->top = -1; //initialize the size of stack
}

///////////////////////////////////////////////////////////////

unsigned int pushC(stackCT *stack, char x)
{
	if (stack->top == MAX-1) //if stack is full return 0
		return 0;
	//push the char, count +1 for size and return 1
	stack->top++;
	stack->items[stack->top] = x;
	return 1;
}

///////////////////////////////////////////////////////////////

char popC(stackCT *stack)
{
	if (stack->top == -1) //if stack is empty return -1
		return -1;
	//count -1 for size and return the last item
	stack->top--;
	return stack->items[stack->top+1];
}

///////////////////////////////////////////////////////////////

char topC(stackCT *stack)
{
	if (stack->top == -1)//if stack is empty return -1
		return -1;

	return stack->items[stack->top]; //return the last item, not changing the size of the stack
}

///////////////////////////////////////////////////////////////

int emptyCStack(stackCT *stack)
{
	if (stack->top == -1) //if stack is empty return 1, else return 0
		return 1;
	return 0;
}

///////////////////////////////////////////////////////////////

int fullCStack(stackCT *stack)
{
	if (stack->top == MAX) //if stack is full return 1, else return 0
		return 1;
	return 0;
}

///////////////////////////////////////////////////////////////

void printCStack(stackCT *stack)
{
	int i;
	if (stack->top == -1) //if stack is empty
	{
		printf("The stack is empty\n");
		return;
	}
	for (i = 0;i <= stack->top;i++) //print all items in stack
		printf("%c, ", stack->items[i]);
}

///////////////////////////////////////////////////////////////

void newRStack(stackRT *stack)
{
	stack->top = -1; //initialize the size of stack
}

///////////////////////////////////////////////////////////////

int pushR(stackRT *stack, resT x)
{
	if (stack->top == MAX - 1) //if stack is full return 0
		return 0;
	//push the char, count +1 for size and return 1
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

	if (stack->top == -1) //if stack is empty return -1 for all resT values
		return fail;
	//count -1 for size and return the last item
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

	if (stack->top == -1) //if stack is empty return -1 for all resT values
		return fail;

	return stack->items[stack->top]; //return the last item, not changing the size of the stack
}

///////////////////////////////////////////////////////////////

int emptyRStack(stackRT *stack)
{
	if (stack->top == -1) //if stack is empty return 1, else return 0
		return 1;
	return 0;
}

///////////////////////////////////////////////////////////////

int fullRStack(stackRT *stack)
{
	if (stack->top == MAX) //if stack is full return 1, else return 0
		return 1;
	return 0;
}

///////////////////////////////////////////////////////////////

void printRStack(stackRT *stack)
{
	int i;
	if (stack->top == -1) //if stack is empty
	{
		printf("The stack is empty\n");
		return;
	}
	printf("\n"
		   "Operation\tOperand1\tOperand2\tResult\n"
		   "---------\t--------\t--------\t------\n");
	for (i = 0;i <= stack->top;i++) //print all items of stack in this table format
	{
		printf("%c\t\t%c\t\t%c\t\t%c", stack->items[i].act, stack->items[i].opr1, stack->items[i].opr2, stack->items[i].rslt);
		printf("\n");
	}
}

///////////////////////////////////////////////////////////////

int expressionInterpreter(stackCT *opr, stackCT *act, stackRT *rslt)
{
	//42 - *, 43 - +, 45 - -, 47 - /, 94 - ^, 90 - Z, 32 - space, 10 - enter

	char input, prevIn; //input - current char, prevIn - previous char
	int actFlag, oprFlag; //flags to determine if last char was operator or action
	char resIndex; //reult index for each action
	clearStdi(); //clear stdin buffer
	resIndex = 90; //initialize to 'Z'
	actFlag = 0;
	oprFlag = 0;
	while (1)
	{
		input = getchar(); //get current char from stdin buffer
		if ((input >= 48 && input <= 57) || (input >= 65 && input <= 72)) //if input is an operator (number/A-H)
		{
			if (oprFlag) //if previous input was an operator then clear stdin buffer and return 0
			{
				clearStdi();
				return 0;
			}
			inputPush(opr, input, &oprFlag, &actFlag); //push input into opr stack
		}
		
		else if (input == 42 || input == 43 || input == 45 || input == 47 || input == 94) //if input is an action (+/-/*///^)
			if (actFlag || emptyCStack(opr)) //if previous input was an action then clear stdin buffer and return 0
			{
				clearStdi();
				return 0;
			}
			else
			{
				if (emptyCStack(act) || input == 94) //if this is the first action or power action then push it to act stack
					inputPush(act, input, &actFlag, &oprFlag);
				else
				{
					prevIn = input; //save the current input into prevIn
					while ((input == 43 || input == 45) ||
						((input == 42 || input == 47) && (topC(act) == 42 || topC(act) == 47 || topC(act) == 94)) ||
						(input == 94 && topC(act) == 94)) //as long as the input is +/- or *// and previous input was *///^ or ^ and previous input was ^
					{
						if ((input == 43 || input == 45) && (prevIn == 42 || prevIn == 47 || prevIn == 94)) //if input is +/- and prevIn is *///^ then do nothing
							input = -1;
						else 
						{
							writeLine(opr, act, rslt, &resIndex); //input new item to result stack
							input = topC(act); //cheack the next action in act stack
						}
					}
					inputPush(act, prevIn, &actFlag, &oprFlag); //push the current action into act stack
				}
			}
		else if (input == 32) //if input is space then do nothing
			input = -1;
		else if (input == 10) //if input is enter
		{
			if (actFlag) //if the last input was action then return 
			{
				clearStdi();
				return 0;
			}
			while (emptyCStack(act) != 1 && emptyCStack(opr) != 1) //as long as act or opr stacks are not empty
				writeLine(opr, act, rslt, &resIndex); //push the remaning actions and results to result stack and return 1
			return 1;
		}
		else //if any other illegal char was entered clear stdin buffer and return 0
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
	line.act = popC(act); //pop last action
	line.opr2 = popC(opr); //pop last two operators
	line.opr1 = popC(opr);
	line.rslt = *resIndex; //last result index
	pushR(rslt, line); //push the result to result stack
	pushC(opr, *resIndex); //push the last result index to opr stack
	(*resIndex)--; //advance to next result index
}

///////////////////////////////////////////////////////////////

void inputPush(stackCT *stack, char input, int *flagOne, int *flagNull)
{
	*flagOne = pushC(stack, input); //flagOne gets 1 for the last stack an item was pushed into
	*flagNull = 0; //flagNull gets 0 for the other stack
}

///////////////////////////////////////////////////////////////

void clearStdi()
{
	char input;
	while ((input = getchar()) != '\n' && input != EOF); //clear stdin buffer as long there is items there and entered is pressed
}
#include "stack.h"


void newCStack(stackCT *stack)
{
	stack->top = -1;
}

unsigned int pushC(stackCT *stack, char x)
{
	if (stack->top == MAX-1)
		return 0;
	stack->top++;
	stack->items[stack->top] = x;
	return 1;
}

char popC(stackCT *stack)
{
	if (stack->top == -1)
		return -1;
	stack->top--;
	return stack->items[stack->top+1];
}

char topC(stackCT *stack)
{
	if (stack->top == -1)
		return -1;

	return stack->items[stack->top];
}

int emptyCStack(stackCT *stack)
{
	if (stack->top == -1)
		return 1;
	return 0;
}

int fullCStack(stackCT *stack)
{
	if (stack->top == MAX)
		return 1;
	return 0;
}

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


void newRStack(stackRT *stack)
{
	stack->top = -1;
}

int pushR(stackRT *stack, resT x)
{
	if (stack->top == MAX - 1)
		return 0;
	stack->top++;
	stack->items[stack->top] = x;
	return 1;
}

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

int emptyRStack(stackRT *stack)
{
	if (stack->top == -1)
		return 1;
	return 0;
}

int fullRStack(stackRT *stack)
{
	if (stack->top == MAX)
		return 1;
	return 0;
}

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

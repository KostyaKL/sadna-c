#pragma once

#define MAX 20
#define MIN_INT 1<<31

typedef struct
{
	int top;
	char items[MAX];
}stackCT;

typedef struct
{
	char act;
	char opr1;
	char opr2;
	char rslt;
}resT;

typedef struct
{
	int top;
	resT items[MAX];
}stackRT;

void newCStack(stackCT *stack);

unsigned int pushC(stackCT *stack, char x);

char popC(stackCT *stack);

char topC(stackCT *stack);

int emptyCStack(stackCT *stack);

int fullCStack(stackCT *stack);

void printCStack(stackCT *stack);


void newRStack(stackRT *stack);

int pushR(stackRT *stack, resT x);

resT popR(stackRT *stack);

resT topR(stackRT *stack);

int emptyRStack(stackRT *stack);

int fullRStack(stackRT *stack);

void printRStack(stackRT *stack);
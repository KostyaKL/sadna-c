#pragma once

#define MAX 100
#define MIN_INT 1<<31

typedef struct
{
	int top;
	int items[MAX];
}stackT;

void newStack(stackT *stack);

unsigned char push(stackT *stack, int x);

int pop(stackT *stack);

int top(stackT *stack);

unsigned char emptyStack(stackT *stack);

unsigned char fullStack(stackT *stack);
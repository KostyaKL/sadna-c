#include "stack.h"


void newStack(stackT *stack)
{
	stack->top = -1;
}

unsigned char push(stackT *stack, int x)
{
	if (stack->top == MAX-1)
		return 0;
	stack->top++;
	stack->items[stack->top] = x;
	return 1;
}

int pop(stackT *stack)
{
	int ret;
	if (stack->top == -1)
		return MIN_INT;
	stack->top--;
	return stack->items[stack->top+1];
}

int top(stackT *stack)
{
	int ret;
	if (stack->top == -1)
		return MIN_INT;

	return stack->items[stack->top];
}

unsigned char emptyStack(stackT *stack)
{
	if (stack->top == -1)
		return MIN_INT;
}

unsigned char fullStack(stackT *stack)
{
	if (stack->top == MAX)
		return MIN_INT;
}
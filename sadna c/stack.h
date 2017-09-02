#pragma once

#define MAX 20
#define MIN_INT 1<<31

typedef struct
{
	int top;
	char items[MAX];
}stackCT; //define stack of chars

typedef struct
{
	char act;
	char opr1;
	char opr2;
	char rslt;
}resT; //define type for result line for ex 1

typedef struct
{
	int top;
	resT items[MAX];
}stackRT; //define stack of resT type

void newCStack(stackCT *stack); //create new stack of chars

unsigned int pushC(stackCT *stack, char x); //push char into stack of chars

char popC(stackCT *stack); //pop char from stack of cars

char topC(stackCT *stack); //check what is the top char i the stack

int emptyCStack(stackCT *stack); //check if the stack is empty

int fullCStack(stackCT *stack); //check if the stacj is full

void printCStack(stackCT *stack); //print the stack


void newRStack(stackRT *stack); //create new stack of resT type

int pushR(stackRT *stack, resT x); //push resT into stack

resT popR(stackRT *stack); //pop resT from stack

resT topR(stackRT *stack); //check what is the top resT in the stack

int emptyRStack(stackRT *stack); //check if the stack is empty

int fullRStack(stackRT *stack); //check if the stacj is full

void printRStack(stackRT *stack); //print the stack

int expressionInterpreter(stackCT *opr, stackCT *act, stackRT *rslt); //handel an arythmetic expression

void writeLine(stackCT *opr, stackCT *act, stackRT *rslt, char *resIndex); //write a result line from the expression

void inputPush(stackCT *stack, char input, int *flagOne, int *flagNull); //handle input chars from the expression to stacks

void clearStdi(); //function to clear stdin buffer
/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Costa Mirkin 61104-62
Targil: Shimon Aviram 661104-61 / Lior Levi 661104-63
*/

#pragma once
#define MAX_B 100

typedef struct {
	int top;
	int items[MAX_B];
}bstStackT;

void newBSTstack(bstStackT *stack);

void pushBST(bstStackT *stack, int x);

int popBST(bstStackT *stack);

void printBSTstack(bstStackT *stack);
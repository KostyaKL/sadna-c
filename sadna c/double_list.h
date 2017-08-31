#pragma once

typedef struct nodedl
{
	int num;
	int pow;
	struct nodedl *next;
	struct nodedl *prev;
}nodeDL;

typedef struct
{
	nodeDL *head;
	nodeDL *tail;
	int size;
}polynomial;

polynomial *newPolynomial();

void polyInsertFirst(polynomial *list, int num, int pow);

void polyInsertLast(polynomial *list, int num, int pow);

void polyPrintFwd(polynomial *list);

void polyPrintBck(polynomial *list);

void polyDeleteSingle(polynomial *list, nodeDL *node);

void freePoly(polynomial *list);
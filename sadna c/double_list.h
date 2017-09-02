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


polynomial *polySend(polynomial *p1, polynomial *p2, polynomial *result);

void emptyPoly(polynomial **p1);

void polyAddNum(polynomial *p1, int num, int pow);

polynomial *polySum(polynomial *p1, polynomial *p2);

polynomial *polySub(polynomial *p1, polynomial *p2);

polynomial *polyMultiConst(polynomial *p1, int constant);

int polySize(polynomial *p1);

void zeroPoly(polynomial *p1);

void polyPrintBck(polynomial *list);

polynomial *polyMulti(polynomial *p1, polynomial *p2);


nodeDL *findPow(polynomial *p1, int pow);

nodeDL *findNextPow(polynomial *p1, int pow);
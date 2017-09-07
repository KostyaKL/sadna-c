/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Costa Mirkin 61104-62
Targil: Shimon Aviram 661104-61 / Lior Levi 661104-63
*/

#pragma once

typedef struct nodedl
{
	double num;
	int pow;
	struct nodedl *next;
	struct nodedl *prev;
}nodeDL; //define node for double list containing two integers

typedef struct
{
	nodeDL *head;
	nodeDL *tail;
	int size;
}polynomial; //define double list of nodeDL type

polynomial *newPolynomial(); //create new double list

void polyInsertFirst(polynomial *list, double num, int pow); //insert node at the begining of the list

void polyInsertLast(polynomial *list, double num, int pow); //insert noed at the end of the list

void polyDeleteSingle(polynomial *list, nodeDL *node); //delete single node from list

void freePoly(polynomial *list); //free the memory was alocated for thr list and its nodes


polynomial *polySend(polynomial *p1, polynomial *p2, polynomial *result); //user choise of p1,p2,result lists


void emptyPoly(polynomial **p1); //create empty polynomal list

void polyAddNum(polynomial *p1, double num, int pow); //add a*X^b item to the polynome

polynomial *polySum(polynomial *p1, polynomial *p2); //return the sum of p1+p2

polynomial *polySub(polynomial *p1, polynomial *p2); //return the substruction of p1-p2

polynomial *polyMultiConst(polynomial *p1, double constant); //return the result for polynome * constant

int polySize(polynomial *p1); //return the size of the polynome

void zeroPoly(polynomial *p1); //zeroise the polynome

void polyPrintBck(polynomial *list); //print the polynome (print backwards function as the largest power item will be in the end of the list

polynomial *polyMulti(polynomial *p1, polynomial *p2); //return the multiplication of p1*p2


nodeDL *findPow(polynomial *p1, int pow); //find a node with a specific power

nodeDL *findNextPow(polynomial *p1, int pow); //find a node with the next power
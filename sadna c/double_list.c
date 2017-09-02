#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

polynomial *newPolynomial()
{
	polynomial *list;
	list = (polynomial*)malloc(sizeof(polynomial)); //allocate memory for list and initialize its items
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

///////////////////////////////////////////////////////////////

void polyInsertFirst(polynomial *list, int num, int pow)
{
	nodeDL *node;
	node = (nodeDL*)malloc(sizeof(nodeDL)); //allocate memory for a new node and initialize its items
	node->num = num;
	node->pow = pow;
	if (list->size == 0)
		list->tail = node;
	else
		list->head->prev = node;
	node->next = list->head;
	node->prev = NULL;
	list->head = node; //update the list items
	list->size++;
}

///////////////////////////////////////////////////////////////

void polyInsertLast(polynomial *list, int num, int pow)
{
	nodeDL *node;
	node = (nodeDL*)malloc(sizeof(nodeDL)); //allocate memory for a new node and initialize its items
	node->num = num;
	node->pow = pow;
	if (list->size == 0)
		list->head = node;
	else
		list->tail->next = node;
	node->next = NULL;
	node->prev = list->tail;
	list->tail = node; //update the list items
	list->size++;
}

///////////////////////////////////////////////////////////////

void polyDeleteSingle(polynomial *list, nodeDL *node)
{
	//update list items
	if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else if (node->prev == NULL)
	{
		list->head = node->next;
		node->next->prev = node->prev;
	}
	else if (node->next == NULL)
	{
		list->tail = node->prev;
		node->prev->next = node->next;
	}
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
	list->size--;
	free(node); //free the memory was allocated for the node
}

///////////////////////////////////////////////////////////////

void freePoly(polynomial *list)
{
	nodeDL *node;
	node = list->head;
	while (list->size) //free every single node
	{
		list->head = node->next;
		free(node);
		node = list->head;
		list->size--;
	}
	free(list); //free the list header
}

///////////////////////////////////////////////////////////////

polynomial *polySend(polynomial *p1, polynomial *p2, polynomial *result)
{
	int choise;
	polynomial *send;

	printf("choose to which polynomial apply the func?\n"
		"p1\t- choose 1\n"
		"p2\t- choose 2\n"
		"result\t- choose 3\n"
		"cancel\t- choose 0\n\n"
		"choise: ");
	do
	{
		scanf("%d", &choise);
		if (choise < 0 || choise > 3)
			printf("your choise must be 0/1/2/3, try again: ");
	} while (choise < 0 || choise > 3); //restrict user choise
	if (choise == 1)
	{
		send = p1;
		if (send == NULL)
			printf("you must create a polynomial, choose function 1 in main menu\n");
	}
	else if (choise == 2)
	{
		send = p2;
		if (send == NULL)
			printf("you must create a polynomial, choose function 1 in main menu\n");
	}
	else if (choise == 3)
	{
		send = result;
		if (send == NULL)
			printf("result polynomial does not exist, choose function 3/4/5 in main menu to create it\n");
	}
	else
		send = NULL;
	printf("\n");
	return send; //return user choise
}

///////////////////////////////////////////////////////////////

void emptyPoly(polynomial **p1)
{
	*p1 = newPolynomial(); //create new list for polynomial
	printf("you have created a new polynimial\n\n");
}

///////////////////////////////////////////////////////////////

void polyAddNum(polynomial *p1, int num, int pow)
{
	nodeDL *node, *insert;
	if (p1->size == 0) //if p1 is empty list
	{
		polyInsertFirst(p1, num, pow);
		return;
	}

	node = findPow(p1, pow); //search if there is already a node with the same power
	if (node) //if so
	{
		node->num += num; //add the multipliers
		if (node->num == 0) //if the outcome is 0 then remove the node from the list
			polyDeleteSingle(p1, node);
	}
	else //if the power was not found
	{
		node = findNextPow(p1, pow); //search for the next power
		if (node) //if found
			if (node->prev == NULL) //if the next power found in the first node
				polyInsertFirst(p1, num, pow); //enter currnt item at the begining
			else //insert the current item before the node that wsa found
			{
				insert = (nodeDL*)malloc(sizeof(nodeDL));
				insert->num = num;
				insert->pow = pow;
				insert->prev = node->prev;
				insert->next = node;
				node->prev->next = insert;
				node->prev = insert;
				p1->size++;
			}
		else //if next power was not found
			polyInsertLast(p1, num, pow); //enter the current item at the end
	}
}

///////////////////////////////////////////////////////////////

polynomial *polySum(polynomial *p1, polynomial *p2)
{
	int i, j, highP1, highP2;
	polynomial *result;
	nodeDL *node1, *node2;

	result = newPolynomial(); //create empty list for result

	if (p1 == NULL || p2 == NULL)
	{
		printf("you must initialize polinomial 1 and 2, use function 1\n");
		return NULL;
	}
	else if (p1->size == 0 && p2->size == 0) //if p1 and p2 are empty return empty list
	{
		return result;
	}

	node1 = p1->tail;
	node2 = p2->tail;

	i = p1->size;
	j = p2->size;

	if (node1 == NULL)
	{
		highP1 = -1;
		highP2 = node2->pow;
	}
	else if (node2 == NULL)
	{
		highP1 = node1->pow;
		highP2 = -1;
	}
	else
	{
		highP1 = node1->pow;
		highP2 = node2->pow;
	}

	while (i > 0 || j > 0) //go through every item in both polynomials
	{
		if (highP1 == highP2) //if there is two items in each polynomial with the same power
		{
			if (node1->num + node2->num) 
			{
				polyAddNum(result, node1->num + node2->num, highP1); //add the sum of the multipliers and add it to result list as long as its not 0
			}
			if (i == 1 && j == 1)
			{
				highP1 = -1;
				highP2 = -1;
			}
			else if (i == 1)
			{
				highP1 = -1;
			}
			else if (j == 1)
			{
				highP2 = -1;
			}
			else
			{
				node1 = node1->prev;
				node2 = node2->prev;
				highP1 = node1->pow;
				highP2 = node2->pow;
			}
			i--;
			j--;
		}
		else if (highP1 > highP2) //add the highest power item to the result list
		{
			polyAddNum(result, node1->num, highP1);
			if (i == 1)
			{
				highP1 = -1;
			}
			else
			{
				node1 = node1->prev;
				highP1 = node1->pow;
			}
			i--;
		}
		else if (highP2 > highP1) //add the highest power item to the result list
		{
			polyAddNum(result, node2->num, highP2);
			if (j == 1)
			{
				highP2 = -1;
			}
			else
			{
				node2 = node2->prev;
				highP2 = node2->pow;
			}
			j--;
		}
	}
	return result;
}

///////////////////////////////////////////////////////////////

polynomial *polySub(polynomial *p1, polynomial *p2)
{
	int i, j, highP1, highP2;
	polynomial *result;
	nodeDL *node1, *node2;

	result = newPolynomial(); //create empty list for result

	if (p1 == NULL || p2 == NULL)
	{
		printf("you must initialize polinomial 1 and 2, use function 1\n");
		return NULL;
	}
	else if (p1->size == 0 && p2->size == 0) //if p1 and p2 are empty return empty list
	{
		return result;
	}

	node1 = p1->tail;
	node2 = p2->tail;

	i = p1->size;
	j = p2->size;

	if (node1 == NULL)
	{
		highP1 = -1;
		highP2 = node2->pow;
	}
	else if (node2 == NULL)
	{
		highP1 = node1->pow;
		highP2 = -1;
	}
	else
	{
		highP1 = node1->pow;
		highP2 = node2->pow;
	}

	while (i > 0 || j > 0) //go through every item in both polynomials
	{
		if (highP1 == highP2)
		{
			if (node1->num - node2->num) //if there is two items in each polynomial with the same power
			{
				polyAddNum(result, node1->num - node2->num, highP1); //add the substraction of the multipliers and add it to result list as long as its not 0
			}
			if (i == 1 && j == 1)
			{
				highP1 = -1;
				highP2 = -1;
			}
			else if (i == 1)
			{
				highP1 = -1;
			}
			else if (j == 1)
			{
				highP2 = -1;
			}
			else
			{
				node1 = node1->prev;
				node2 = node2->prev;
				highP1 = node1->pow;
				highP2 = node2->pow;
			}
			i--;
			j--;
		}
		else if (highP1 > highP2) //add the highest power item to the result list
		{
			polyAddNum(result, node1->num, highP1);
			if (i == 1)
			{
				highP1 = -1;
			}
			else
			{
				node1 = node1->prev;
				highP1 = node1->pow;
			}
			i--;
		}
		else if (highP2 > highP1) //add the highest power item to the result list
		{
			polyAddNum(result, -node2->num, highP2);
			if (j == 1)
			{
				highP2 = -1;
			}
			else
			{
				node2 = node2->prev;
				highP2 = node2->pow;
			}
			j--;
		}
	}
	return result;
}

///////////////////////////////////////////////////////////////

polynomial *polyMultiConst(polynomial *p1, int constant)
{
	int i;
	polynomial * result;
	nodeDL *node;
	result = newPolynomial(); //create empty list for result

	if (p1 == NULL)
	{
		printf("you must initialize polinomial, use function 1\n");
		return NULL;
	}

	if (p1->size == 0) //if p1 is 0 the return empty list
		return result;
	
	node = p1->head;
	for (i = p1->size;i > 0;i--)
	{
		polyAddNum(result, node->num*constant, node->pow); //add to result each item*constant using pollyAddNum() function
		node = node->next;
	}
	
	return result;
}

///////////////////////////////////////////////////////////////

int polySize(polynomial *p1)
{
	if (p1->size) //return the size of the list
		return p1->size;
	return -1;
}

///////////////////////////////////////////////////////////////

void zeroPoly(polynomial *p1)
{
	nodeDL *node;
	if (p1->size == 0)
		return;
	for (node = p1->head; p1->size > 0; node = p1->head) //delete all nodes from list (only nodes)
		polyDeleteSingle(p1, node);
}

///////////////////////////////////////////////////////////////

void polyPrintBck(polynomial *list)
{
	int i;
	nodeDL *node;
	if (list->size == 0)
	{
		printf("Zero (empty polynomal)\n");
		return;
	}
	node = list->tail;

	for (i = list->size; i > 0; i--) //print each item in correct format
	{
		if (node->pow == 0)
		{
			if (i < list->size  && node->num > 0)
				printf("+%d", node->num);
			else
				printf("%d", node->num);
		}
		else if (node->pow == 1)
		{
			if (i < list->size && node->num == 1)
				printf("+X");
			else if (node->num == -1)
				printf("-X");
			else if (i < list->size && node->num > 1)
				printf("+%dX", node->num);
			else
				printf("%dX", node->num);
		}
		else
		{
			if (i < list->size && node->num == 1)
				printf("+X^%d", node->pow);
			else if (node->num == -1)
				printf("-X^%d", node->pow);
			else if (i < list->size && node->num > 1)
				printf("+%dX^%d", node->num, node->pow);
			else
				printf("%dX^%d", node->num, node->pow);
		}
		node = node->prev;
	}
}

///////////////////////////////////////////////////////////////

polynomial *polyMulti(polynomial *p1, polynomial *p2)
{
	polynomial *result;
	nodeDL *node1, *node2;
	int i, j;
	result = newPolynomial(); //create empty list for result
	if (p1 == NULL || p2 == NULL)
	{
		printf("you must initialize polinomial 1 and 2, use function 1\n");
		return NULL;
	}
	else if (p1->size == 0 && p2->size == 0) //if both polynomes are 0 retrun empty list
	{
		return result;
	}

	node1 = p1->head;
	node2 = p2->head;

	for (i = p1->size;i > 0;i--)
	{
		for (j = p2->size; j > 0;j--) //multiply each item from p1 by each item from p2
		{
			if (node1->num*node2->num) //if the result not 0
			{
				polyAddNum(result, node1->num*node2->num, node1->pow + node2->pow); //add to result each using pollyAddNum() function
			}
			node2 = node2->next;
		}
		node1 = node1->next;
		node2 = p2->head;
	}
	return result;
}

///////////////////////////////////////////////////////////////

nodeDL *findPow(polynomial *p1, int pow)
{
	int i;
	nodeDL *node;
	node = p1->head;
	if (p1->size == 0)
		return NULL;
	else
		for (i = 0; i < p1->size; i++) //search a node with a specific power
			if (node->pow == pow)
				return node;
			else
				node = node->next;
	return NULL; //if not found return NULL
}

///////////////////////////////////////////////////////////////

nodeDL *findNextPow(polynomial *p1, int pow)
{
	int i;
	nodeDL *node;
	node = p1->head;
	if (p1->size == 0)
		return NULL;
	else
		for (i = 0; i < p1->size; i++) //search a node with the next power after pow
			if (node->pow > pow)
				return node;
			else
				node = node->next;
	return NULL; //if not found return NULL
}
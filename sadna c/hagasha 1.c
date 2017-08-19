/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "list.h"

#define	MAT_A_ROW 3 //predifined number of rows for matrix A
#define	MAT_A_COL 3 //predifined number of cols for matrix A
#define	MAT_B_ROW 3 //predifined number of rows for matrix B
#define	MAT_B_COL 3 //predifined number of cols for matrix B

//declaration of functions:
void h1_ex1(); //function for excercise 1
unsigned int *powerArray(int n); //function to build an array that each element is 2^(i mod 32), i being the index of the array

void h1_ex2(); //function for excercise 2
int **matMulti(int matA[MAT_A_ROW][MAT_A_COL], int matB[MAT_B_ROW][MAT_B_COL]); //function to calculate the multiplication of two matrixs
void freeMat(int **mat, int row); //function to free the memoery allocated for a dynamic size matrix

void h1_ex3(); //function for excercise 3
int coordSum(int **mat, int row, int col, listT *list);

void h1_ex4(); //function for excercise 4
void userList(listT *list);
listT *oddEven(listT* even);

void h1_ex5(); //function for excercise 5



void hagahsa_1()
{

	int select = 0, i, all_Ex_in_loop = 0;
	/*
	select - value to choose an exercise to display
	i - index to print the menu
	all_ex_in_loop - value to choose if the program will return to main menu at the end of an exersice or it will exit
	*/

	srand(time(NULL));//initialize random number generator (to be used later in the program)
	
	system("cls");
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1) // determin if the value for loop condition is a number, if not exit the program
		do
		{
			system("cls");
			printf("Choose exercise number: \n");
			for (i = 1; i <= 5; i++)//loop to print the main menu
				printf("Ex%d--->%d\n", i, i);
			printf("\nEXIT-->0\n\n");
			do {
				select = 0;
				printf("please select 0-5 : ");
				scanf("%d", &select);
			} while ((select < 0) || (select > 5));//loop to get a correct input from the user to choose the exercise to show
			printf("\n");
			switch (select) {//main menu switch case
			case 1:	h1_ex1();//calling the function for ex 1
				break;
			case 2: h1_ex2();//calling the function for ex 2
				break;
			case 3: h1_ex3();//calling the function for ex 3
				break;
			case 4: h1_ex4();//calling the function for ex 4
				break;
			case 5: h1_ex5();//calling the function for ex 5
				break;
			}
		} while (all_Ex_in_loop && select); //determin if the program will return to main menu at the end of an exersice or it will exit
		return main();
}

///////////////////////////////////////////////////////////////

void h1_ex1() 
{
	unsigned int *p; //p - pointer to an array the will be created
	int n, i; //n - number of elements in the aray, i - index
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n); //get input for the number of elements

	p = powerArray(n); //build the array using the function powerArray()

	for (i = 0;i < n;i++) //loop to print the array
		printf("%d, ", *(p + i));

	printf("\n");
	free(p);
	system("pause");
}

///////////////////////////////////////////////////////////////

unsigned int *powerArray(int n) //function to build an array that each element is 2^(i mod 32), i being the index of the array
{
	unsigned int *p; //p - pointer to be returend when the array is ready
	int i;//i - index
	p = (unsigned int *)malloc(sizeof(unsigned int)*n);//create an array in size n and save the addrres at p
	for (i = 0;i < n;i++)
		*(p + i) = pow(2, i % 32);//insert numbers into the array using the rule 2^(i mod 32)

	return p; //return the address of the array
}

///////////////////////////////////////////////////////////////

void h1_ex2()
{
	int matA[MAT_A_ROW][MAT_A_COL], matB[MAT_B_ROW][MAT_B_COL]; //predifined size matrix
	int **matC; //ponter to a new matrix to be returned after calcuclating matA*matB
	int i, j; //index i and index j to work with matrix
	//printf("Enter number for matrix A %dX%d:\n", MAT_A_ROW, MAT_A_COL);
	for(i=0;i<MAT_A_ROW;i++) //input values for matrix A
		for (j = 0;j < MAT_A_COL;j++)
		{
			//printf("row %d col %d: ", i+1, j+1);
			if (rand() % 2)
				matA[i][j] = rand() % 20;
			else
				matA[i][j] = (rand() % 20)*(-1);
			//scanf("%d", &matA[i][j]);
		}
	printf("\n");
	//printf("Enter number for matrix B %dX%d:\n", MAT_B_ROW, MAT_B_COL);
	for (i = 0;i<MAT_B_ROW;i++) //input values for matrix B
		for (j = 0;j < MAT_B_COL;j++)
		{
			//printf("row %d col %d: ", i+1, j+1);
			if (rand() % 2)
				matB[i][j] = rand() % 20;
			else
				matB[i][j] = (rand() % 20)*(-1);
			//scanf("%d", &matB[i][j]);
		}

	printf("\n\nmatrix A:\n");

	for (i = 0;i < MAT_A_ROW;i++)
	{
		for (j = 0;j < MAT_A_COL;j++)
			printf("%d\t", matA[i][j]);
		printf("\n");
	}

	printf("\n\nmatrix B:\n");

	for (i = 0;i < MAT_B_ROW;i++)
	{
		for (j = 0;j < MAT_B_COL;j++)
			printf("%d\t", matB[i][j]);
		printf("\n");
	}

	printf("\n\n");

	matC = matMulti(matA, matB); //send the adressess of matrix A and B to calculate their multiplication and return the address of the new matrix

	printf("\n");
	printf("matrixA X matrixB =\n");
	for (i = 0;i < MAT_A_ROW;i++) //print new matrix C wich shows matA*matB
	{
		for (j = 0;j < MAT_B_COL;j++)
			printf("%d\t", *(*(matC + i) + j));
		printf("\n");
	}

	printf("\n");
	freeMat(matC,MAT_A_ROW); //free the memorie that was allocated for matrix C
	system("pause");
}

///////////////////////////////////////////////////////////////

int **matMulti(int matA[MAT_A_ROW][MAT_A_COL], int matB[MAT_B_ROW][MAT_B_COL]) //function to calculate the multiplication of two matrixs
{
	int **matC; //pointer for matrix C
	int i, j, m; //index i and j to work with matrix, index m for calculating the multiplication of matA nad matB

	matC = (int**)malloc(sizeof(int*)*MAT_A_ROW);//allocate memory for array of pointers in the size of the rows of matrix A
	for (i = 0;i < MAT_A_ROW;i++) //for each pointer allocate memory for array of number in the size of the cols of matrix B
		*(matC + i) = (int*)calloc(sizeof(int*),MAT_B_COL);//each slot in the new matrix will get initial value of zero
	
	for (i = 0;i < MAT_A_ROW;i++) //calculate matA*matB by multiplying each row in matA by each col in matB
		for (j = 0;j < MAT_B_COL;j++)
			for(m = 0;m < MAT_A_COL;m++)
			*(*(matC + i) + j) += matA[i][m]*matB[m][j];
	return matC; //return the address of the result matrix C
}

///////////////////////////////////////////////////////////////

void freeMat(int **mat, int row) //function to free the memoery allocated for a dynamic size matrix
{
	int i; //index

	for (i = 0;i < row;i++) //free the memory of each array of numbers (cols)
		free(*(mat + i));
	free(mat); //free the memory of the array of pointers (rows)
}

///////////////////////////////////////////////////////////////

void h1_ex3()
{
	int **mat;
	int row, col, i, j, size=0;
	listT *list;

	list = newList();

	//printf("Enter number of rows: ");
	//scanf("%d", &row);
	//printf("Enter number of cols: ");
	//scanf("%d", &col);

	row = (rand() % 5) + 1;
	col = (rand() % 5) + 1;

	mat = (int**)malloc(sizeof(int*)*row);
	for (i = 0;i < row;i++)
		*(mat + i) = (int*)malloc(sizeof(int)*col);
	//printf("Enter numbers for matrix %dX%d:\n", row, col);
	for(i=0;i<row;i++)
		for (j = 0;j < col;j++)
		{
			//printf("row %d col %d: ", i+1, j+1);
			//scanf("%d", *(mat + i) + j);
			if (rand() % 2)
				*(*(mat + i) + j) = rand() % 20;
			else
				*(*(mat + i) + j) = (rand() % 20)*(-1);
		}

	printf("\n\n");
	printf("matrix %dX%d:\n", row, col);
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
			printf("%d\t", *(*(mat + i) + j));
		printf("\n");
	}

	printf("\n");

	size = coordSum(mat, row, col, list);

	if (size)
	{
		printList3(list);
		printf("\n");
		printf("the size of the list is %d nodes\n", size);
		printf("\n");
		freeList3(list);
	}
	else
		printf("no i+j numbers found in the matrix");

	printf("\n\n");
	freeMat(mat,row);
	system("pause");
}

///////////////////////////////////////////////////////////////

int coordSum(int **mat, int row, int col, listT *list)
{
	int i, j, size=0;
	trio data;
	
	for(i=0;i<row;i++)
		for (j = 0;j < col;j++)
			if (*(*(mat + i) + j) == i + j)
			{
				data.sum = i + j;
				data.i = i;
				data.j = j;
				addFirst3(list, data);
				size++;
			}
	return size;
}

///////////////////////////////////////////////////////////////

void h1_ex4()
{
	listT *even, *odd;

	even = newList();

	userList(even);
	printf("user list:\n");
	printList(even);
	printf("\n\n");



	odd = oddEven(even);

	printf("even list:\n");
	printList(even);
	printf("\n\n");
	printf("odd list:\n");
	printList(odd);

	freeList(even);
	freeList(odd);

	printf("\n\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void userList(listT *list)
{
	int x = 0;
	printf("enter numbers to list:\n");
	while (1)
	{
		//x = (rand() % 20) - 1;
		scanf("%d", &x);
		if (x >= 0)
			addFirst(list, x);
		else
			return;
	}
}

///////////////////////////////////////////////////////////////

listT *oddEven(listT* even)
{
	listT *odd, tempL;
	nodeT *node;
	odd = newList();

	if (even->head == NULL)
		return odd;

	node = even->head;
	tempL.head = node->next;

	while (node->data % 2)
	{
		addFirst(odd, node->data);
		
		if (node->next)
			freeSingle(even, node);
		else
		{
			freeSingle(even, node);
			return odd;
		}
	}

	while (tempL.head)
	{
		if (node->next && node->next->data % 2)
		{
			addFirst(odd, node->next->data);
			if (node->next->next)
			{
				freeSingle(even, node->next);
				tempL.head = node;
			}
			else
			{
				freeLast(node);
				return odd;
			}
		}
		else
		{
			tempL.head = node->next;
			node = tempL.head;
		}
	}

	return odd;
}

///////////////////////////////////////////////////////////////

void h1_ex5()
{
	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////
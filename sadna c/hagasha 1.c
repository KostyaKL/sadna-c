/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

#define MAT_A_ROW 5 //predifined number of rows for matrix A
#define MAT_A_COL 4 //predifined number of cols for matrix A
#define MAT_B_ROW 4 //predifined number of rows for matrix B
#define MAT_B_COL 3 //predifined number of cols for matrix B

//declaration of functions:
void h1_ex1(); //function for excercise 1
unsigned int *powerArray(int n); //function to build an array that each element is 2^(i mod 32), i being the index of the array
void printArry(int *arr, int size);

void h1_ex2(); //function for excercise 2
int **matMulti(int matA[MAT_A_ROW][MAT_A_COL], int matB[MAT_B_ROW][MAT_B_COL]); //function to calculate the multiplication of two matrixs
void freeMat(int **mat, int row); //function to free the memoery allocated for a dynamic size matrix
void printMat(int **mat, int row, int col);

void h1_ex3(); //function for excercise 3
int coordSum(int **mat, int row, int col, listT **list, trio **arr); //function to create a list of matrix members that equal to row + col index
int **inputMat(int row, int col);
void printArrTrio(trio *arr, int size);

void h1_ex4(); //function for excercise 4
void userList(listT *list); //function to get numbers into list from user
listT *oddEven(listT* even); //function to sort odd/even numbers in the list

void h1_ex5(); //function for excercise 5
listT *oddEven_noDelete(listT* even); //function to sort odd/even numbers in the list, returns the address of the odd numbers list



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
			case 1: h1_ex1();//calling the function for ex 1
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
	int n; //n - number of elements in the aray
			  printf("Enter the number of elements in the array: ");
			  scanf("%d", &n); //get input for the number of elements

	//n = rand();
	

	p = powerArray(n); //build the array using the function powerArray()

	if (p)
	{
		printf("number of elements in the array: %d\n", n);
		printArry(p, n);
	}
	else
		printf("Not enough memory for the array\n");

	printf("\n\n");
	free(p);
	system("pause");
}

///////////////////////////////////////////////////////////////

unsigned int *powerArray(int n) //function to build an array that each element is 2^(i mod 32), i being the index of the array
{
	unsigned int *p; //p - pointer to be returend when the array is ready
	int i;//i - index
	
	p = (unsigned int *)malloc(sizeof(unsigned int)*n);//create an array in size n and save the addrres at p
	if (p)
	{
		*p = 1;
		for (i = 1; i < n; i++)
		{
			if (*(p + i-1) == 1073741824)
				*(p + i) = 1;
			else
				*(p + i) = *(p + i - 1) * 2;//insert numbers into the array using the rule 2^(i mod 32)
		}
	}

	return p; //return the address of the array
}

///////////////////////////////////////////////////////////////

void printArry(int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++) //loop to print the array
		printf("%d, ", *(arr + i));
}

///////////////////////////////////////////////////////////////

void h1_ex2()
{
	int matA[MAT_A_ROW][MAT_A_COL], matB[MAT_B_ROW][MAT_B_COL]; //predifined size matrix
	int **matC; //ponter to a new matrix to be returned after calcuclating matA*matB
	int i, j; //index i and index j to work with matrix
			  //printf("Enter number for matrix A %dX%d:\n", MAT_A_ROW, MAT_A_COL);

	for (i = 0; i<MAT_A_ROW; i++) //input values for matrix A
		for (j = 0; j < MAT_A_COL; j++)
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
	for (i = 0; i<MAT_B_ROW; i++) //input values for matrix B
		for (j = 0; j < MAT_B_COL; j++)
		{
			//printf("row %d col %d: ", i+1, j+1);
			if (rand() % 2)
				matB[i][j] = rand() % 20;
			else
				matB[i][j] = (rand() % 20)*(-1);
			//scanf("%d", &matB[i][j]);
		}

	printf("\n\nmatrix A:\n");

	for (i = 0; i < MAT_A_ROW; i++)
	{
		for (j = 0; j < MAT_A_COL; j++)
			printf("%d\t", matA[i][j]);
		printf("\n");
	}

	printf("\n\nmatrix B:\n");

	for (i = 0; i < MAT_B_ROW; i++)
	{
		for (j = 0; j < MAT_B_COL; j++)
			printf("%d\t", matB[i][j]);
		printf("\n");
	}

	printf("\n\n");

	matC = matMulti(matA, matB); //send the adressess of matrix A and B to calculate their multiplication and return the address of the new matrix

	printf("\n");
	printf("matrixA X matrixB =\n");

	printMat(matC, MAT_A_ROW, MAT_B_COL);

	printf("\n");
	freeMat(matC, MAT_A_ROW); //free the memorie that was allocated for matrix C
	system("pause");
}

///////////////////////////////////////////////////////////////

int **matMulti(int matA[MAT_A_ROW][MAT_A_COL], int matB[MAT_B_ROW][MAT_B_COL]) //function to calculate the multiplication of two matrixs
{
	int **matC; //pointer for matrix C
	int i, j, m; //index i and j to work with matrix, index m for calculating the multiplication of matA nad matB

	matC = (int**)malloc(sizeof(int*)*MAT_A_ROW);//allocate memory for array of pointers in the size of the rows of matrix A
	for (i = 0; i < MAT_A_ROW; i++) //for each pointer allocate memory for array of number in the size of the cols of matrix B
		*(matC + i) = (int*)calloc(sizeof(int*), MAT_B_COL);//each slot in the new matrix will get initial value of zero

	for (i = 0; i < MAT_A_ROW; i++) //calculate matA*matB by multiplying each row in matA by each col in matB
		for (j = 0; j < MAT_B_COL; j++)
			for (m = 0; m < MAT_A_COL; m++)
				*(*(matC + i) + j) += matA[i][m] * matB[m][j];
	return matC; //return the address of the result matrix C
}

///////////////////////////////////////////////////////////////

void freeMat(int **mat, int row) //function to free the memoery allocated for a dynamic size matrix
{
	int i; //index
	for (i = 0; i < row; i++) //free the memory of each array of numbers (cols)
		free(*(mat + i));
	free(mat); //free the memory of the array of pointers (rows)
}

///////////////////////////////////////////////////////////////

void printMat(int **mat, int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++) //print new matrix C wich shows matA*matB
	{
		for (j = 0; j < col; j++)
			printf("%d\t", *(*(mat + i) + j));
		printf("\n");
	}
}

///////////////////////////////////////////////////////////////

void h1_ex3()
{
	int **mat; //dynamic matrix pointer
	int row, col, i, j, size = 0; //row,col - number of row and cols in matrix, i,j - index, size - number of mat members that equal to i+j
	listT *list; //pointer to list of number of mat members that equal to i+j
	trio *arr;

	list = NULL;
	arr = NULL;

	//printf("Enter number of rows: ");
	//scanf("%d", &row);
	//printf("Enter number of cols: ");
	//scanf("%d", &col);

	row = (rand() % 5) + 1;
	col = (rand() % 5) + 1;

	mat = inputMat(row, col);

	printf("\n\n");
	printf("matrix %dX%d:\n", row, col);
	printMat(mat, row, col);

	printf("\n");

	size = coordSum(mat, row, col, &list, &arr); //function to create a list of matrix members that equal to row + col index and returns the number of memeber found

	if (size) //print the answer if memeber=i+j was found
	{
		printf("list:\n");
		printList3(list);//print the list
		printf("\n");
		printf("array:\n");
		printArrTrio(arr, size);
		printf("the size of the list/arr is %d\n", size);
		printf("\n");
		freeList3(list);//free the memorry was allocated for the list
		free(arr); //free the memorry was allocated for the array
	}
	else //if no members was found (list empty)
		printf("no i+j numbers found in the matrix");

	printf("\n\n");
	freeMat(mat, row); //free the memory was allocated to the dynamic matrix
	system("pause");
}

///////////////////////////////////////////////////////////////

int coordSum(int **mat, int row, int col, listT **list, trio **arr) //function to create a list of matrix members that equal to row + col index and returns the number of memeber found
{
	int i, j, size = 0; //i,j - index, size - number of mat members that equal to i+j
	trio data; //trio struct that contains the index i and j and its sum i+j

	*list = newList(); //create new linked list

	for (i = 0; i<row; i++) //check if the matrix member equeal to its coordinate i+j
		for (j = 0; j < col; j++)
			if (*(*(mat + i) + j) == i + j) //if so save the data of type trio into the list
			{
				data.sum = i + j;
				data.i = i;
				data.j = j;
				addFirst3(*list, data);
				size++;
			}

	*arr = (trio*)malloc(sizeof(trio)*size);

	size = 0;//use size as index for the array
	for (i = 0; i<row; i++) //check if the matrix member equeal to its coordinate i+j
		for (j = 0; j < col; j++)
			if (*(*(mat + i) + j) == i + j) //if so save the data of type trio into the array
			{
				data.sum = i + j;
				data.i = i;
				data.j = j;
				*((*arr) + size) = data;
				size++;
			}

	return size;//return how meny members found
}

int **inputMat(int row, int col)
{
	int **mat;
	int i, j;

	mat = (int**)malloc(sizeof(int*)*row);  //create dynamic matrix in size rowXcol
	for (i = 0; i < row; i++)
		*(mat + i) = (int*)malloc(sizeof(int)*col);
	//printf("Enter numbers for matrix %dX%d:\n", row, col);
	for (i = 0; i<row; i++) //get numbers to matrix
		for (j = 0; j < col; j++)
		{
			//printf("row %d col %d: ", i+1, j+1);
			//scanf("%d", *(mat + i) + j);
			if (rand() % 2)
				*(*(mat + i) + j) = rand() % 10;
			else
				*(*(mat + i) + j) = (rand() % 10)*(-1);
		}
	return mat;
}

///////////////////////////////////////////////////////////////

void printArrTrio(trio *arr, int size)
{
	int i;
	for (i = size - 1; i >= 0; i--) //print the array
		printf("sum: %d\ti: %d\tj: %d\n", (arr + i)->sum, (arr + i)->i, (arr + i)->j);
	printf("\n");
}

///////////////////////////////////////////////////////////////

void h1_ex4()
{
	listT *even, *odd; //even - general list to be list of even numbers in the end, odd - list of odd numbers

	even = newList(); //create new list

	userList(even); //get input of numbers into the list
	printf("user list:\n");
	printList(even);
	printf("\n\n");



	odd = oddEven(even); //function to sort odd/even numbers in the list, returns the address of the odd numbers list

	printf("even list:\n");//print the two lists odd and even
	printList(even);
	printf("\n\n");
	printf("odd list:\n");
	printList(odd);

	freeList(even); //free the memory that was allocated for the lists
	freeList(odd);

	printf("\n\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void userList(listT *list) //function to get numbers into list from user
{
	int x = 0; //x - integer to input into the list
	printf("enter numbers to list:\n");
	while (1) //loop
	{
		x = (rand() % 20) - 1;
		//scanf("%d", &x);
		if (x >= 0) //add number to the list until there is a flag x = -1, without saving -1 to the list
			addFirst(list, x);
		else
			return;
	}
}

///////////////////////////////////////////////////////////////

listT *oddEven(listT* even) //function to sort odd/even numbers in the list, returns the address of the odd numbers list
{
	listT *odd, tempL;//odd - pointer to list of odd numbers, tempL - temp list header to run through the list
	nodeT *node; //temp node to checl list values
	odd = newList(); //create new list

	if (even->head == NULL)//if even list is empty end the function and return empty odd list
		return odd;

	node = even->head; //first node of even list
	tempL.head = node->next; //second node of even list to be temporary head of the list

	while (node->data % 2) //while the first number in the list is odd
	{
		addFirst(odd, node->data); //add it to odd list

		if (node->next) //if there is more than one node in the list then delete the curent node and continue
			freeSingle(even, node);
		else //if this is the last node that delete it and return the odd list
		{
			freeSingle(even, node);
			return odd;
		}
	}

	while (tempL.head) //while temporary head of the list is not NULL
	{
		if (node->next && node->next->data % 2) //check if the next node value is odd as long that there is next node
		{
			addFirst(odd, node->next->data); //ad it to odd list
			if (node->next->next) //if there is a node after that then remove the next node and point the had at the current node
			{
				freeSingle(even, node->next);
				tempL.head = node;
			}
			else //if there is no node after that, delete the last node and return odd list
			{
				freeLast(node);
				return odd;
			}
		}
		else //if the next node value is even then move the head pointer to the next node and the temp node to the current node
		{
			tempL.head = node->next;
			node = tempL.head;
		}
	}

	return odd; //return odd list address
}

///////////////////////////////////////////////////////////////

void h1_ex5()
{
	listT *even, *odd; //even - general list to be list of even numbers in the end, odd - list of odd numbers

	even = newList(); //create new list

	userList(even); //get input of numbers into the list
	printf("user list:\n");
	printList(even);
	printf("\n\n");



	odd = oddEven_noDelete(even); //function to sort odd/even numbers in the list, returns the address of the odd numbers list

	printf("even list:\n");//print the two lists odd and even
	printList(even);
	printf("\n\n");
	printf("odd list:\n");
	printList(odd);

	freeList(even); //free the memory that was allocated for the lists
	freeList(odd);
	printf("\n\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

listT *oddEven_noDelete(listT* even) //function to sort odd/even numbers in the list, returns the address of the odd numbers list
{
	listT *odd, tempL;//odd - pointer to list of odd numbers, tempL - temp list header to run through the list
	nodeT *node, tempN; //temp node to checl list values
	odd = newList(); //create new list

	if (even->head == NULL)//if even list is empty end the function and return empty odd list
		return odd;

	node = even->head; //first node of even list
	tempL.head = node->next; //second node of even list to be temporary head of the list

	while (node->data % 2) //while the first number in the list is odd
	{
		even->head = node->next;//move the node from even list to odd list
		node->next = odd->head;
		odd->head = node;
		if (even->head) //if there is more nodes in the list look at the new first node
		{
			node = even->head;
			tempL.head = node->next;
		}
		else //if there is more than one node in the list then delete the curent node and continue
			return odd;
	}

	while (tempL.head) //while temporary head of the list is not NULL
	{
		if (node->next && node->next->data % 2) //check if the next node value is odd as long that there is next node
		{
			tempN = *node->next; //move the next node from even list to odd list
			node->next->next = odd->head;
			odd->head = node->next;
			node->next = tempN.next;
			tempL.head = node;
		}
		else //if the next node value is even then move the head pointer to the next node and the temp node to the current node
		{
			tempL.head = node->next;
			node = tempL.head;
		}
	}

	return odd; //return odd list address
}

///////////////////////////////////////////////////////////////
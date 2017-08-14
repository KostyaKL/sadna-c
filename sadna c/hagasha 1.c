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

//declaration of functions:
void h1_ex1(); //function for excercise 1
unsigned int *powerArray(int n);

void h1_ex2(); //function for excercise 2

void h1_ex3(); //function for excercise 3

void h1_ex4(); //function for excercise 4

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
	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void h1_ex3()
{
	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void h1_ex4()
{
	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void h1_ex5()
{
	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int class_train_3_ex_1();
int class_train_3_ex_2();
int class_train_3_ex_3();

void lineSwap(int **head,  int line1, int line2);


int class_train_3()
{
	char drill_num[5];
	system("cls");
	printf("Welcome to class train 2 Page!\n"
		"_____________________________\n"
		"1 - Swap lines in matrix\n"
		"2 - Swap columns in matrix\n"
		"3 - dynamic matrix\n"
		"\n"

		"Back - Return to main\n"
		"Quit - Exit\n\n"
		"Enter your choise: ");
	scanf("%s", &drill_num);

	if (strcmp(drill_num, "1") == 0)
	{
		printf("\n");
		class_train_3_ex_1();
	}

	else if (strcmp(drill_num, "2") == 0)
	{
		printf("\n");
		class_train_3_ex_2();
	}

	else if (strcmp(drill_num, "3") == 0)
	{
		printf("\n");
		class_train_3_ex_3();
	}

	else if (strcmp(drill_num, "back") == 0)
	{
		printf("\n");
		return main();
	}

	else if (strcmp(drill_num, "quit") == 0 || strcmp(drill_num, "0") == 0)
	{
		exit(0);
	}

	else
	{
		printf("You have enterd invalid choise\n\n");
		system("pause");
		return class_train_3();
	}
	return main();

}

//////////////////////////////////////////////////////////////////

int class_train_3_ex_1()
{

	printf("\n");
	system("pause");
	return class_train_3();
}

//////////////////////////////////////////////////////////////////

int class_train_3_ex_2()
{

	printf("\n");
	system("pause");

	return class_train_3();
}

//////////////////////////////////////////////////////////////////

int class_train_3_ex_3()
{
	int **row;
	int rowSize, colSize, i, j;
	int lineS1, lineS2;
	
	printf("enter the number of rows you want: ");
	scanf("%d", &rowSize);

	printf("enter the number of cols you want: ");
	scanf("%d", &colSize);

	row = (int**)calloc(sizeof(int*), rowSize);

	for (i = 0;i < rowSize;i++)
		*(row + i) = (int**)calloc(sizeof(int*), colSize);

	for (i = 0;i < rowSize;i++)
		for (j = 0;j < colSize;j++)
		{
			printf("enter number for line %d row %d: ", i, j);
			scanf("%d", *(row + i) + j);
		}
	printf("\n");
	printf("\n");

	for (i = 0;i < rowSize;i++)
	{
		for (j = 0;j < colSize;j++)
		{
			printf("%d	", *(*(row + i) + j));
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");

	printf("Enter the first line you want to swap: ");
	scanf("%d", &lineS1);

	printf("Enter the second line you want to swap: ");
	scanf("%d", &lineS2);

	lineS1--;
	lineS2--;

	lineSwap(&row, lineS1, lineS2);

	printf("\n");
	printf("\n");

	for (i = 0;i < rowSize;i++)
	{
		for (j = 0;j < colSize;j++)
		{
			printf("%d	", *(*(row + i) + j));
		}
		printf("\n");
	}

	printf("\n");
	system("pause");
	
	return class_train_3();
}

//////////////////////////////////////////////////////////////////

void lineSwap(int **head, int line1, int line2)
{
	int *temp;
	
	temp = *(head + line1);
	*(head + line1) = *(head + line2);
	*(head + line2) = temp;
}

//////////////////////////////////////////////////////////////////


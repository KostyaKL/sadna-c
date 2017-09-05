/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Roi Zimon 61108-61
Targil: Ester Amiti 661108-65/69
*/

//rony goodman got a good mark

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void h2_ex1_s(); //function for excercise 1
char **wordByLetter(char *str, char letter, int *size);
void printCharArray(char **arry, int size);
void freeCharArray(char **arry, int size);
//void clearStdi();

void h2_ex2_s(); //function for excercise 2
char *noNumS(char *str);

void h2_ex3_s(); //function for excercise 3

void h2_ex4_s(); //function for excercise 4

void h2_ex5_s(); //function for excercise 5


void hagasha_2_sadna()
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
			case 1: h2_ex1_s();//calling the function for ex 1
				break;
			case 2: h2_ex2_s();//calling the function for ex 2
				break;
			case 3: h2_ex3_s();//calling the function for ex 3
				break;
			case 4: h2_ex4_s();//calling the function for ex 4
				break;
			case 5: h2_ex5_s();//calling the function for ex 5
				break;
			}
		} while (all_Ex_in_loop && select); //determin if the program will return to main menu at the end of an exersice or it will exit
		return main();
}

///////////////////////////////////////////////////////////////

void h2_ex1_s()
{
	char str[MAX], letter, **result;
	int size;

	printf("enter a sentance: ");
	clearStdi();
	gets(str);

	printf("Enter a letter to search: ");
	scanf("%c", &letter);

	result = wordByLetter(str, letter, &size);
	printf("\n");
	printf("Search result:\n");
	printCharArray(result, size);

	printf("\n\n");
	freeCharArray(result, size);
	system("pause");
}

///////////////////////////////////////////////////////////////

char **wordByLetter(char const *str, char letter, int *size)
{
	char **ret, fail[] = "no words found";
	char temp[MAX][MAX] = { 0 };
	int i, j, strSize;

	strSize = strlen(str);
	*size = 0;
	i = 1;
	if (letter > 96)
		letter -= 32;

	while (i <= strSize)
	{
		if ((*(str + i - 1) == letter || *(str + i - 1) == letter + 32) && i == 1)
		{
			j = 0;
			while (*(str + i - 1) != '\0' && *(str + i - 1) != ' ')
			{
				temp[*size][j] = *(str + i - 1);
				i++;
				j++;
			}
			(*size)++;
			i--;
		}
		else if (*(str + i-1) == ' ' && (*(str + i) == letter || *(str + i) == letter + 32))
		{
			j = 0;
			while (*(str + i) != '\0' && *(str + i) != ' ')
			{
				temp[*size][j] = *(str + i);
				i++;
				j++;
			}
			(*size)++;
		}
		i++;
	}

	if (*size)
	{
		ret = (char**)malloc(sizeof(char*)*(*size));
		for (i = 0; i < *size; i++)
		{
			*(ret + i) = (char*)malloc(sizeof(char)*(strlen(temp[i]) + 1));
			for (j = 0; j <= strlen(temp[i]); j++)
			{
				*(*(ret + i) + j) = temp[i][j];
			}
		}
	}
	else
	{
		ret = (char**)malloc(sizeof(char*));
		*ret = (char*)malloc(sizeof(char)*(strlen(fail) + 1));
		for (j = 0; j <= strlen(fail); j++)
		{
			*(*(ret) + j) = fail[j];
		}
	}
	return ret;
}

///////////////////////////////////////////////////////////////

void printCharArray(char **arry, int size)
{
	int i;
	if (size)
	{
		for (i = 0; i < size; i++)
			printf("%s\n", *(arry + i));
	}
	else
	{
		printf("%s\n", *arry);
	}
}

///////////////////////////////////////////////////////////////

void freeCharArray(char **arry, int size)
{
	int i;
	if (size)
	{
		for (i = 0; i < size; i++)
			free(*(arry + i));
	}
	else
	{
		free(*arry);
	}
	free(arry);
}

///////////////////////////////////////////////////////////////

/*void clearStdi()
{
	char input;
	while ((input = getchar()) != '\n' && input != EOF); //clear stdin buffer as long there is items there and entered is pressed
}*/

///////////////////////////////////////////////////////////////

void h2_ex2_s()
{
	char str[MAX], *result;

	printf("enter a sentance: ");
	clearStdi();
	gets(str);

	result = noNumS(str);
	printf("\n");
	printf("Search result:\n");
	printf("%s\n", result);

	printf("\n\n");
	free(result);
	system("pause");
	
}

///////////////////////////////////////////////////////////////

char *noNumS(char *str)
{
	int i, count, size;
	char *ret, temp[MAX] = { 0 };
	size = strlen(str);
	count = 0;
	for (i = 0;i < size;i++)
	{
		if (*(str + i) != ' ' && (*(str + i) < 48 || *(str + i) > 57))
		{
			temp[count] = *(str + i);
			count++;
		}
	}
	ret = (char*)malloc(sizeof(char)*(count + 1));
	for (i = 0;i < count + 1;i++)
	{
		*(ret + i) = temp[i];
	}
	return ret;
}

///////////////////////////////////////////////////////////////

void h2_ex3_s()
{

	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void h2_ex4_s()
{

	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void h2_ex5_s()
{

	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////
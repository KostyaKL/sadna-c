/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Roi Zimon 61108-61
Targil: Ester Amiti 661108-65/69
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 250

void h2_ex1_s(); //function for excercise 1
char **wordByLetter(char *str, char letter, int *size); //function to find all words in a string that start with a specific letter
void printCharArray(char **arry, int size); //print matrix of string
void freeCharArray(char **arry, int size); //free matrix of string
//void clearStdi(); //clear stdin buffer

void h2_ex2_s(); //function for excercise 2
char *noNumS(char *str); //function to remove all spaces and numbers from string
int countRemove(char *str); //function to count the size of string without spaces and numbers

void h2_ex3_s(); //function for excercise 3
char commonestLetter(char *fileName); //function to find the commonest letter in a file
int createFile(char *fileName); //function to create a file

void h2_ex4_s(); //function for excercise 4
void strDecrypter(char *str); //function to decrypt a string

void h2_ex5_s(); //function for excercise 5
void memoForVar(char declaration[], char filename[]); //function to create a file with types of variables and its size
void printMemoFile(char* filename); //function to print a text file
void skipSpace(char *declaration, int *i); //function to skip spaces
void printType(FILE *fin, char *tempVar); //function to print type into file
void getType(FILE *fin, char *declaration, int *i, int *size); //function to get the type and write it to file
void getVar(FILE *fin, char *declaration, int *i, int *size); //function to get the varaible and write it to file

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
}

///////////////////////////////////////////////////////////////

void h2_ex1_s()
{
	char str[MAX], letter, **result; //str - input string, letter - key to search, result - matrix of strings that show the search result
	int size; //size - how many words found

	printf("enter a sentance: ");
	clearStdi(); //clear stdin buffer
	gets(str); //get string from user

	printf("Enter a letter to search: ");
	scanf("%c", &letter); //get letter to search words by

	result = wordByLetter(str, letter, &size); //get the result of the search using wordByLetter() function
	printf("\n");
	printf("Search result:\n");
	printCharArray(result, size); //print the search result

	printf("\n\n");
	freeCharArray(result, size); //free the memory that was allocated for the search result matrix
	system("pause");
}

///////////////////////////////////////////////////////////////

char **wordByLetter(char const *str, char letter, int *size) //function to find all words in a string that start with a specific letter
{
	char **ret, fail[] = "no words found"; //ret - matrix of strings to be returned, fail - return in case of no search results
	int i, j, strSize; // i,j - index, strsize - size of input string

	strSize = strlen(str);
	*size = 0;
	i = 1;
	if (letter > 96) //deal with regular/capital letters as capital letters
		letter -= 32;

	ret = (char**)malloc(sizeof(char*)); //allocate memory for matrix of string

	while (i <= strSize) //go through the whole input string
	{
		if ((*(str + i - 1) == letter || *(str + i - 1) == letter + 32) && i == 1) //if the first letter of the input is the search key
		{
			ret = (char**)realloc(ret, sizeof(char*)*(*size + 1)); //realocate the size of ret by 1 extra slot
			*(ret + *size) = (char*)malloc(sizeof(char)); //allocate memory for found word
			j = 0;
			while (*(str + i - 1) != '\0' && *(str + i - 1) != ' ') //go to the end of the word util space or end of string
			{
				*(ret + *size) = (char*)realloc(*(ret + *size), sizeof(char)*j + 1); //increase the memory size for the word by one for each letter
				*(*(ret + *size) + j) = *(str + i - 1); //enter the letters of found word into the string matrix
				i++;
				j++;
			}
			*(ret + *size) = (char*)realloc(*(ret + *size), sizeof(char)*j + 1);
			*(*(ret + *size) + j) = '\0'; //mark the end of the word when done
			(*size)++; //increase the size by one
			i--;
		}
		else if (*(str + i - 1) == ' ' && (*(str + i) == letter || *(str + i) == letter + 32)) //if the previous char was space and the corrent letter is the search key
		{
			ret = (char**)realloc(ret, sizeof(char*)*(*size + 1)); //realocate the size of ret by 1 extra slot
			*(ret + *size) = (char*)malloc(sizeof(char)*i); //allocate memory for found word
			j = 0;
			while (*(str + i) != '\0' && *(str + i) != ' ') //go to the end of the word util space or end of string
			{
				*(ret + *size) = (char*)realloc(*(ret + *size), sizeof(char)*j + 1); //increase the memory size for the word by one for each letter
				*(*(ret + *size) + j) = *(str + i); //enter the letters of found word into the string matrix
				i++;
				j++;
			}
			*(ret + *size) = (char*)realloc(*(ret + *size), sizeof(char)*j + 1);
			*(*(ret + *size) + j) = '\0'; //mark the end of the word when done
			(*size)++; //increase the size by one
		}
		i++;
	}

	if (*size == 0) //if no words found
	{
		*ret = (char*)malloc(sizeof(char)*(strlen(fail) + 1));
		for (j = 0; j <= strlen(fail); j++) //enter fail[] string to the matrix
		{
			*(*(ret)+j) = fail[j];
		}
	}

	return ret; //return the string matrix by refrence
}

///////////////////////////////////////////////////////////////

void printCharArray(char **arry, int size) //print matrix of string
{
	int i;
	if (size) //if found search result
	{
		for (i = 0; i < size; i++) //print all string
			printf("%s\n", *(arry + i));
	}
	else
	{
		printf("%s\n", *arry); //if there is no search result print the fail[] massege
	}
}

///////////////////////////////////////////////////////////////

void freeCharArray(char **arry, int size) //free matrix of string
{
	int i;
	if (size) //if found search result
	{
		for (i = 0; i < size; i++) //free every string
			free(*(arry + i));
	}
	else
	{
		free(*arry); //if there is no search result free the fail[] string
	}
	free(arry); //free the matrix itself
}

///////////////////////////////////////////////////////////////

/*
void clearStdi() //clear stdin buffer
{
	char input;
	while ((input = getchar()) != '\n' && input != EOF); //clear stdin buffer as long there is items there and entered is pressed
}
*/

///////////////////////////////////////////////////////////////

void h2_ex2_s()
{
	char str[MAX], *result; //str - input string, result - modified string

	printf("enter a sentance: ");
	clearStdi(); //clear stdin buffer
	gets(str); //get input string from user

	result = noNumS(str); //get modofied string using noNumS() function
	printf("\n");
	printf("Search result:\n");
	printf("%s\n", result); //print the modified string

	printf("\n\n");
	free(result); //free result string
	system("pause");

}

///////////////////////////////////////////////////////////////

char *noNumS(char *str) //function to remove all spaces and numbers from string
{
	int i, j, newSize, size; //i,j - index, newSize - size of modified string, size - size of input string
	char *ret; //ret - modified string to be returned
	size = strlen(str); //get the size of input string
	newSize = countRemove(str); //get the size of modified string using countRemove() function
	ret = (char*)malloc(sizeof(char)*(newSize + 1)); //allocate memory for the returned string
	j = 0;
	for (i = 0;i < size&&j<newSize;i++) //chck all chars in input string
	{
		if (*(str + i) != ' ' && (*(str + i) < 48 || *(str + i) > 57)) //copy all chars from input to ret expet spaces and numbers
		{
			*(ret + j) = *(str + i);
			j++;
		}
	}
	*(ret + j) = '\0'; //mark the end of string
	return ret; //return the modified string by refrence
}

///////////////////////////////////////////////////////////////

int countRemove(char *str) //function to count the size of string without spaces and numbers
{
	int i, ret, size; //i - index, ret - size to return, size - size of input string
	ret = 0;
	size = strlen(str);
	for (i = 0;i < size;i++)
	{
		if (*(str + i) != ' ' && (*(str + i) < 48 || *(str + i) > 57)) //if the current char is space or number then don't count it
			ret++;
	}
	return ret; //return new size
}

///////////////////////////////////////////////////////////////

void h2_ex3_s()
{
	char ch = 0;
	if (createFile("input.txt")) //if create file using createFile() function was successful
	{
		ch = commonestLetter("input.txt"); //find the most common letter in file usinf commonestLetter() function
		if (ch)
			printf("the commonest letter is %c\n", ch); //print the letter if it was found
		else
			printf("no letters in the file\n");
	}
	else
		printf("Error creating file\n");

	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

char commonestLetter(char *fileName) //function to find the commonest letter in a file
{
	FILE *input; //input - pointer to file
	char ret, count[26] = { 0 }; //ret - commonest letter, count[] - count array of a-z
	int i, size; //i - index, size - number of chars in file
	ret = -1;
	input = NULL;
	input = fopen(fileName, "r"); //open the file for reading
	if (input) //if file was opened succssefully
	{
		fseek(input, 0, SEEK_END); //go to the end of the file
		size = ftell(input); //get the position of the cursor
		fseek(input, 0, SEEK_SET); //return to the beggining of the file
		for (i = 0;i<size;i++)
		{
			ret = fgetc(input); //get each char from file
			if (ret > 91) //treat all letters (regular/capital) as capital
				ret -= 32;
			if (ret > 64 && ret < 91) //if the char is a letter the add a count in its position in the count array
				count[ret - 65]++;
		}
		fclose(input); //close the file
		ret = 0; //if no letter found return 0
		for (i = 0;i < 26;i++)
		{
			if (count[ret] <= count[i]) //find the index with most count
				ret = i;
		}
		ret += 65; //refer the index to its ascii letter
	}
	else //if couldn't open file return 0
		ret = 0;
	return ret; //return the letter found
}

///////////////////////////////////////////////////////////////

int createFile(char *fileName) //function to create a file
{
	FILE *input; //input - pointer to file
	int flag; //flag - is file creation was successfull
	char str[MAX]; //str - user input into the file
	flag = EOF;
	input = NULL;
	input = fopen(fileName, "w"); //create/open file for writing
	if (input) //if creation/opening of file was successfull
	{
		printf("Enter data into text file:\n");
		clearStdi();
		gets(str); //get input from user
		flag = fputs(str, input); //put the user input into the file, if succesfull returns a number, if not returns EOF
		fclose(input); //close the file
	}
	if (flag == EOF) //if writing/file creation failed then flag is 0
		flag = 0;
	else
		flag = 1; //if succesffull flag is 1
	return flag; //return flag
}

///////////////////////////////////////////////////////////////

void h2_ex4_s()
{
	char str[MAX]; //str - input string from user
	printf("Enter encrypted string:\n");
	clearStdi();
	gets(str); //get encrypted string from user
	strDecrypter(str); //decrypt the string using strDecrypter() function
	printf("Decrypted string:\n%s\n", str); //print decrypted string

	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void strDecrypter(char *str) //function to decrypt a string
{
	int i, j, size; //i,j - index, size - size of input string
	size = strlen(str);
	i = 1;
	while (i <= size)
	{
		if (*(str + i - 1) != ' ') //handle first word
		{
			j = 1;
			while (*(str + i - 1) != '\0' && *(str + i - 1) != ' ') //for each letter until end of word
			{
				*(str + i - 1) -= j; //for each char aplly -j to ascii value of char
				i++;
				j++;
			}
			i--;
		}
		else if (*(str + i - 1) == ' ') //for every word
		{
			j = 1;
			while (*(str + i) != '\0' && *(str + i) != ' ') // for each letter until end of word
			{
				*(str + i) -= j; //for each char aplly -j to ascii value of char
				i++;
				j++;
			}
		}
		i++;
	}
}

///////////////////////////////////////////////////////////////

void h2_ex5_s()
{
	char declaration[MAX];

	printf("Enter your declaration:\n");
	clearStdi();
	gets(declaration);
	memoForVar(declaration, "input.txt"); //create file with types and variables size using memoForVar() function

	printf("\n");
	system("pause");
}

///////////////////////////////////////////////////////////////

void memoForVar(char declaration[], char filename[]) //function to create a file with types of variables and its size
{
	int size, i; //size - size of type, i - index
	FILE *fin; //fin - pointer to file

	fin = fopen(filename, "w"); //open\create file for writting
	if (fin) //if file open was successfull
	{
		i = 0;
		while (declaration[i] != '\0') //check current char in file
		{
			size = 0;
			getType(fin, declaration, &i, &size); //get type from string and write it to file using getType() function
			getVar(fin, declaration, &i, &size); //get variable from string and write it to file using getType() function
		}
		fclose(fin); //close file	
		printf("\n");
		printMemoFile("input.txt"); //print the file using printMemoFile() function
	}
	else
		printf("\nError handling file\n"); //if file could not be openned
}

///////////////////////////////////////////////////////////////

void printMemoFile(char* filename) //function to print a text file
{
	FILE *fin; //fin - pointer to file
	char str[MAX]; //str - temp string
	int size = 0; //i - index, size - number of chars in the file

	fin = fopen(filename, "r"); //open file for reading
	if (fin)
	{
		fseek(fin, 0, SEEK_END); //go to the end of the file
		size = ftell(fin); //get the position of the cursor
		fseek(fin, 0, SEEK_SET); //return to the beggining of the file

		while (ftell(fin) != size) //as long as the cursor didn't reach the end of file
		{
			fgets(str, MAX, fin);
			printf("%s", str); //print each line
		}

		printf("\n");

		fclose(fin); //close the file
	}
	else
		printf("Error reading the file\n");
}

///////////////////////////////////////////////////////////////

void skipSpace(char *declaration, int *i) //function to skip spaces
{
	while (declaration[*i] == ' ')
		(*i)++;
}

///////////////////////////////////////////////////////////////

void printType(FILE *fin, char *tempVar) //function to print type into file
{
	int size, i;
	size = strlen(tempVar);

	fprintf(fin, "\nsizeof (%s): \n", tempVar); //print the type into file
	for (i = 0;i < size + 10;i++)
		fprintf(fin, "-");
	fprintf(fin, "\n\t");
}

///////////////////////////////////////////////////////////////

void getType(FILE *fin, char *declaration, int *i, int *size) //function to get the type and write it to file
{
	char tempVar[MAX] = " "; //temVar - string to identify type
	int k; //k-index
	k = 0;

	skipSpace(declaration, i); //skip space

	while (declaration[*i] != ' ') //get teype into tempVar                              
	{
		tempVar[k] = declaration[*i];
		(*i)++;
		k++;
	}
	tempVar[k] = '\0';

	if (!strcmp(tempVar, "int")) //check the type and deside its size
		*size = sizeof(int);

	else if (!strcmp(tempVar, "char"))
		*size = sizeof(char);

	else if (!strcmp(tempVar, "short"))
		*size = sizeof(short);

	else if (!strcmp(tempVar, "long"))
	{
		*size = sizeof(long);

		if (declaration[*i + 1] == 'l' && declaration[*i + 2] == 'o' && declaration[*i + 3] == 'n' && declaration[*i + 4] == 'g' && declaration[*i + 5] == ' ')
		{ // checking for long long
			tempVar[k] = declaration[*i];
			(*i)++;
			k++;
			while (declaration[*i] != ' ')
			{
				tempVar[k] = declaration[*i];
				(*i)++;
				k++;
			}
			tempVar[k] = '\0';
			*size = sizeof(long long);
		}
	}

	else if (!strcmp(tempVar, "float"))
		*size = sizeof(float);

	else if (!strcmp(tempVar, "double"))
		*size = sizeof(double);

	printType(fin, tempVar); //print the type into file using printType() function
}

///////////////////////////////////////////////////////////////

void getVar(FILE *fin, char *declaration, int *i, int *size) //function to get the varaible and write it to file
{
	char tempArr[MAX] = " "; //tempArr - string to identify size of array
	int j, flag, arr_size; //j - index, flag - when to write var size, arr_size - size of array
	arr_size = 0;

	while (declaration[*i] != ';' && declaration[*i] != '\0')  //get variables
	{
		skipSpace(declaration, i); //skip space

		while ((declaration[*i] != ',') && (declaration[*i] != ';'))
		{
			flag = 1;
			skipSpace(declaration, i); //skip space

			if (declaration[*i] == '*')  // if it's a pointer
			{
				while ((declaration[*i] != ',') && (declaration[*i] != ';') && (declaration[*i] != ' '))
				{
					fprintf(fin, "%c", declaration[*i]); //print the pointer into file
					(*i)++;
				}
				fprintf(fin, " requires 4 bytes\n\t"); //print pointer size into file
				if (declaration[*i] != ';')
					(*i)++;
				flag = 0; //don't print the size again
				skipSpace(declaration, i); //skip space
			}

			if (declaration[*i] == '[') // if it's an array
			{
				fprintf(fin, "%c", declaration[*i]);
				(*i)++;
				j = 0;
				while (declaration[*i] != ']') //get array size into tempArr
				{
					tempArr[j] = declaration[*i];
					fprintf(fin, "%c", declaration[*i]);
					(*i)++;;
					j++;
				}
				tempArr[j] = '\0';
				arr_size = atoi(tempArr); //save array size as integer
			}
			if (flag && declaration[*i] != ';' && declaration[*i] != ',')
			{
				fprintf(fin, "%c", declaration[*i]);
				(*i)++;
			}
		}

		if (flag) //if flag is 1
		{
			if (arr_size) //if arr_size not 0
			{
				fprintf(fin, " requires %d bytes\n\t", *size*arr_size); //print array size
				arr_size = 0; //zeroize arr_size
			}
			else
				fprintf(fin, " requires %d bytes\n\t", *size); //print size of type
		}

		if (declaration[*i] != ';') //if not end of line goto next char
			(*i)++;

		skipSpace(declaration, i); //skip space
	}
	(*i)++;
	skipSpace(declaration, i); //skip space
}

///////////////////////////////////////////////////////////////
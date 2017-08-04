#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int class_train_2_ex_1();
int class_train_2_ex_2();
int class_train_2_ex_3();

char input_name();
void free_mem(char *, int);


int class_train_2()
{
	char drill_num[5];
	system("cls");
	printf("Welcome to class train 2 Page!\n"
		"_____________________________\n"
		"1 - ****\n"
		"2 - ****\n"
		"3 - Names list\n"
		"\n"

		"Back - Return to main\n"
		"Quit - Exit\n\n"
		"Enter your choise: ");
	scanf("%s", &drill_num);

	if (strcmp(drill_num, "1") == 0)
	{
		printf("\n");
		class_train_2_ex_1();
	}

	else if (strcmp(drill_num, "2") == 0)
	{
		printf("\n");
		class_train_2_ex_2();
	}

	else if (strcmp(drill_num, "3") == 0)
	{
		printf("\n");
		class_train_2_ex_3();
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
		return class_train_2();
	}
	return main();

}

//////////////////////////////////////////////////////////////////

int class_train_2_ex_1()
{
	
	printf("\n");
	system("pause");
	return class_train_2();
}

//////////////////////////////////////////////////////////////////

int class_train_2_ex_2()
{
	
	printf("\n");
	system("pause");

	return class_train_2();
}

//////////////////////////////////////////////////////////////////

int class_train_2_ex_3()
{
	char *list;
	int size = 2, i = 0;

	list = (char*)calloc(sizeof(char*),size);

	while (*(list + i) = input_name())
	{
		if (i == size-1)
		{
			size = size * 2;
			list = (char*)realloc(list, sizeof(char*)*size);
		}
		i++;
	}

	for (size = 0;size < i;size++)
		printf("%c\n", *(list + size));

	printf("\n");
	system("pause");
	free_mem(list, i);
	free(list);
	return class_train_2();
}

//////////////////////////////////////////////////////////////////

char input_name()
{
	char name[256] = { 0 }, *ret;
	printf("enter a name: ");
	scanf("%s", name);
	if (name[0] == '0')
		return 0;
	ret = (char*)malloc(sizeof(char)*strlen(name)+1);
	strcpy(ret, name);
	return ret;
}

//////////////////////////////////////////////////////////////////

void free_mem(char *arr, int size)
{
	int i;
	for (i = 0;i < size;i++)
		free(arr + i);
}
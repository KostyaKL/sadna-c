#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int class_train_4_ex_1();
int class_train_4_ex_2();
int class_train_4_ex_3();




int class_train_4()
{
	char drill_num[5];
	system("cls");
	printf("Welcome to class train 2 Page!\n"
		"_____________________________\n"
		"1 - ****\n"
		"2 - ****\n"
		"3 - ****\n"
		"\n"

		"Back - Return to main\n"
		"Quit - Exit\n\n"
		"Enter your choise: ");
	scanf("%s", &drill_num);

	if (strcmp(drill_num, "1") == 0)
	{
		printf("\n");
		class_train_4_ex_1();
	}

	else if (strcmp(drill_num, "2") == 0)
	{
		printf("\n");
		class_train_4_ex_2();
	}

	else if (strcmp(drill_num, "3") == 0)
	{
		printf("\n");
		class_train_4_ex_3();
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
		return class_train_4();
	}
	return main();

}

//////////////////////////////////////////////////////////////////

int class_train_4_ex_1()
{

	printf("\n");
	system("pause");
	return class_train_4();
}

//////////////////////////////////////////////////////////////////

int class_train_4_ex_2()
{

	printf("\n");
	system("pause");

	return class_train_4();
}

//////////////////////////////////////////////////////////////////

int class_train_4_ex_3()
{


	printf("\n");
	system("pause");

	return class_train_4();
}

//////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char lab_name[5] = "";

	system("cls");
	printf("Welcome to Lab select page!\n");
	printf("______________________________________\n");
	printf("Choose which lab you want to display:\n");
	printf(""
		"1.1 - NOT YET\n"
		"\n"

		"2.1 - Class Train 1\n"
		"\n"

		"3.1 - NOT YET\n"
		"\n"

		"4 - Ascii\n"
		"5 - Test\n"
		"6 - Console commands\n"
		"7 - Misc\n"
		"8 - Pause\n\n"

		"Exit - Quit\n");
	printf("Enter your choise: ");

	scanf("%s", &lab_name);
	printf("\n");


	if (strcmp(lab_name, "1.1") == 0)
	{
		printf("\n");
		lab1();
	}

	else if (strcmp(lab_name, "1.2") == 0)
	{
		printf("\n");
		lab2();
	}

	else if (strcmp(lab_name, "1.3") == 0)
	{
		printf("\n");
		lab3_4();
	}

	else if (strcmp(lab_name, "1.5") == 0)
	{
		printf("\n");
		lab5();
	}

	else if (strcmp(lab_name, "1.6") == 0)
	{
		printf("\n");
		lab6();
	}

	else if (strcmp(lab_name, "1.7") == 0)
	{
		printf("\n");
		lab7();
	}

	else if (strcmp(lab_name, "1.8") == 0)
	{
		printf("\n");
		lab8();
	}

	else if (strcmp(lab_name, "1.9") == 0)
	{
		printf("\n");
		lab9();
	}

	else if (strcmp(lab_name, "1.10") == 0)
	{
		printf("\n");
		lab10();
	}

	else if (strcmp(lab_name, "1.11") == 0)
	{
		printf("\n");
		lab11();
	}

	else if (strcmp(lab_name, "1.12") == 0)
	{
		printf("\n");
		lab12();
	}

	else if (strcmp(lab_name, "1.13") == 0)
	{
		printf("\n");
		lab13();
	}

	else if (strcmp(lab_name, "2.1") == 0)
	{
		printf("\n");
		self_train1();
	}

	else if (strcmp(lab_name, "2.2") == 0)
	{
		printf("\n");
		self_train2();
	}

	else if (strcmp(lab_name, "2.3") == 0)
	{
		printf("\n");
		self_train3();
	}

	else if (strcmp(lab_name, "3.1") == 0)
	{
		printf("\n");
		hagasha_1();
	}

	else if (strcmp(lab_name, "3.2") == 0)
	{
		printf("\n");
		hagasha_2();
	}

	else if (strcmp(lab_name, "3.3") == 0)
	{
		printf("\n");
		hagasha_3();
	}

	else if (strcmp(lab_name, "quit") == 0 || strcmp(lab_name, "0") == 0)
	{
		exit(0);
	}

	else if (strcmp(lab_name, "4") == 0)
	{
		printf("\n");
		ascii();
	}

	else if (strcmp(lab_name, "5") == 0)
	{
		printf("\n");
		testim();
	}

	else if (strcmp(lab_name, "6") == 0)
	{
		printf("\n");
		printf("Enter console command: ");
		cmd();
	}

	else if (strcmp(lab_name, "7") == 0)
	{
		printf("\n");
		misc();
	}

	else if (strcmp(lab_name, "8") == 0)
	{
		printf("\n");
		system("pause");
	}

	else
	{
		printf("You have enterd invalid lab name\n\n");
		system("pause");
		return main();

	}

	return 0;
}

//////////////////////////////////////////////////////////////////////

int ascii()
{
	char ch1, ch2, ch3, ch4, ch5, ch6;

	ch1 = -128;
	ch2 = ch1 + 1;
	ch3 = ch2 + 1;
	ch4 = ch3 + 1;
	ch5 = ch4 + 1;
	ch6 = ch5 + 1;

	while (ch1 < 126)
	{
		printf("%c - %d			%c - %d			"
			"%c - %d			%c - %d			"
			"%c - %d			%c - %d\n", ch1, ch1, ch2, ch2, ch3, ch3, ch4, ch4, ch5, ch5, ch6, ch6);
		ch1 += 6;
		ch2 += 6;
		ch3 += 6;
		ch4 += 6;
		ch5 += 6;
		ch6 += 6;
	}

	system("pause");
	return main();

}

////////////////////////////////////////////////////////////////////////////

int testim()
{


	printf("1\n");
	system("pause");
	return main();
}

////////////////////////////////////////////////////////////////////////////

int cmd()
{
	char cmmd[50];
	scanf("%s", &cmmd);
	if (strcmp(cmmd, "quit") == 0)
	{
		return main();
	}

	if (strcmp(cmmd, "clear") == 0)
	{
		system("cls");
		return cmd();
	}

	printf("\n");
	system(cmmd);
	printf("\n");
	return cmd();
}
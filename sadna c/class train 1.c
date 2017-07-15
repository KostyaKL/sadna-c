#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int class_train_1_ex_1();
int class_train_1_ex_2();
int class_train_1_ex_3();
int class_train_1_ex_4();




int class_train_1()
{
	char drill_num[5];
	system("cls");
	printf("Welcome to class train 1 Page!\n"
		"_____________________________\n"
		"1 - Sum odd index numbers\n"
		"2 - Election program\n"
		"3 - No repeat numbers array\n"
		"4 - ***\n"
		"\n"

		"Back - Return to main\n"
		"Quit - Exit\n\n"
		"Enter your choise: ");
	scanf("%s", &drill_num);

	if (strcmp(drill_num, "1") == 0)
	{
		printf("\n");
		class_train_1_ex_1();
	}

	else if (strcmp(drill_num, "2") == 0)
	{
		printf("\n");
		class_train_1_ex_2();
	}

	else if (strcmp(drill_num, "3") == 0)
	{
		printf("\n");
		class_train_1_ex_3();
	}

	else if (strcmp(drill_num, "4") == 0)
	{
		printf("\n");
		class_train_1_ex_4();
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
		return class_train_1();
	}
	return main();

}

//////////////////////////////////////////////////////////////////

int class_train_1_ex_1()
{
	int size, *arr, i, sum = 0;
	printf("enter the size of the array: ");
	do
	{
		scanf("%d", &size);
		if (size <= 1)
			printf("Enter a positive number\n");
	} while (size <= 0);
	arr = (int*)malloc(sizeof(int)*size);

	printf("enter %d numbers:\n", size);
	for (i = 0; i < size; i++)
		scanf("%d", arr + i);

	for (i = 0; i < size; i++)
		if (i % 2 == 0)
			sum += *(arr + i);
	printf("\nthe sum of odd index numbers is: %d\n", sum);

	printf("\n");
	system("pause");
	free(arr);
	return class_train_1();
}

//////////////////////////////////////////////////////////////////

int class_train_1_ex_2()
{
	int *moamad, voter, i, v_size, m_size, winner = 0, flag = 0;
	printf("Welcome to voting count system!\n");
	printf("-------------------------------\n");

	printf("Enter the number of candidates: ");
	do {
		scanf("%d", &m_size);
		if (m_size < 1)
			printf("you must enter a positive number\n");
	} while (m_size < 1);

	printf("Enter the number of voters: ");
	do {
		scanf("%d", &v_size);
		if (v_size < 1)
			printf("you must enter a positive number\n");
	} while (v_size < 1);

	moamad = (int*)calloc(sizeof(int), m_size);


	printf("Enter each voters choise (0 for not voted):\n");
	for (i = 0; i < v_size; i++)
	{
		printf("Voter %d choise: ", i + 1);
		do {
			scanf("%d", &voter);
			if (voter < 0 || voter > m_size)
				printf("you must enter a number between 0-%d\n", m_size);
		} while (voter < 0 || voter > m_size);

		if (voter != 0)
			*(moamad + voter - 1) += 1;
	}

	printf("The results are:\n");
	for (i = 0; i < m_size; i++)
		printf("candidate %d got %d votes\n", i + 1, *(moamad + i));

	for (i = 0; i < m_size; i++)
		if (*(moamad + winner) < *(moamad + i))
			winner = i;
	for (i = 0; i < m_size; i++)
		if (i != winner)
			if (*(moamad + winner) == *(moamad + i))
				flag++;


	if (flag == 0)
		printf("the winner is candidate %d\n", winner + 1);
	else
		printf("its a tie, go vote again!!!\n");

	printf("\n");
	system("pause");
	free (moamad);
	return class_train_1();
}

//////////////////////////////////////////////////////////////////

int class_train_1_ex_3()
{
	int *o_arr, *n_arr, o_size, n_size=1, i=0,j=1;

	printf("Enter the size of your array: ");
	do {
		scanf("%d", &o_size);
		if (o_size < 2)
			printf("You must enter an array size grater then 1\n");
	} while (o_size < 2);

	o_arr = (int*)malloc(sizeof(int)*o_size);

	printf("Enter %d numbers in to the array from small to large:\n", o_size);
	scanf("%d", o_arr + i);
	for (i = 1;i < o_size;i++)
	{
		do {
			scanf("%d", o_arr + i);
			if (*(o_arr + i) < *(o_arr + i - 1))
				printf(" you must enter a number >= of %d\n", *(o_arr + i - 1));
		} while (*(o_arr + i) < *(o_arr + i - 1));
		if (*(o_arr + i) != (*(o_arr + i - 1)))
			n_size++;
	}

	n_arr = (int*)malloc(sizeof(int)*n_size);
	*(n_arr) = *(o_arr);

	for (i = 1;i < o_size;i++)
		if (*(o_arr + i) != (*(o_arr + i - 1)))
			*(n_arr + j++) = *(o_arr + i);
		
		
	printf("\nThe new array is:\n");
	for (i = 0;i < n_size;i++)
		printf("%d\n", *(n_arr + i));
	

	printf("\n");
	system("pause");
	free(o_arr);
	free(n_arr);
	return class_train_1();
}

//////////////////////////////////////////////////////////////////

int class_train_1_ex_4()
{
	

	printf("\n");
	system("pause");
	return class_train_1();
}

//////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct list
{
	int data;
	struct list *next;
} listT;

listT* creatListT(int x);
listT* addNum(listT *node, int x);
void printList(listT *list);
void deletList(listT *list);

int class_train_5_ex_1();
int class_train_5_ex_2(listT *list, int *sum, int *min, int *max);




int class_train_5()
{
	char drill_num[5];
	system("cls");
	printf("Welcome to class train 2 Page!\n"
		"_____________________________\n"
		"1 - odd even linked list\n"
		"2 - ****\n"
		"\n"

		"Back - Return to main\n"
		"Quit - Exit\n\n"
		"Enter your choise: ");
	scanf("%s", &drill_num);

	if (strcmp(drill_num, "1") == 0)
	{
		printf("\n");
		class_train_5_ex_1();
	}

	else if (strcmp(drill_num, "2") == 0)
	{
		printf("\n");
		class_train_5_ex_2(NULL,0,0,0);
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
		return class_train_5();
	}
	return main();

}

//////////////////////////////////////////////////////////////////

int class_train_5_ex_1()
{
	int x = 0, count = 0, sum=0,min=0,max=0;
	listT *listOdd;
	listT *listEven;

	listOdd = creatListT(0);
	listEven = creatListT(0);

	printf("Enter numbers to your list: ");
	scanf("%d", &x);

	while (x != -1)
	{
		if (x % 2)
			listOdd = addNum(listOdd, x);
		else
			listEven = addNum(listEven, x);
		count++;
		printf("Enter numbers to your list: ");
		scanf("%d", &x);
	}

	printf("you have entered %d numbers\n\n", count);
	printList(listOdd);
	printf("\n\n");
	printList(listEven);
	printf("\n\n");

	class_train_5_ex_2(listOdd, &sum, &min, &max);
	printf("The sum of odd list is: %d\n"
		"min number: %d\n"
		"max number: %d\n\n", sum, min, max);

	class_train_5_ex_2(listEven, &sum, &min, &max);
	printf("The sum of even list is: %d\n"
		"min number: %d\n"
		"max number: %d\n\n", sum, min, max);

	deletList(listOdd);
	deletList(listEven);

	printf("\n");
	system("pause");
	return class_train_5();
}

//////////////////////////////////////////////////////////////////

int class_train_5_ex_2(listT *list, int *sum, int *min, int *max)
{
	listT *temp;

	temp = list;
	*min = *max = temp->data;
	*sum = 0;
	while (temp->next)
	{
		if (temp->data <= *min)
			*min = temp->data;
		else if (temp->data >=*max)
			*max = temp->data;
		*sum += temp->data;
		temp = temp->next;
	}

	printf("\n");
	//system("pause");

	//return class_train_5();
}

//////////////////////////////////////////////////////////////////

listT* creatListT(int x)
{
	listT *list;
	list = (listT*)malloc(sizeof(listT));
	list->data = x;
	list->next = NULL;
	return list;
}

//////////////////////////////////////////////////////////////////

listT* addNum(listT *node, int x)
{
	listT *tempNode;
	tempNode = (listT *)malloc(sizeof(listT));
	tempNode->data = x;
	tempNode->next = node;
	return tempNode;
}

//////////////////////////////////////////////////////////////////

void printList(listT *list)
{
	listT *temp;
	temp = list;

	do
	{
		printf("%d, ", temp->data);
		temp = temp->next;
	} while (temp->next);

}

//////////////////////////////////////////////////////////////////

void deletList(listT *list)
{
	listT *temp1;
	listT *temp2;
	temp1 = list;
	while (temp1->next)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		free(temp2);
	} 
}

//////////////////////////////////////////////////////////////////
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
#include "exercise_3.h"

void enterEmployee(char *filename) {
	FILE *file;
	eMployee tmp;
	tmp.code = 1;
	file = NULL;
	file = fopen(filename, "w");
	if (file) {
		printf("Enter employee data\n"
			"employee code '0' to finish\n\n");
		while (1) {
			printf("code: ");
			scanf("%d", &tmp.code);
			if (!tmp.code)
				return;
			printf("name: ");
			clearStdi();
			scanf("%s", tmp.name);
			printf("salary: ");
			scanf("%lf", &tmp.salary);
			
		}
		fclose(file);
	}
	else {
		printf("Error openning file\n");
	}
}

///////////////////////////////////////////////////////////////

void updateSalary(char *filename, float threshold) {

}

///////////////////////////////////////////////////////////////

void printEmployeeFile(char *filename) {

}

///////////////////////////////////////////////////////////////

char *codingToShortString(char *dig_str) {
	int strSize, retSize, i, flag;
	char *ret, *temp;
	strSize = strlen(dig_str);
	if (strSize) {
		if (strSize > 1 && *dig_str == '0') {
			printf("illegal input\n\n");
			return 0;
		}
		if (strSize % 2) {
			retSize = strSize * 4 + 4;
			flag = 1;
		}
		else {
			retSize = strSize * 4;
			flag = 0;
		}
		ret = (char*)calloc(retSize+1, sizeof(char));
		if (flag) {
			for (i = 0;i < 4;i++) {
				ret[i] = '0';
			}
		}
		for (i = strSize-1;i >= 0;i--) {
			if (dig_str[i] < 48 || dig_str[i] >57) {
				printf("illegal input\n\n");
				return 0;
			}
			
			temp = dec_to_bin(*(dig_str + i));
			str_cpy((ret + i * 4 + flag * 4), temp);
			free(temp);
		}
	}
	else {
		printf("Error getting dig_str size\n\n");
		return 0;
	}
	return ret;
}

void str_cpy(char *to, char *from) {
	int i;
	for (i = 0;i < 4;i++) {
		to[i] = from[i];
	}
}

char *dec_to_bin(char num) {
	int i;
	char *ret;
	ret = (char*)malloc(5 * sizeof(char));
	num -= 48;
	ret[4] = '\0';
	for (i = 3;i >= 0;i--) {
		ret[i] = num % 2+48;
		num /= 2;
	}
	return ret;
}

///////////////////////////////////////////////////////////////

void displayShortString(char *short_dig_str) {
	int strSize, i, num, flag, exp;
	strSize = strlen(short_dig_str);
	flag = 1;

	for (i = 0;i < 3;i++) {
		if (short_dig_str[i] != '0')
			flag = 0;
	}

	if (flag) {
		for (i = 0;i <= strSize-4;i++)
		{
			*(short_dig_str + i) = *(short_dig_str + i + 4);
		}
		strSize = strlen(short_dig_str);
	}
	num = 0;
	exp = 1;
	for (i = strSize - 1;i >= 0;i--) {
		if (!((i+1) % 4)) {
			exp *= 10;
		}
		num += exp*(short_dig_str[i]-48)*pow2((i+3) % 4);
	}
	printf("%d = %s\n", num, short_dig_str);
}

int pow2(int x) {
	int ret, i;
	ret = 1;
	for (i = 0;i < x;i++) {
		ret *= 2;
	}
	return ret;
}

///////////////////////////////////////////////////////////////

void fillBoard(board bin_board) {
	int i, j;
	for (i = 0;i < SIZE;i++)
		for (j = 0;j < SIZE;j++)
			bin_board[i][j] = rand()%2;

	for (i = 0;i < SIZE;i++) {
		for (j = 0;j < SIZE;j++)
			printf("%d  ", bin_board[i][j]);
		printf("\n");
	}
	printf("\n");
}

///////////////////////////////////////////////////////////////

unsigned long long boardToBits(board bin_board) {
	int i, j, count;
	unsigned long long ret;
	count = 0;
	ret = 0;
	for (i = SIZE - 1;i >= 0;i--) {
		for (j = SIZE - 1;j >= 0;j--) {
			ret += bin_board[i][j] * pow2(count);
			count++;
		}
	}
	return ret;
}

///////////////////////////////////////////////////////////////

void displayBinaryBoard(unsigned long long coded_bin_board) {
	int i, j;
	board bin_board;
	for (i = SIZE - 1;i >= 0;i--) {
		for (j = SIZE - 1;j >= 0;j--) {
			bin_board[i][j] = coded_bin_board % 2;
			coded_bin_board /= 2;
		}
	}

	for (i = 0;i < SIZE;i++) {
		for (j = 0;j < SIZE;j++)
			printf("%d  ", bin_board[i][j]);
		printf("\n");
	}
	printf("\n");
}

///////////////////////////////////////////////////////////////

void clearStdi() { //function to clear the system input buffer
	char input;
	while ((input = getchar()) != '\n' && input != EOF); //clear stdin buffer as long there is items there and entered is pressed
}

///////////////////////////////////////////////////////////////
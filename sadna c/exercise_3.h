/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Roi Zimon 61108-61
Targil: Ester Amiti 661108-65/69
*/

#pragma once

#define SIZE 6

#define MAX_FN 30

typedef struct employee {
	int code;
	char name[15];
	float salary;
}eMployee;

typedef char board[SIZE][SIZE];

///////////////////////////////////////////////////////////////

void enterEmployee(char *filename);

void updateSalary(char *filename, float threshold);

void printEmployeeFile(char *filename);

///////////////////////////////////////////////////////////////

char *codingToShortString(char *dig_str);

char *dec_to_bin(char num);

void displayShortString(char *short_dig_str);

void str_cpy(char *to, char *from);

int pow2(int x);

///////////////////////////////////////////////////////////////

void fillBoard(board bin_board);

unsigned long long boardToBits(board bin_board);

void displayBinaryBoard(unsigned long long coded_bin_board);

///////////////////////////////////////////////////////////////

void clearStdi(); //function to clear the system input buffer

///////////////////////////////////////////////////////////////
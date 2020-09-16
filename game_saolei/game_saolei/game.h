#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>

#define MAX_VALUE_OF_BOARD 11
#define EASY 15
#define MID 30
#define DIFFICULT 50
//
//
void init(char[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD], char element);
void lay_mines(char board[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],int num);
void display_board(char board[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD]);
void display_menue();
void choice_grade(char board1[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD], char board2[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD]);
void play(char board1[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD], char board2[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],int grade);
int check_local(int cow, int rol, char board1[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD], char board2[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],int grade);
static int check(char board2[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],int grade);
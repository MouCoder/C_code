#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//初始化
void init(char board[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD], char element)
{
	int i, j;
	for (i = 0; i < MAX_VALUE_OF_BOARD; i++)
		for (j = 0; j < MAX_VALUE_OF_BOARD; j++)
			board[i][j] = element;
}

//布雷
void lay_mines(char board[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],int num)
{
	//产生两个随机数，确定布雷位置
	int cow, rol;//定义行和列数
	int count = 0;
	do
	{
		//产生1-MAX_VALUE_OF_BOARD的随机数
		cow = (rand() % (MAX_VALUE_OF_BOARD - 2) + 1);
		rol = (rand() % (MAX_VALUE_OF_BOARD - 2) + 1);
		if (board[cow][rol] == 'N')
		{
			board[cow][rol] = 'Y';
			count++;
		}
	} while (count != num);
}

//显示布置好雷的棋盘棋盘
void display_board(char board[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD])
{
	int cow, rol;
	int i;
	//打印列号
	printf("  ");
	for (i = 1; i <= MAX_VALUE_OF_BOARD - 2; i++)
		printf("%d", i);
	printf("\n");
	for (cow = 1; cow < MAX_VALUE_OF_BOARD - 1; cow++)
	{
		printf("%d|", cow);
		for (rol = 1; rol < MAX_VALUE_OF_BOARD - 1; rol++)
		{
			printf("%c", board[cow][rol]);
		}
		printf("\n");
	}
}

//打印菜单
void display_menue()
{
	printf("*******************************\n");
	printf("**********1.开始游戏***********\n");
	printf("**********2.结束游戏***********\n");
	printf("*******************************\n");
	printf("请选择:>");
}

//选择游戏等级
void choice_grade(char board1[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],char board2[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD])
{
	int choice2;//选择游戏等级
	int grade;
	do{
		printf("*******************************\n");
		printf("**********1.简单***************\n");
		printf("**********2.中等***************\n");
		printf("**********3.困难***************\n");
		printf("*******************************\n");
		printf("请选择:>");
		scanf("%d", &choice2);
		switch (choice2)
		{
		case 1:
			grade = EASY;
			//布雷
			lay_mines(board1, grade);
			//开始游戏
			play(board1, board2,grade);
			break;
		case 2:
			grade = MID;
			//布雷
			lay_mines(board1, grade);
			//开始游戏
			play(board1, board2,grade);
			break;
		case 3:
			grade = DIFFICULT;
			//布雷
			lay_mines(board1, grade);
			//开始游戏
			play(board1, board2, grade);
			break;
		default:printf("输入有误，请重新输入\n");
		}
	} while (choice2 != 1 && choice2 != 2 && choice2 != 3);
}

//玩游戏
void play(char board1[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],char board2[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],int grade)
{
	display_board(board2);
	int cow, rol;
	int count = 0;
	//int judge;
	do
	{
		count = 0;
		printf("请输入合法的位置:>");
		scanf("%d,%d", &cow, &rol);
		if (cow >= 1 && cow <= MAX_VALUE_OF_BOARD - 2 && rol >= 1 && rol <= MAX_VALUE_OF_BOARD - 2)
		{
			if (board2[cow][rol] == '*')
			{
				//judge = check_local(cow, rol, board1, board2);
				switch (check_local(cow, rol, board1, board2,grade))
				{
				case 1:
					display_board(board1);
					printf("扫雷失败！\n");
					break;
				case 2:
					display_board(board1);
					printf("扫雷成功!\n");
					break;
				case 3:
					count = 1;
					display_board(board2);
					break;
				}
			}
			else
			{
				printf("输入位置已被占用，请重新输入合法位置\n");
				count = 1;
			}
		}
		else
		{
			printf("输入位置错误，请重新输入合法位置\n");
			count = 1;
		}
	} while (count);
}

//判断
int check_local(int cow, int rol, char board1[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD], char board2[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],int grade)
{
	int i, j;
	int count = 0;
	//判断该位置是否为雷
	if (board1[cow][rol] == 'Y')
		return 1;
	//判断是否已经扫雷成功
	else if (check(board2,grade) == 1)
		return 2;
	else
	{
		for (i = cow - 1; i <= cow + 1; i++)
		for (j = rol - 1; j <= rol + 1; j++)
		{
			if (board1[i][j] == 'Y')
				count++;
		}
		board2[cow][rol] = '9';//由于count最大为8，所以强制类型转换为char类型时不存在数据溢出问题
		return 3;
	}
}

//检查是否扫雷成功
static int check(char board2[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],int grade)
{
	int i, j;
	int count = 0;
	for (i = 1; i < MAX_VALUE_OF_BOARD - 2;i++)
	for (j = 1; j < MAX_VALUE_OF_BOARD - 2; j++)
	{
		if (board2[i][j] == '*')
			count++;
	}
	if (count == grade)
		return 1;//扫雷成功
	else
		return 0;
}

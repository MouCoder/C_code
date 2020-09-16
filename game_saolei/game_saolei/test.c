#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

int main()
{
	char board1[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD];//存储雷的信息
	char board2[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD];//存储棋盘信息
	int grade = EASY;//游戏等级，默认为简单
	int choice1;//选择开始游戏或者退出游戏
	//初始化棋盘
	init(board1, ' ');//空格表示没有雷，Y表示有雷
	init(board2, '*');
	do
	{
		display_menue();
		printf("请选择:>");
		scanf("%d", &choice1);
		switch (choice1)
		{
		case 1:
			choice_grade(board1,board2);
			break;
		case 2:printf("退出游戏成功！\n");
			break;
		default:printf("输入错误，请重新输入\n");
		}
	} while (choice1 != 1 && choice1 != 2);
	return 0;
}

//int main()
//{
//	//定义两个二维数组，一个存储雷的信息，一个存储棋盘信息
//	//用*表示雷，因此需要定义为字符数组
//	//为了解决位置违法问题，将棋盘扩大一圈，实际棋盘可用大小为9*9
//	char check[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD];//存储雷
//	char checks[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD];//存储棋盘
//
//	int choice;
//	int num = 0;//确定累的数量
//
//	//依次初始化两个数组
//	init(check, '0');//0表示无雷，1表示有雷
//	init(checks, '*');//*表示该位置未被占用
//
//	//显示菜单
//	do{
//		display_menue();
//		scanf("%d", &choice);
//		if (choice == 1)
//		{
//			do{
//				//选择游戏等级
//				choice_grade();
//				scanf("%d", &num);
//				if (num == 1)
//				{
//					num = EASY;
//					//布置雷区
//					lay_mines(check, num);
//					display_board(checks);
//					play(checks,check);
//					break;
//				}
//				else if (num == 2)
//				{
//					num = MID;
//					//布置雷区
//					lay_mines(check, num);
//					display_board(checks);
//					play(checks, check);
//					break;
//				}
//				else if (num == 3)
//				{
//					num = DIFFICULT;
//					//布置雷区
//					lay_mines(check, num);
//					display_board(checks);
//					play(checks, check);
//					break;
//				}
//				else
//					printf("输入有误，请重新输入\n");
//			} while (num != 1 && num != 2 && num != 3);
//		}
//		else if (choice == 2)
//		{
//			break;
//		}
//		else printf("输入有误，请重新输入\n");
//	} while (choice != 1 && choice != 2);
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//��ʼ��
void init(char board[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD], char element)
{
	int i, j;
	for (i = 0; i < MAX_VALUE_OF_BOARD; i++)
		for (j = 0; j < MAX_VALUE_OF_BOARD; j++)
			board[i][j] = element;
}

//����
void lay_mines(char board[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],int num)
{
	//���������������ȷ������λ��
	int cow, rol;//�����к�����
	int count = 0;
	do
	{
		//����1-MAX_VALUE_OF_BOARD�������
		cow = (rand() % (MAX_VALUE_OF_BOARD - 2) + 1);
		rol = (rand() % (MAX_VALUE_OF_BOARD - 2) + 1);
		if (board[cow][rol] == 'N')
		{
			board[cow][rol] = 'Y';
			count++;
		}
	} while (count != num);
}

//��ʾ���ú��׵���������
void display_board(char board[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD])
{
	int cow, rol;
	int i;
	//��ӡ�к�
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

//��ӡ�˵�
void display_menue()
{
	printf("*******************************\n");
	printf("**********1.��ʼ��Ϸ***********\n");
	printf("**********2.������Ϸ***********\n");
	printf("*******************************\n");
	printf("��ѡ��:>");
}

//ѡ����Ϸ�ȼ�
void choice_grade(char board1[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],char board2[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD])
{
	int choice2;//ѡ����Ϸ�ȼ�
	int grade;
	do{
		printf("*******************************\n");
		printf("**********1.��***************\n");
		printf("**********2.�е�***************\n");
		printf("**********3.����***************\n");
		printf("*******************************\n");
		printf("��ѡ��:>");
		scanf("%d", &choice2);
		switch (choice2)
		{
		case 1:
			grade = EASY;
			//����
			lay_mines(board1, grade);
			//��ʼ��Ϸ
			play(board1, board2,grade);
			break;
		case 2:
			grade = MID;
			//����
			lay_mines(board1, grade);
			//��ʼ��Ϸ
			play(board1, board2,grade);
			break;
		case 3:
			grade = DIFFICULT;
			//����
			lay_mines(board1, grade);
			//��ʼ��Ϸ
			play(board1, board2, grade);
			break;
		default:printf("������������������\n");
		}
	} while (choice2 != 1 && choice2 != 2 && choice2 != 3);
}

//����Ϸ
void play(char board1[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],char board2[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],int grade)
{
	display_board(board2);
	int cow, rol;
	int count = 0;
	//int judge;
	do
	{
		count = 0;
		printf("������Ϸ���λ��:>");
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
					printf("ɨ��ʧ�ܣ�\n");
					break;
				case 2:
					display_board(board1);
					printf("ɨ�׳ɹ�!\n");
					break;
				case 3:
					count = 1;
					display_board(board2);
					break;
				}
			}
			else
			{
				printf("����λ���ѱ�ռ�ã�����������Ϸ�λ��\n");
				count = 1;
			}
		}
		else
		{
			printf("����λ�ô�������������Ϸ�λ��\n");
			count = 1;
		}
	} while (count);
}

//�ж�
int check_local(int cow, int rol, char board1[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD], char board2[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD],int grade)
{
	int i, j;
	int count = 0;
	//�жϸ�λ���Ƿ�Ϊ��
	if (board1[cow][rol] == 'Y')
		return 1;
	//�ж��Ƿ��Ѿ�ɨ�׳ɹ�
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
		board2[cow][rol] = '9';//����count���Ϊ8������ǿ������ת��Ϊchar����ʱ�����������������
		return 3;
	}
}

//����Ƿ�ɨ�׳ɹ�
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
		return 1;//ɨ�׳ɹ�
	else
		return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

int main()
{
	char board1[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD];//�洢�׵���Ϣ
	char board2[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD];//�洢������Ϣ
	int grade = EASY;//��Ϸ�ȼ���Ĭ��Ϊ��
	int choice1;//ѡ��ʼ��Ϸ�����˳���Ϸ
	//��ʼ������
	init(board1, ' ');//�ո��ʾû���ף�Y��ʾ����
	init(board2, '*');
	do
	{
		display_menue();
		printf("��ѡ��:>");
		scanf("%d", &choice1);
		switch (choice1)
		{
		case 1:
			choice_grade(board1,board2);
			break;
		case 2:printf("�˳���Ϸ�ɹ���\n");
			break;
		default:printf("�����������������\n");
		}
	} while (choice1 != 1 && choice1 != 2);
	return 0;
}

//int main()
//{
//	//����������ά���飬һ���洢�׵���Ϣ��һ���洢������Ϣ
//	//��*��ʾ�ף������Ҫ����Ϊ�ַ�����
//	//Ϊ�˽��λ��Υ�����⣬����������һȦ��ʵ�����̿��ô�СΪ9*9
//	char check[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD];//�洢��
//	char checks[MAX_VALUE_OF_BOARD][MAX_VALUE_OF_BOARD];//�洢����
//
//	int choice;
//	int num = 0;//ȷ���۵�����
//
//	//���γ�ʼ����������
//	init(check, '0');//0��ʾ���ף�1��ʾ����
//	init(checks, '*');//*��ʾ��λ��δ��ռ��
//
//	//��ʾ�˵�
//	do{
//		display_menue();
//		scanf("%d", &choice);
//		if (choice == 1)
//		{
//			do{
//				//ѡ����Ϸ�ȼ�
//				choice_grade();
//				scanf("%d", &num);
//				if (num == 1)
//				{
//					num = EASY;
//					//��������
//					lay_mines(check, num);
//					display_board(checks);
//					play(checks,check);
//					break;
//				}
//				else if (num == 2)
//				{
//					num = MID;
//					//��������
//					lay_mines(check, num);
//					display_board(checks);
//					play(checks, check);
//					break;
//				}
//				else if (num == 3)
//				{
//					num = DIFFICULT;
//					//��������
//					lay_mines(check, num);
//					display_board(checks);
//					play(checks, check);
//					break;
//				}
//				else
//					printf("������������������\n");
//			} while (num != 1 && num != 2 && num != 3);
//		}
//		else if (choice == 2)
//		{
//			break;
//		}
//		else printf("������������������\n");
//	} while (choice != 1 && choice != 2);
//
//	return 0;
//}
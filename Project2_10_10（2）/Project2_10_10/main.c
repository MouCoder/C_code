#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"

int main()
{
	int m, n;
	int a, b;
	int k;//��λ�����е�����λ��
	char rubbish;//�������س�
	char str[50];//�������Ļ������Ϊ50���ַ�
	do{
		printf("1.��λ���룻2.�˷����룻3.��������\n1.���ܣ�2.����\n");
		printf("��ѡ��:>");
		scanf("%d,%d", &m, &n);
		//��λ�������
		if (m == 1 && n == 1)
		{
			scanf("%c", &rubbish);//�������ûس�
			printf("����������:>");
			gets(str);
			printf("����������λ��:>");
			scanf("%d", &k);
			enOfSsc(str, k);
			printf("����Ϊ:>%s\n", str);
		}
		//��λ�������
		else if (m == 1 && n == 2)
		{
			scanf("%c", &rubbish);//�������ûس�
			printf("����������:>");
			gets(str);
			printf("����������λ��:>");
			scanf("%d", &k);
			deOfSsc(str, k);
			printf("����Ϊ:>%s\n", str);
		}
		//�˷��������
		else if (m == 2 && n == 1)
		{
			printf("��Կ�ռ䣺[1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25]\n");
			printf("����������:>");
			scanf("%c", &rubbish);//�������ûس�
			gets(str);
			printf("��ѡ����Կ:>");
			scanf("%d", &k);
			enOfMc(str, k);
			printf("����Ϊ:>%s\n", str);
		}
		//�˷��������
		else if (m == 2 && n == 2)
		{
			printf("��Կ�ռ䣺[1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25]\n");
			scanf("%c", &rubbish);//�������ûس�
			printf("����������:>");
			gets(str);
			printf("��ѡ����Կ:>");
			scanf("%d", &k);
			deOfMc(str, k);
			printf("����Ϊ:>%s\n", str);
		}
		//�����������
		else if (m == 3 && n == 1)
		{
			printf("����������:>");
			scanf("%c", &rubbish);//�������ûس�
			gets(str);
			printf("������a,b��ֵ:>\n");
			printf("ע��a��b������a��m���ʣ�m = 26\n:>");
			scanf("%d,%d", &a, &b);
			enOfAc(str, a, b);
			printf("����Ϊ:>%s\n", str);
		}
		//�����������
		else if (m == 3 && n == 2)
		{
			printf("����������:>");
			scanf("%c", &rubbish);//�������ûس�
			gets(str);
			printf("������a,b��ֵ:>\n");
			printf("ע��a��b������a��m���ʣ�m = 26\n:>");
			scanf("%d,%d", &a, &b);
			deOfAc(str, a, b);
			printf("����Ϊ:>%s\n", str);
		}
		else if (m != 0)
			printf("������������������\n");
	} while (m);

	return 0;
}

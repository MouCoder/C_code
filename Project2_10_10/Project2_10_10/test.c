#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//���ܣ�encrypt  ���ܣ�decode
//��λ���룺Shift Substitution Cipher
//�˷����룺multiplicative cipher
//�������룺affine cipher

//��λ�������
void enOfSsc()
{
	//�����㷨��Ek(C)=(m+k) mod q (k<26)
	//����k��ʾ���Ƶ�λ����q=26
}
//��λ�������
void deOfSsc()
{}

//�˷��������
void enOfMc()
{}
//�˷��������
void deOfSc()
{}
//�����������
void enOfAc()
{}
//�����������
void deOfAc()
{}
int main()
{
	int m, n;
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
			scanf("%c", &rubbish);
			printf("����������:>");
			gets(str);
			//scanf("%s", str);
			printf("����������λ��:>");
			scanf("%d", &k);
			enOfSsc(str);
		}
		//��λ�������
		else if (m == 1 && n == 2)
		{
			printf("����������:>");
			gets(str);
			printf("����������λ��:>");
			scanf("%d", &k);
			deOfSsc(str);
		}
		//�˷��������
		else if (m == 2 && n == 1)
		{
			printf("����������:>");
			gets(str);
			enOfMc(str);
		}
		//�˷��������
		else if (m == 2 && n == 2)
		{
			printf("����������:>");
			gets(str);
			deOfSc();
		}
		//�����������
		else if (m == 3 && n == 1)
		{
			printf("����������:>");
			gets(str);
			enOfAc();
		}
		//�����������
		else if (m == 3 && n == 2)
		{
			printf("����������:>");
			gets(str);
			deOfAc();
		}
		else if (m != 0)
			printf("������������������\n");
	} while (m);

	return 0;
}
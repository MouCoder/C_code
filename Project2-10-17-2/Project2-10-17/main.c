#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"


int main()
{	
	int m;
	int i = 0;
	//��16������Կ�洢��16λ��������
	//���������±������16��������λ������
	char num[17];
	//�洢64λ��������Կ
	short key[64];
	//�洢ѹ�����56λ��Կ
	short key2[56];
	//ÿ���ƶ���λ��
	int digit_1[16] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
	short C0[28], D0[28];
	//�洢16��48λ������Կ
	short keyKids[16][48];
	int j = 0;
	//�û�ѡ����ܻ��߽���
	int choice;
	//�洢16λ���ġ�����
	char cleartext[17];
	char ciphertext[17];
	//�洢64λ���������ġ�����
	short password[64];
	//�������û���
	char rubbish;
	//IP��ʼ�û�������ġ�����
	short IP[64];
	//�洢�û�������ġ����ĵ����Ҳ���
	short L0[32], R0[32];
	//��չ�û����R0
	short E_1[48];
	//�洢��չ�û����R0��k1����Ľ��
	short E_1ORk1[48];
	printf("������һ��16λ��16���Ƶ���Կ:>");
	scanf("%s", num);
	//��16������Կת��Ϊ2���ƣ���������Կ����key��
	hexToTwo(num, key);
	//��64λ�Ķ�������Կѹ���û���56λ
	replace(key, key2);
	//��56λ��������Կ��ΪC0,D0������
	part(key2, C0, D0);
	//16��ѭ�����Ʋ�ѹ������16��48λ����Կ
	while (i < 16)
	{
		//��56λ��������Կѭ������1��
		left(digit_1[i], C0);
		left(digit_1[i], D0);
		//�����ƺ��C0 D0�ϲ���Ž�key2��
		C0D0Tokey2(C0, D0, key2);
		//�����ƺ����Կѹ���û�Ϊ48λ������������Կ������
		replaceTo48(keyKids, key2, i);
		i++;
	}
	printf("1.����  2.����\n");
	printf("��ѡ��:>");
	scanf("%d", &choice);
	if (choice == 1)
	{
		//����
		printf("������16λ16��������:>");
		//�������û���
		scanf("%c", &rubbish);
		scanf("%s", cleartext);
		//��16��������ת��Ϊ�����Ʋ���������������
		hexToTwo(cleartext, password);
		//���ü��ܺ�������
		encrypt(password, IP, L0, R0, E_1, E_1ORk1,keyKids);
		printf("\n");
	}
	else if (choice == 2)
	{
		//����
		printf("������16λ16��������:>");
		//�������û���
		scanf("%c", &rubbish);
		scanf("%s", ciphertext);
		//���ý��ܺ�������
		//��16��������ת��Ϊ�����Ʋ���������������
		hexToTwo(ciphertext, password);
		/*decode(psssword,IP);*/
	}
	else
	{
		printf("������������������:>");
		scanf("%d", &choice);
	}
	return 0;
}
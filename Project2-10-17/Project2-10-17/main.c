#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"


int main()
{
	int m, n;
	int i = 0;
	//��16�������洢��16λ��������
	//���������±������16��������λ������
	char num[17];//��17λ���ڴ洢������־��
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
	printf("������һ��16λ��16���Ƶ���Կ:>");
	scanf("%s", num);
	//��16������Կת��Ϊ2���ƣ���������Կ����key��
	hexToTwo(num, key);
	
	//��64λ�Ķ�������Կѹ���û���56λ
	replace(key, key2);
	//��56λ��������Կ��ΪC0,D0������
	part(key2, C0, D0);
	left(digit_1[0], C0);
	for (m = 0; m < 28; m++)
		printf("%d", D0[m]);
	//while (i < 16)
	//{
	//	//��56λ��������Կѭ������1��
	//	left(digit_1[i], C0);
	//	for (m = 0; m < 28; m++)
	//		printf("%d", D0[m]);
	//	printf("\n");
	//	left(digit_1[i], D0);
	//	/*for (m = 0; m < 28; m++)
	//		printf("%d", D0[m]);
	//	printf("\n");*/
	//	//�����ƺ��C0 D0�ϲ���Ž�key2��
	//	C0D0Tokey2(C0, D0, key2);
	//	/*for (m = 0; m < 56; m++)
	//		printf("%d", key2[m]);
	//	printf("\n");*/
	//	//�����ƺ����Կѹ���û�Ϊ48λ������������Կ������
	//	replaceTo48(keyKids, key2,i);
	//	i++;
	//}
	/*for (m = 0; m < 16; m++)
	{
		printf("k%d:", m);
		for (n = 0; n < 48; n++)
			printf("%d", keyKids[m][n]);
		printf("\n");
	}*/
	return 0;
}
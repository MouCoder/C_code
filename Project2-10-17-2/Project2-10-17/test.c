#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"

//��ʮ�����Ƶģ�16λ����Կת��Ϊ������
//����������������Կ����key��
void scan_f(int j,int k,short key[64])
{
	//16������1-f�Ķ����Ʊ�ʾ
	short two[16][4] = { { 0, 0, 0, 0 }, { 0, 0, 0, 1 },
	{ 0, 0, 1, 0 }, { 0, 0, 1, 1 },
	{ 0, 1, 0, 0 }, { 0, 1, 0, 1 },
	{ 0, 1, 1, 0 }, { 0, 1, 1, 1 },
	{ 1, 0, 0, 0 }, { 1, 0, 0, 1 },
	{ 1, 0, 1, 0 }, { 1, 0, 1, 1 },
	{ 1, 1, 0, 0 }, { 1, 1, 0, 1 },
	{ 1, 1, 1, 0 }, { 1, 1, 1, 1 } };
	int i = 0;
	for (; i < 4; i++)
	{
		key[k + i] = two[j][i];
	}
}
void hexToTwo(char num[16],short key[64])
{
	int i = 0;//���16λ16��������ǰ��λ��
	int j = 0;//��¼�����±�
	int k = 0;//��¼��������Կkey��ǰ��λ��
	while (i < 16)
	{
		switch(num[i])
		{
		case '0':j = 0; scan_f(j, k, key); k += 4;
				break;
		case '1':j = 1; scan_f(j, k, key); k += 4;
				break;
		case '2':j = 2; scan_f(j, k, key); k += 4;
				break;
		case '3':j = 3; scan_f(j, k, key); k += 4;
				break;
		case '4':j = 4; scan_f(j, k, key); k += 4;
				break;
		case '5':j = 5; scan_f(j, k, key); k += 4;
				break;
		case '6':j = 6; scan_f(j, k, key); k += 4;
				break;
		case '7':j = 7; scan_f(j, k, key); k += 4;
				break;
		case '8':j = 8; scan_f(j, k, key); k += 4;
				break;
		case '9':j = 9; scan_f(j, k, key); k += 4;
				break;
		case 'A':j = 10; scan_f(j, k, key); k += 4;
				break;
		case 'B':j = 11; scan_f(j, k, key); k += 4;
				break;
		case 'C':j = 12; scan_f(j, k, key); k += 4;
				break;
		case 'D':j = 13; scan_f(j, k, key); k += 4;
				break;
		case 'E':j = 14; scan_f(j, k, key); k += 4;
				break;
		case 'F':j = 15; scan_f(j, k, key); k += 4;
				break;
		}
		i++;
	}
}

//pc-1������ʵ��
void replace(short key[65],short key2[56])
{
	int i;
	//pc-1��
	int pc[56] = { 57,49,41,33,25,17,9,1,58,50,42,34,26,18, 10,2,59,51,43,35,27, 19,11,3,60,52,44,36, 
					63,55,47,39,31,23,15, 7,62,54,46,38,30,22, 14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
	for (i = 0; i < 56; i++)
	{
		key2[i] = key[pc[i] - 1];
	}

}
//��56λ��������Կ��ΪC0,D0������
void part(short key2[56],short C0[28],short D0[28])
{
	int i,j=0;
	for (i = 0; i < 28; i++)
		C0[i] = key2[i];
	for (; i < 56; i++)
	{
		D0[j] = key2[i];
		j++;
	}
}
//�����ƺ��C0 D0�ڴ洢��key2��
void C0D0Tokey2(short C0[28],short D0[28],short key2[56])
{
	int i, j;
	for (i = 0; i < 28; i++)
	{
		key2[i] = C0[i];
	}
	for (j = 0; j < 28; j++)
	{
		key2[i] = D0[j];
			i++;
	}
}
//ѭ������1��
void left(int digit,short* CD)
{
		int i;
		if (digit == 1)
		{
			int num = CD[0];
			for (i = 0; i < 27; i++)
			{
				CD[i] = CD[i + 1];
			}
			CD[27] = num;
		}
		else
		{
			int num1 = CD[0];
			int num2 = CD[1];
			for (i = 0; i < 26; i++)
			{
				CD[i] = CD[i + 2];
			}
			CD[26] = num1;
			CD[27] = num2;
		}
}

//ѹ���û���48λ
void replaceTo48(short P[16][48],short key2[56],int j)
{
	int i;
	//pc-2��
	int pc_2[48] = { 14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,
					16,7,27,20,13,2,41,52,31,37,47,55, 30,40,51,45,33,
					48,44,49,39,56,34,53,46,42,50,36,29,32};
	for (i = 0; i < 48; i++)
	{
		P[j][i] = key2[pc_2[i]-1];
	}
}
//��64λ�û�������ġ����ķֳ�������
void part_1(short password[64], short L0[32], short R0[32])
{
	int i, j = 0;
	for (i = 0; i < 32; i++)
		L0[i] = password[i];
	for (; i < 64; i++)
	{
		R0[j] = password[i];
		j++;
	}
}

//��R0������չ�û�E�����48λ
void E(short R0[32],short E_1[48])
{
	int i;
	int e[48] = {32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,
				12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,
				23,24,25,24,25,26,27,28,29,28,29,30,31,32,1};
	for (i = 0; i < 48; i++)
		E_1[i] = R0[e[i] - 1];
}

//��4λ������ת��Ϊʮ���Ʒ���
int hexToTen(short n1,short n2,short n3,short n4)
{
	return n4 + 2 * n3 + 4 * n2 + 8 * n1;
}

//S����ת��
void S_1(short E_1ORk1[48],short s_2[8][4])
{
	int i=0;
	int j=0,k=0;
	int p;
	int m, n;//����
	//s�û���,ÿ4�д���һ��s����
	int s[32][16] = { {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7}, {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8}, 
					{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0}, {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}, 
					{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10}, {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5}, 
					{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15}, {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}, 
					{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8}, {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1}, 
					{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7}, {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}, 
					{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15}, {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
					{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4}, {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}, 
					{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9}, {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6}, 
					{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14}, {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}, 
					{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11}, {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8}, 
					{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6}, {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}, 
					{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1}, {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6}, 
					{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2}, {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12},
					{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7}, {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2}, 
					{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8}, {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}};
	while (i < 8)
	{
		k = 0;
		for (j=0; j < 6;j++)
		{
			if (j % 6 == 0)
			{
				m = hexToTen(0, 0, E_1ORk1[j+i*6], E_1ORk1[j+i*6 + 5]);
				n = hexToTen(E_1ORk1[j+i*6+1], E_1ORk1[j +i*6+ 2], E_1ORk1[j+i*6 + 3], E_1ORk1[j+i*6 + 4]);
			}
		}
		for (p = 3; p >=0; p--)
		{
			s_2[i][p] = s[i*4+m-1][n - 1] % 2;
			s[i * 4 + m - 1][n - 1] /= 2;
		}
		i++;
	}
}
//P�����û�
void P_1(short s_2[8][4],short result_p[32])
{
	int i;
	int m, n;
	//P���û���
	int p[32] = {16,7,20,21,29,12,28,17,
				1,15,23,26,5,18,31,10,2,
				8,24,14,32,27,3,9,19,13,
				30,6,22,11,4,25};
	for (i = 0; i < 32; i++)
	{
		if (p[i]%4 == 0)
		{
			m = p[i] / 4 - 1;
			n = 3;
		}
		else
		{
			m = p[i] / 4;
			n = p[i] % 4 - 1;
		}
		result_p[i] = s_2[m][n];
	}
}
//IP-1�û�
void IP_1(short result[64], short merge[64])
{
	int i;
	int ip_1[64] = {40,8,48,16,56,24,64,32,
					39,7,47,15,55,23,63,31,
					38,6,46,14,54,22,62,30,
					37,5,45,13,53,21,61,29,
					36,4,44,12,52,20,60,28,
					35,3,43,11,51,19,59,27,
					34,2,42,10,50,18,58,26,
					33,1,41,9,49,17,57,25};
	for (i = 0; i < 64; i++)
	{
	
		result[i] = merge[ip_1[i - 1]];
	}
}
//���ü��ܺ�������
void encrypt(short password[64], short IP[64], short L0[32], short R0[32], short E_1[48], short E_1ORk1[48],short keyKids[16][48])
{
	int i;
	int j = 0;
	short s_2[8][4];
	short result_p[32];
	short result_OR[32];
	short replace;
	short merge[64];
	short result[64];
	//��ʼIP�û���
	int ip[64] = {58,50,42,34,26,18,10,2,60,52,44,
				36,28,20,12,4,62,54,46,38,30,22,14,
				6,64,56,48,40,32,24,16,8,57,49,41,
				33,25,17,9,1,59,51,43,35,27,19,11,
				3,61,53,45,37,29,21,13,5,63,55,47,
				39,31,23,15,7};
	for (i = 0; i < 64; i++)
	{
		IP[i] = password[(ip[i] - 1)];
	}
	//���û����64λ���ķֳ�������
	part_1(password, L0, R0);
	//16�ִ���
	while (j < 16)
	{
		//��R0������չ�û�
		E(R0, E_1);
		//E_1��k1������򲢴���E_1ORk1
		for (i = 0; i < 48; i++)
		{
			E_1ORk1[i] = (E_1[i] ^ keyKids[0][i]);
			//printf("%d", E_1ORk1[i]);
		}
		//printf("\n");
		//����s�����û�
		S_1(E_1ORk1, s_2);
		//s�����û�����ڽ���p���û��������û��������result_p������
		P_1(s_2, result_p);
		//p���û������L0�����������
		for (i = 0; i < 32; i++)
		{
			result_OR[i] = (result_p[i]) ^ (L0[i]);
		}
		//����L0��R0
		for (i = 0; i < 32; i++)
		{
			L0[i] = R0[i];
			R0[i] = result_OR[i];
		}
		j++;
	}
	//����16�εĵĴ������L16��R16���н���
	for (i = 0; i < 32; i++)
	{
		replace = L0[i];
		L0[i] = R0[i];
		R0[i] = replace;
	}
	//��L0R0�ϲ�
	for (i = 0; i < 64; i++)
	{
		if (i < 32)
		{
			merge[i] = L0[i];
		}
		else
		{
			merge[i] = R0[i % 32];
		}
	}
	//IP-1�û�
	void IP_1(result,merge);
	//�������
	printf("����Ϊ:>");
	for (i = 0; i < 64; i++)
		printf("%d", result[i]);
	printf("\n");
}

////���ý��ܺ�������
//void decode()
//{
// 
//}
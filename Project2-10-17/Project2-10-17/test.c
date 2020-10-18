#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"

//将十六进制的（16位）秘钥转换为二进制
//将二进制数存入秘钥数组key中
void scan_f(int j,int k,short key[64])
{
	//16进制数1-f的二进制表示
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
	int i = 0;//标记16位16进制数当前的位数
	int j = 0;//记录数组下标
	int k = 0;//记录二进制秘钥key当前的位数
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

//pc-1函数的实现
void replace(short key[65],short key2[56])
{
	int i;
	//pc-1表
	int pc[56] = { 57,49,41,33,25,17,9,1,58,50,42,34,26,18, 10,2,59,51,43,35,27, 19,11,3,60,52,44,36, 
					63,55,47,39,31,23,15, 7,62,54,46,38,30,22, 14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
	for (i = 0; i < 56; i++)
	{
		key2[i] = key[pc[i] - 1];
	}

}
//将56位二进制秘钥分为C0,D0两部分
void part(short key2[56],short C0[28],short D0[28])
{
	int i;
	for (i = 0; i < 28; i++)
		C0[i] = key2[i];
	for (; i < 56; i++)
		D0[i] = key2[i];
}
//将左移后的C0 D0在存储进key2中
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
//循环左移1轮
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

//压缩置换到48位
void replaceTo48(short P[16][48],short key2[56],int j)
{
	int i;
	//pc-2表
	int pc_2[48] = { 14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,
					16,7,27,20,13,2,41,52,31,37,47,55, 30,40,51,45,33,
					48,44,49,39,56,34,53,46,42,50,36,29,32};
	for (i = 0; i < 48; i++)
	{
		P[j][i] = key2[pc_2[i]];
	}
}
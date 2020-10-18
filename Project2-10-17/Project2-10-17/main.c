#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"


int main()
{
	int m, n;
	int i = 0;
	//将16进制数存储在16位的数组中
	//随着数组下标的增大，16进制数的位数降低
	char num[17];//第17位用于存储结束标志符
	//存储64位二进制秘钥
	short key[64];
	//存储压缩后的56位秘钥
	short key2[56];
	//每轮移动的位数
	int digit_1[16] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
	short C0[28], D0[28];
	//存储16个48位的子秘钥
	short keyKids[16][48];
	int j = 0;
	printf("请输入一个16位的16进制的秘钥:>");
	scanf("%s", num);
	//将16进制秘钥转换为2进制，并存入秘钥数组key中
	hexToTwo(num, key);
	
	//将64位的二进制秘钥压缩置换到56位
	replace(key, key2);
	//将56位二进制秘钥分为C0,D0两部分
	part(key2, C0, D0);
	left(digit_1[0], C0);
	for (m = 0; m < 28; m++)
		printf("%d", D0[m]);
	//while (i < 16)
	//{
	//	//将56位二进制秘钥循环左移1轮
	//	left(digit_1[i], C0);
	//	for (m = 0; m < 28; m++)
	//		printf("%d", D0[m]);
	//	printf("\n");
	//	left(digit_1[i], D0);
	//	/*for (m = 0; m < 28; m++)
	//		printf("%d", D0[m]);
	//	printf("\n");*/
	//	//将左移后的C0 D0合并存放进key2中
	//	C0D0Tokey2(C0, D0, key2);
	//	/*for (m = 0; m < 56; m++)
	//		printf("%d", key2[m]);
	//	printf("\n");*/
	//	//将左移后的秘钥压缩置换为48位，并存入子秘钥数组中
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
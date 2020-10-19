#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"


int main()
{	
	int m;
	int i = 0;
	//将16进制秘钥存储在16位的数组中
	//随着数组下标的增大，16进制数的位数降低
	char num[17];
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
	//用户选择加密或者解密
	int choice;
	//存储16位明文、密文
	char cleartext[17];
	char ciphertext[17];
	//存储64位二进制明文、密文
	short password[64];
	//处理无用换行
	char rubbish;
	//IP初始置换后的明文、密文
	short IP[64];
	//存储置换后的明文、密文的左右部分
	short L0[32], R0[32];
	//扩展置换后的R0
	short E_1[48];
	//存储扩展置换后的R0与k1异或后的结果
	short E_1ORk1[48];
	printf("请输入一个16位的16进制的秘钥:>");
	scanf("%s", num);
	//将16进制秘钥转换为2进制，并存入秘钥数组key中
	hexToTwo(num, key);
	//将64位的二进制秘钥压缩置换到56位
	replace(key, key2);
	//将56位二进制秘钥分为C0,D0两部分
	part(key2, C0, D0);
	//16次循环左移并压缩生成16个48位子秘钥
	while (i < 16)
	{
		//将56位二进制秘钥循环左移1轮
		left(digit_1[i], C0);
		left(digit_1[i], D0);
		//将左移后的C0 D0合并存放进key2中
		C0D0Tokey2(C0, D0, key2);
		//将左移后的秘钥压缩置换为48位，并存入子秘钥数组中
		replaceTo48(keyKids, key2, i);
		i++;
	}
	printf("1.加密  2.解密\n");
	printf("请选择:>");
	scanf("%d", &choice);
	if (choice == 1)
	{
		//加密
		printf("请输入16位16进制明文:>");
		//处理无用换行
		scanf("%c", &rubbish);
		scanf("%s", cleartext);
		//将16进制明文转化为二进制并存入明文数组中
		hexToTwo(cleartext, password);
		//利用加密函数加密
		encrypt(password, IP, L0, R0, E_1, E_1ORk1,keyKids);
		printf("\n");
	}
	else if (choice == 2)
	{
		//解密
		printf("请输入16位16进制密文:>");
		//处理无用换行
		scanf("%c", &rubbish);
		scanf("%s", ciphertext);
		//利用解密函数解密
		//将16进制密文转化为二进制并存入密文数组中
		hexToTwo(ciphertext, password);
		/*decode(psssword,IP);*/
	}
	else
	{
		printf("输入有误，请重新输入:>");
		scanf("%d", &choice);
	}
	return 0;
}
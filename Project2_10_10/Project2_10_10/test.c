#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//加密：encrypt  解密：decode
//移位密码：Shift Substitution Cipher
//乘法密码：multiplicative cipher
//仿射密码：affine cipher

//移位密码加密
void enOfSsc()
{
	//加密算法：Ek(C)=(m+k) mod q (k<26)
	//其中k表示右移的位数，q=26
}
//移位密码解密
void deOfSsc()
{}

//乘法密码加密
void enOfMc()
{}
//乘法密码解密
void deOfSc()
{}
//仿射密码加密
void enOfAc()
{}
//放射密码解密
void deOfAc()
{}
int main()
{
	int m, n;
	int k;//移位密码中的右移位数
	char rubbish;//处理多余回车
	char str[50];//定义明文或密文最长为50个字符
	do{
		printf("1.移位密码；2.乘法密码；3.仿射密码\n1.加密；2.解密\n");
		printf("请选择:>");
		scanf("%d,%d", &m, &n);
		//移位密码加密
		if (m == 1 && n == 1)
		{
			scanf("%c", &rubbish);
			printf("请输入明文:>");
			gets(str);
			//scanf("%s", str);
			printf("请输入右移位数:>");
			scanf("%d", &k);
			enOfSsc(str);
		}
		//移位密码解密
		else if (m == 1 && n == 2)
		{
			printf("请输入密文:>");
			gets(str);
			printf("请输入右移位数:>");
			scanf("%d", &k);
			deOfSsc(str);
		}
		//乘法密码加密
		else if (m == 2 && n == 1)
		{
			printf("请输入明文:>");
			gets(str);
			enOfMc(str);
		}
		//乘法密码解密
		else if (m == 2 && n == 2)
		{
			printf("请输入密文:>");
			gets(str);
			deOfSc();
		}
		//仿射密码加密
		else if (m == 3 && n == 1)
		{
			printf("请输入明文:>");
			gets(str);
			enOfAc();
		}
		//仿射密码解密
		else if (m == 3 && n == 2)
		{
			printf("请输入密文:>");
			gets(str);
			deOfAc();
		}
		else if (m != 0)
			printf("输入有误，请重新输入\n");
	} while (m);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"

int main()
{
	int m, n;
	int a, b;
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
			scanf("%c", &rubbish);//处理无用回车
			printf("请输入明文:>");
			gets(str);
			printf("请输入右移位数:>");
			scanf("%d", &k);
			enOfSsc(str, k);
			printf("密文为:>%s\n", str);
		}
		//移位密码解密
		else if (m == 1 && n == 2)
		{
			scanf("%c", &rubbish);//处理无用回车
			printf("请输入密文:>");
			gets(str);
			printf("请输入右移位数:>");
			scanf("%d", &k);
			deOfSsc(str, k);
			printf("明文为:>%s\n", str);
		}
		//乘法密码加密
		else if (m == 2 && n == 1)
		{
			printf("秘钥空间：[1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25]\n");
			printf("请输入明文:>");
			scanf("%c", &rubbish);//处理无用回车
			gets(str);
			printf("请选择秘钥:>");
			scanf("%d", &k);
			enOfMc(str, k);
			printf("密文为:>%s\n", str);
		}
		//乘法密码解密
		else if (m == 2 && n == 2)
		{
			printf("秘钥空间：[1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25]\n");
			scanf("%c", &rubbish);//处理无用回车
			printf("请输入密文:>");
			gets(str);
			printf("请选择秘钥:>");
			scanf("%d", &k);
			deOfMc(str, k);
			printf("明文为:>%s\n", str);
		}
		//仿射密码加密
		else if (m == 3 && n == 1)
		{
			printf("请输入明文:>");
			scanf("%c", &rubbish);//处理无用回车
			gets(str);
			printf("请输入a,b的值:>\n");
			printf("注：a与b互质且a与m互质，m = 26\n:>");
			scanf("%d,%d", &a, &b);
			enOfAc(str, a, b);
			printf("密文为:>%s\n", str);
		}
		//仿射密码解密
		else if (m == 3 && n == 2)
		{
			printf("请输入密文:>");
			scanf("%c", &rubbish);//处理无用回车
			gets(str);
			printf("请输入a,b的值:>\n");
			printf("注：a与b互质且a与m互质，m = 26\n:>");
			scanf("%d,%d", &a, &b);
			deOfAc(str, a, b);
			printf("密文为:>%s\n", str);
		}
		else if (m != 0)
			printf("输入有误，请重新输入\n");
	} while (m);

	return 0;
}

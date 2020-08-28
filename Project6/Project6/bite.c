#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//递归实现，打印一个数的每一位
//void print(int num)
//{
//	if (num <= 9)
//	{
//		printf(" %d", num);
//	}
//	else
//	{
//		printf("%d", num % 10);
//		print(num / 10);
//	}
//}
//int main()
//{
//	int num;
//	printf("请输入num:");
//	scanf("%d",&num);
//	print(num);
//}

//递归实现求阶乘
//int factorial(int n)
//{
//	if (n == 1)
//		return n;
//	else 
//	{
//		return n*factorial(n - 1);
//	}
//}
//int main()
//{
//	int n;
//	printf("请输入n的值：");
//	scanf("%d", &n);
//	printf("n的阶乘为：%d\n", factorial(n));
//	return 0;
//}

//非递归实现求阶乘
//int factorial(int n)
//{
//	int i;
//	int sum = 1;
//	for (i = 1; i <= n; i++)
//	{
//		sum *= i;
//	}
//	return sum;
//}
//int main()
//{
//	int n;
//	printf("请输入n的值：");
//	scanf("%d", &n);
//	printf("n的阶乘为：%d\n", factorial(n));
//	return 0;
//}

//递归实现strlen函数（求字符串长度函数）
//int strlen1(char* p)
//{
//	if (*p != '\0')
//	{
//		return 1 + strlen1(p + 1);
//	}
//	else return 0;
//}
//int main()
//{
//	char str[] = "abcdefgh";
//	printf("%d\n",strlen1(str));
//	return 0;
//}

//非递归实现strlen函数
//int strlen2(char *p)
//{
//	int count = 0;
//	while (*p != '\0')
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//int main()
//{
//	char str[] = "abcdef";
//	printf("%d\n", strlen(str));
//	return 0;
//}

//递归实现斐波那契数
//int fibonacci(int n)
//{
//	if (n <= 2)
//		return n;
//	else
//	{
//		return fibonacci(n - 1) + fibonacci(n - 2);
//	}
//}
//int main()
//{
//	int n;
//	printf("请输入n的值：");
//	scanf("%d", &n);
//	printf("Fn = %d\n", fibonacci(n));
//	return 0;
//}

//非递归实现斐波那契数
//int fibonacci(int n)
//{
//	int i;
//	int fib = 3, a = 1, b = 2;
//	if (n <= 2)
//		return n;
//	else
//	{
//		for (i = 3; i <= n; i++)
//		{
//			fib = a + b;
//			a = b;
//			b = fib;
//		}
//		return fib;
//	}
//}
//int main()
//{
//	int n;
//	printf("请输入n的值：");
//	scanf("%d", &n);
//	printf("Fn = %d\n", fibonacci(n));
//	return 0;
//}

//递归实现n的k次方
//double pow(int n, int k)
//{
//	if (k > 0)
//	{
//		return n*pow(n, k - 1);
//	}
//	else if (k < 0)
//	{
//		return 1.0 / (n*pow(n, -1*k - 1));
//	}
//	else return 1;
//}
//int main()
//{
//	int n, k;
//	printf("请输入n和k的值：");
//	scanf("%d,%d", &n, &k);
//	printf("%lf\n", pow(n, k));
//	return 0;
//}

//递归实现返回一个数的各位之和
//int DigitSum(int num)
//{
//	if (num <= 9)
//		return num;
//	else return (num % 10) + DigitSum(num / 10);
//}
//int main()
//{
//	int num;
//	printf("请输入一个非负整数：");
//	scanf("%d", &num);
//	printf("%d\n", DigitSum(num));
//	return 0;
//}

//递归实现字符串逆序
//void reverse_string(char * str,int len)
//{
//	char itm;
//	if (len > 0)
//	{
//		itm = *str;
//		*str = *(str + len-1);
//		*(str + len -1) = itm;
//		reverse_string(str + 1,len-2);
//	}
//}
//int main()
//{
//	char str[] = "abcdef";
//	int len = strlen(str);
//	reverse_string(str,len);
//	printf("%s\n",str);
//	return 0;
//}
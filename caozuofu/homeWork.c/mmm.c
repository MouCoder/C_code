#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//操作符详解(初阶)_作业

//1.求两个数二进制中不同位的个数
//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
//			输入例子:1999 2299
//			输出例子 : 7

//思路：将m和n进行异或运算，在统计异或运算后的结果中1的个数。

//c程序
//int count(int result)
//{
//	//1.对result模2统计1的个数
//	int counter = 0;
//	while (result)
//	{
//		if (result % 2 == 1)
//		{
//			counter++;
//		}
//		result /= 2;
//	}
//	return counter;
//}

//int count(int result)
//{
//	int counter = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((result >> i) & 1) == 1)
//		{
//			counter++;
//		}
//	}
//	return counter;
//}
//
//int count(int result)
//{
//	int counter = 0;
//	while (result)
//	{
//		result = result & (result - 1);
//		counter++;
//	}
//	return counter;
//}
//int compaper(int m, int n)
//{
//	int sum = 0;
//	int result = m^n;
//	//统计result中1的个数
//	while (result)
//	{
//		result = result & (result - 1);
//		sum++;
//	}
//	return sum;
//}
//int main()
//{
//	int m, n;
//	int sum;
//	printf("请输入两个int型数据：");
//	scanf("%d,%d", &m, &n);
//	sum = compaper(m,n);
//	printf("%d\n", sum);
//	return 0;
//}
//

//2.交换两个变量（不创建临时变量）

//int main()
//{
//	int a, b;
//	printf("请输入两个int型整数：");
//	scanf("%d,%d", &a, &b);
//	printf("交换前a = %d,b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("交换后a = %d,b=%d\n", a, b);
//	return 0;
//}


//3.打印整数二进制的奇数位和偶数位

void print_even(int n)
{
	//偶数位时：将二进制数每次右移两位，如果右移后与2与结果为2则该位为1，否则为0
	int m = 32;
	while (m)
	{
		m -= 2;
		if (((n >> m) & 2) == 2)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}
void print_odd(int n)
{
	//奇数位时：将二进制数每次右移两位，如果右移后与1与结果为2则该位为1，否则为0
	int m = 32;
	while (m)
	{
		m -= 2;
		if (((n >> m) & 1) == 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

int main()
{
	int n;
	printf("请输入一个int型数据：");
	scanf("%d", &n);
	printf("偶数位：");
	print_even(n);
	printf("\n奇数位：");
	print_odd(n);

	return 0;
}
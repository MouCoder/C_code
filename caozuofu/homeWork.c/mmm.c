#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//���������(����)_��ҵ

//1.���������������в�ͬλ�ĸ���
//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
//			��������:1999 2299
//			������� : 7

//˼·����m��n����������㣬��ͳ����������Ľ����1�ĸ�����

//c����
//int count(int result)
//{
//	//1.��resultģ2ͳ��1�ĸ���
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
//	//ͳ��result��1�ĸ���
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
//	printf("����������int�����ݣ�");
//	scanf("%d,%d", &m, &n);
//	sum = compaper(m,n);
//	printf("%d\n", sum);
//	return 0;
//}
//

//2.����������������������ʱ������

//int main()
//{
//	int a, b;
//	printf("����������int��������");
//	scanf("%d,%d", &a, &b);
//	printf("����ǰa = %d,b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("������a = %d,b=%d\n", a, b);
//	return 0;
//}


//3.��ӡ���������Ƶ�����λ��ż��λ

void print_even(int n)
{
	//ż��λʱ������������ÿ��������λ��������ƺ���2����Ϊ2���λΪ1������Ϊ0
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
	//����λʱ������������ÿ��������λ��������ƺ���1����Ϊ2���λΪ1������Ϊ0
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
	printf("������һ��int�����ݣ�");
	scanf("%d", &n);
	printf("ż��λ��");
	print_even(n);
	printf("\n����λ��");
	print_odd(n);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//�ݹ�ʵ�֣���ӡһ������ÿһλ
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
//	printf("������num:");
//	scanf("%d",&num);
//	print(num);
//}

//�ݹ�ʵ����׳�
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
//	printf("������n��ֵ��");
//	scanf("%d", &n);
//	printf("n�Ľ׳�Ϊ��%d\n", factorial(n));
//	return 0;
//}

//�ǵݹ�ʵ����׳�
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
//	printf("������n��ֵ��");
//	scanf("%d", &n);
//	printf("n�Ľ׳�Ϊ��%d\n", factorial(n));
//	return 0;
//}

//�ݹ�ʵ��strlen���������ַ������Ⱥ�����
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

//�ǵݹ�ʵ��strlen����
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

//�ݹ�ʵ��쳲�������
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
//	printf("������n��ֵ��");
//	scanf("%d", &n);
//	printf("Fn = %d\n", fibonacci(n));
//	return 0;
//}

//�ǵݹ�ʵ��쳲�������
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
//	printf("������n��ֵ��");
//	scanf("%d", &n);
//	printf("Fn = %d\n", fibonacci(n));
//	return 0;
//}

//�ݹ�ʵ��n��k�η�
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
//	printf("������n��k��ֵ��");
//	scanf("%d,%d", &n, &k);
//	printf("%lf\n", pow(n, k));
//	return 0;
//}

//�ݹ�ʵ�ַ���һ�����ĸ�λ֮��
//int DigitSum(int num)
//{
//	if (num <= 9)
//		return num;
//	else return (num % 10) + DigitSum(num / 10);
//}
//int main()
//{
//	int num;
//	printf("������һ���Ǹ�������");
//	scanf("%d", &num);
//	printf("%d\n", DigitSum(num));
//	return 0;
//}

//�ݹ�ʵ���ַ�������
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
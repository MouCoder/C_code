#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int exchangeBits(int num)
{
	int a = 1;
	while (a <= num)
	{
		//�������λ��ż��λ��ͬ����������,a������λ��ָ����һ������λ
		if (((num&a)==a && (num&(a<<1))==(a<<1))||((num&a)==(num&(a<<1))))
			a = a << 2;
		//�������λ��1�������������a
		else if ((num&a) == a)
		{
			num += a;
			a = a << 2;
		}
		else
		{
			num -= a;
			a = a << 2;
		}
	}
	return num;
	
}
int main()
{
	printf("%d", exchangeBits(571603718));
	return 0;
}
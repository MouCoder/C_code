#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//����ʵ�ֳ˷��ھ���
void multipilication(int m,int n)
{
	int i, j;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%4d * %d = %d", j, i, i*j);
		}
		printf("\n");
	}
}
int main()
{
	int m, n;
	printf("������������������");
	scanf("%d,%d", &m, &n);
	multipilication(m, n);
	return 0;
}


//����ʵ��������������
/*int exchange(int num[])
{
	int itm;
	itm = num[0];
	num[0] = num[1];
	num[1] = itm;
	return num;
}
int main()
{
	int num[2];
	printf("����������������");
	scanf("%d,%d", &num[0], &num[1]);
	exchange(num);
	printf("num[0] = %d,num[1] = %d\n", num[0], num[1]);
	return 0;
}*/


//�����ж�����
/*void runNian(int year)
{
	if (year % 4 == 0 && year % 1000 != 0)
		printf("%d������\n", year);
	else printf("%d��������\n",year);
}
int main()
{
	int year;
	printf("��������ݣ�");
	scanf("%d", &year);
	runNian(year);
	return 0;
}*/


//����ʵ������
/*void suShu(int i, int j)
{
	for (i; i <= j; i++)
	{
		if (i % 2 == 1)
			printf("%5d", i);
	}
}

int main()
{
	suShu(100, 200);
	return 0;
}*/


//���ֲ���
/*{int main()
{
	int num[10] = { 1, 5, 6, 8, 11, 13, 18, 21, 25, 26};
	int a,max = 9,min = 0,mid = 4;
	printf("��������Ҫ���ҵ����ݣ�");
		scanf("%d", &a);
		while (min <= max)
		{
			if (a > num[mid])
			{
				min = mid + 1;
				mid = (min + max) / 2;
			}
			else if (a < num[mid])
			{
				max = mid - 1;
				mid = (min + max) / 2;
			}
			else if (a == num[mid])
			{
				printf("%d��%dλ��\n", a, mid);
				break;
			}
		}
	return 0;
}*/


//��������Ϸ
/*#include<stdlib.h>
int main()
{
	int a,b,Random;
	printf("1.��ʼ��Ϸ\n2.������Ϸ\n��ѡ��");
		scanf("%d",&a);
		while (a == 1)
		{
			Random = rand() * 10 + 1;
			printf("��Ϸ��ʼ���������(1-10֮�������)��");
			scanf("%d", &b);
			if (b == Random)
				printf("��ϲ�㣬�¶���������\n");
			else printf("������ô�򵥶��²��ԣ�����\n");
			printf("������Ϸ������1���˳���Ϸ������2��");
			scanf("%d", &a);
		}
		return 0;
}*/

//�ͷ��ھ����
/*int main()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%4d * %d = %d", j, i, i*j);
		}
		printf("\n");
	}
	return 0;
}*/

//�����ֵ
/*int main()
{
	int num[10];
	int i,max = 0;
	printf("������ʮ��������");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);
		if (num[i] > max)
			max = num[i];
	}
	printf("max = %d\n", max);
	return 0;
}*/

//�������
/*#include<math.h>
int main()
{
	int i = 1;
	float sum = 0;
	for (i = 1; i <= 100; i++)
	{
		sum += pow(-1, i + 1)*(1 / i);
	}
	printf("%.2f\n", sum);
	return 0;
}*/
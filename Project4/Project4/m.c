#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//函数实现乘法口诀表
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
	printf("请输入行数和列数：");
	scanf("%d,%d", &m, &n);
	multipilication(m, n);
	return 0;
}


//函数实现两个整数交换
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
	printf("请输入两个整数：");
	scanf("%d,%d", &num[0], &num[1]);
	exchange(num);
	printf("num[0] = %d,num[1] = %d\n", num[0], num[1]);
	return 0;
}*/


//函数判断闰年
/*void runNian(int year)
{
	if (year % 4 == 0 && year % 1000 != 0)
		printf("%d是闰年\n", year);
	else printf("%d不是闰年\n",year);
}
int main()
{
	int year;
	printf("请输入年份：");
	scanf("%d", &year);
	runNian(year);
	return 0;
}*/


//函数实现素数
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


//二分查找
/*{int main()
{
	int num[10] = { 1, 5, 6, 8, 11, 13, 18, 21, 25, 26};
	int a,max = 9,min = 0,mid = 4;
	printf("请输入您要查找的数据：");
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
				printf("%d在%d位置\n", a, mid);
				break;
			}
		}
	return 0;
}*/


//猜数字游戏
/*#include<stdlib.h>
int main()
{
	int a,b,Random;
	printf("1.开始游戏\n2.结束游戏\n请选择：");
		scanf("%d",&a);
		while (a == 1)
		{
			Random = rand() * 10 + 1;
			printf("游戏开始，请猜数字(1-10之间的整数)：");
			scanf("%d", &b);
			if (b == Random)
				printf("恭喜你，猜对啦！！！\n");
			else printf("大笨猪，这么简单都猜不对！！！\n");
			printf("继续游戏请输入1，退出游戏请输入2：");
			scanf("%d", &a);
		}
		return 0;
}*/

//惩罚口诀标表
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

//求最大值
/*int main()
{
	int num[10];
	int i,max = 0;
	printf("请输入十个整数：");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);
		if (num[i] > max)
			max = num[i];
	}
	printf("max = %d\n", max);
	return 0;
}*/

//分数求和
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
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//��ӡ
void print(int* p,int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}
//����
int add_sort(int x,int y)
{
	return x > y ? 1 : 0;
}
//����
int less_sort(int x,int y)
{
	return x<y ? 1 : 0;
}

//����
void bubble_sort(int* p,int n, int(*q)(int,int))
{
	int i, j;
	int tmp;
	for (i = 1; i < n;++i)
	for (j = 0; j < n - 1; ++j)
	{
		if (q(p[j],p[j+1]))
		{
			tmp = p[j];
			p[j] = p[j + 1];
			p[j + 1] = tmp;
		}
	}
}

int main()
{
	int num[10] = {8,2,9,7,4,5,3,1,6,0};
	//����
	bubble_sort(num,10,add_sort);
	//��ӡ
	printf("����");
	print(num, 10);
	//����
	bubble_sort(num,10,less_sort);
	//��ӡ
	printf("����");
	print(num,10);
	return 0;
}
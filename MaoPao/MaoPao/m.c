#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//���齻��
void exchange(int *a,int *b)
{
	int i = 0;
	int temp;
	for (i = 0; i < 9; i++)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		a++;
		b++;
	}
}
int main()
{
	int i;
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int b[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	printf("����ǰ��a���飺");
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%3d", a[i]);
	printf("\n");
	printf("����ǰ��b���飺");
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%3d", b[i]);
	printf("\n");
	exchange(a, b);
	printf("�������a���飺");
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%3d", a[i]);
	printf("\n");
	printf("�������b���飺");
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%3d", b[i]);
	printf("\n");
	return 0;
}
////�����������
//#define MAX_VALUE 10
//void init(int num[])
//{
//	int i;
//	for (i = 0; i < MAX_VALUE; i++)
//		num[i] = 0;
//}
//void reverse(int* str, int len)
//{
//	char itm;
//	if (len > 0)
//
//	{
//		itm = *str;
//		*str = *(str + len - 1);
//		*(str + len - 1) = itm;
//		reverse(str + 1, len - 2);
//	}
//}
//int main()
//{
//	int i;
//	int num[MAX_VALUE];
//	init(num);
//	printf("������%d������", MAX_VALUE);
//	for (i = 0; i < MAX_VALUE; i++)
//		scanf("%d", &num[i]);
//	reverse(num,MAX_VALUE);
//	for (i = 0; i < MAX_VALUE; i++)
//		printf("%3d", num[i]);
//}

//ð������
//#define MAX_VALUE 10
//int bobbleSort(int num[])
//{
//	int i,j,temp;
//	//һ����ҪMAX_VALUE - 1������
//	for (i = 0; i < MAX_VALUE - 1;i++)
//	for (j = 0; j < MAX_VALUE - 1 - i; j++)
//	{
//		if (num[j] > num[j + 1])
//		{
//			temp = num[j];
//			num[j] = num[j + 1];
//			num[j + 1] = temp;
//		}
//	}
//	return num;
//}
//int main()
//{
//	int num[MAX_VALUE];
//	int i;
//	printf("������%d������",MAX_VALUE);
//	for (i = 0; i < MAX_VALUE; i++)
//		scanf("%d", &num[i]);
//	int *p = bobbleSort(num);
//	for (i = 0; i < MAX_VALUE; i++)
//	{
//		printf("%3d", *p);
//		p++;
//	}
//	return 0;
//}
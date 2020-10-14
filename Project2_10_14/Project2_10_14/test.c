#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int search(int* arr, int col, int row,int num)
{
	//二维数组在内存中的存储与一位数组相同，均是存储在一片连续的区域内
	//因此，可以用指针遍历数组
	//
	int count = col * row;
	while (count)
	{
		if (*arr == num)
		{
			return 1;//存在
		}
		else
		{
			arr++;
			count--;
		}
	}
	return 0;//不存在
}

int main()
{
	/*有一个数字矩阵，矩阵的每行从左到右是递增的，
	矩阵从上到下是递增的，
	请编写程序在这样的矩阵中查找某个数字是否存在。
	要求：时间复杂度小于O(N);*/

	////分析题目：数字矩阵每行、每列都是递增的，
	//可以将矩阵看成一个二维整型数组

	//int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };//初始化数组
	//int row = 3, col = 4;//数组的行数和列数
	//int num;
	//int result;
	//scanf("%d", &num);
	//result = search(arr[0], col, row,num);//arr表示二维数组首元素的地址，类型为：int(* arr)[4]
	////arr[0]表示二维数组第0行的数组名，类型为int*，加一跳过四个字节
	//if (result == 1)
	//{
	//	printf("存在\n");
	//}
	//else
	//{
	//	printf("不存在\n");
	//}

	/*int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a + 0));
	printf("%d\n", sizeof(*a));
	printf("%d\n", sizeof(a + 1));
	printf("%d\n", sizeof(a[1]));
	printf("%d\n", sizeof(&a));
	printf("%d\n", sizeof(*&a));
	printf("%d\n", sizeof(&a + 1));
	printf("%d\n", sizeof(&a[0]));
	printf("%d\n", sizeof(&a[0] + 1));*/

	char *p = "abcdef";
	/*printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p + 1));
	printf("%d\n", sizeof(*p));
	printf("%d\n", sizeof(p[0]));
	printf("%d\n", sizeof(&p));
	printf("%d\n", sizeof(&p + 1));
	printf("%d\n", sizeof(&p[0] + 1));*/

	//printf("%d\n", strlen(p));
	//printf("%d\n", strlen(p + 1));
	///*printf("%d\n", strlen(*p));
	//printf("%d\n", strlen(p[0]));
	//printf("%d\n", strlen(&p));
	//printf("%d\n", strlen(&p + 1));*/
	//printf("%d\n", strlen(&p[0] + 1));

	int a[3][4] = { 0 };

	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a[0][0]));
	printf("%d\n", sizeof(a[0]));
	printf("%d\n", sizeof(a[0] + 1));
	printf("%d\n", sizeof(*(a[0] + 1)));
	printf("%d\n", sizeof(a + 1));
	printf("%d\n", sizeof(*(a + 1)));
	printf("%d\n", sizeof(&a[0] + 1));
	printf("%d\n", sizeof(*(&a[0] + 1)));
	printf("%d\n", sizeof(*a));
	printf("%d\n", sizeof(a[3]));

	return 0;
}
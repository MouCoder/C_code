#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//数组指针的使用
//int main()
//{
//	int arr[2][4] = { {1,2,3,4}, {1,2,3,4} };
//	int i, j;
//	int(* p)[4] = &arr;
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", (*(p + i))[j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//函数指针
int my_strlen(const char* str)
{}
int main()
{
	int(*ps)(const char*) = &my_strlen;
	return 0;
}
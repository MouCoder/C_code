#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int* ptr = NULL;
//	ptr = (int*)malloc(5 * sizeof(int));
//	if (NULL != ptr)//判断ptr指针是否为空
//	{
//		int i = 0;
//		for (i = 0; i<5; i++)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);//释放ptr所指向的动态内存
//	ptr = NULL;//是否有必要？
//	return 0;
//}

int main()
{
	int *p = calloc(10, sizeof(int));
	if (NULL != p)
	{
		//使用空间
	}
	free(p);
	p = NULL;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int* ptr = NULL;
//	ptr = (int*)malloc(5 * sizeof(int));
//	if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
//	{
//		int i = 0;
//		for (i = 0; i<5; i++)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�
//	ptr = NULL;//�Ƿ��б�Ҫ��
//	return 0;
//}

int main()
{
	int *p = calloc(10, sizeof(int));
	if (NULL != p)
	{
		//ʹ�ÿռ�
	}
	free(p);
	p = NULL;
	return 0;
}
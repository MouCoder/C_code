#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>
int main()
{
	int* ptr = NULL;
	ptr = (int*)malloc(10*sizeof(int));
	if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
	{
		int i = 0;
		for (i = 0; i<10; i++)
		{
			*(ptr + i) = 0;
		}
	}
	free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�
	ptr = NULL;//�Ƿ��б�Ҫ��
	return 0;
}
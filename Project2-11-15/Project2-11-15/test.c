#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int main()
//{
//	char* ptr = (char*)calloc(5,sizeof(char));
//	if (ptr != NULL)
//	{
//		realloc(ptr,8);
//	}
//	free(ptr);
//	ptr = NULL;
//	return 0;
//}

//��ָ��Ľ�����
//int main()
//{
//	char* ptr = NULL;
//	*ptr = 20;
//	return 0;
//}

////��̬���ٿռ��Խ�����
//int main()
//{
//	char* ptr = (char*)malloc(10);
//	if (ptr == NULL)
//	{
//		printf("���ٿռ�ʧ��\n");
//		exit(-1);
//	}
//	ptr[11] = 20;
//	return 0;
//}

////�Ƕ�̬���ٵĿռ�ʹ��free�ͷ�
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	free(pa);
//	return 0;
//}

////���������1
//void GetMemory(char* p)
//{
//	p = (char*)malloc(20);
//}
//int main()
//{
//	char* ptr = NULL;
//	GetMemory(ptr);
//	strcpy(ptr,"hello word");
//	printf("%s\n",ptr);
//	return 0;
//}

//void GetMemory(char** p)
//{
//	*p = (char*)malloc(20);
//}
//int main()
//{
//	char* ptr = NULL;
//	GetMemory(&ptr);
//	strcpy(ptr, "hello word");
//	printf("%s\n", ptr);
//	return 0;
//}

//char *GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//int main(void)
//{
//	char *str = NULL;
//	str = GetMemory();
//	printf(str);
//	return 0;
//}

//void GetMemory(char **p, int num)
//{
//	*p = (char *)malloc(num);
//}
//int main(void)
//{
//	char *str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	return 0;
//}

int main()
{
	char* p = (char*)malloc(100);
	strcpy(p,"hello");
	free(p);
	if (p != NULL)
	{
		printf("%s\n",p);
	}
	return 0;
}
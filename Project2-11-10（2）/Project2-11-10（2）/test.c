#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//�ַ�ָ��
//int main()
//{
//	char str1[] = {'a','b','c'};
//	char str2[] = { 'a', 'b', 'c' };
//	char* str3 = "hello world";
//	char* str4 = "hello world";
//
//	printf("str1:%s \nstr3:%s\n",str1,str3);
//	//��Ϊ�����ַ�ָ������ַ���ʱ��ֻ������������־�Ż�ֹͣ������str1:abc+���ֵ str2:abc
//	printf("*str3:%c\n",*str3);
//	//��Ϊָ�롰�洢���ַ���ʱʵ���ϴ洢�����ַ��������ַ��ĵ�ַ������*str3:h
//	if (str1 == str2)
//	{
//		printf("str1��str2���\n");
//	}
//	else
//	{
//		//ִ����������䣬��Ϊ����洢ʱ���Զ�������������Ŀռ䣬����str1��str2�ǲ���ͬ��
//		printf("str1��str2�����\n");
//	}
//	if (str3 == str4)
//	{
//		//������ִ�У��ַ���ָ��洢�����ַ������׵�ַ��
//		//��ͬ���ַ������ڴ���ֻ�洢1�Σ�����ָ����Ҫʹ��ʱֱ��ָ����ַ������׵�ַ
//		printf("str3��str4���\n");
//	}
//	else
//	{
//		printf("str3��str4���\n");
//	}
//	return 0;
//}

//int main()
//{
//	int a[10] = {0};
//	//a��ȡ��ַa��ֵ��ʲô�����أ�
//	printf("a:%p\n",a);
//	printf("&a:%p\n\n",&a);
//	//a+1��&a+1����ʲô�����أ�
//	printf("a+1:%p\n",a+1);
//	printf("&a+1:%p\n", &a + 1);
//	return 0;
//}

//void PopSort(int* nums,int numsSize,int(*p)(int,int))
//{
//	int i = 0,j;
//	int mid = 0;
//	for (j = 0; j < numsSize - 1;j++)
//	for (i = 0; i < numsSize - 1;i++)
//	if (p(nums[i],nums[i+1]))
//	{
//		mid = nums[i];
//		nums[i] = nums[i+1];
//		nums[i + 1] = mid;
//	}
//}
//int GreaterPopSort(int x,int y)
//{
//	return x > y ? 1 : 0;
//}
//int LessPopSort(int x, int y)
//{
//	return x < y ? 1 : 0;
//}
//int main()
//{
//	int i = 0;
//	int nums[] = {1,5,6,3,2,8,9,4,7};
//	//����
//	PopSort(nums, 9, &GreaterPopSort);
//	for (i = 0; i<9; i++)
//		printf("%2d", nums[i]);
//	printf("\n");
//	//����
//	PopSort(nums, 9, &LessPopSort);
//	for (i = 0; i<9; i++)
//		printf("%2d", nums[i]);
//	printf("\n");
//	return 0;
//}



//#include <stdio.h>
//void test(int arr[])//ok?
//{}
//void test(int arr[10])//ok?
//{}
//void test(int *arr)//ok?
//{}
//void test2(int *arr[20])//ok?
//{}
//void test2(int **arr)//ok?
//{}
//int main()
//{
//	int arr[10] = { 0 };
//	int *arr2[20] = { 0 };
//	test(arr);
//	test2(arr2);
//}

//void test(int *arr)//��ά�����������ָ����������Ԫ�صĵ�ַ������ά�������Ԫ����һ��һά���飬����Ӧ��������ָ��������
//{}
//void test(int* arr[5])//����Ĳ�����һ��ָ�����飬��˴���
//{}
//void test(int(*arr)[5])//��ȷ
//{}
//void test(int **arr)//���󣬶�ά�����������������ָ�벻�Ƕ���ָ��
//{}
//int main()
//{
//	int arr[3][5];
//	test(arr);
//}


//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	printf("%d\n", sizeof(a));//16,����Ĵ�С
//	printf("%d\n", sizeof(a + 0));//4,int*
//	printf("%d\n", sizeof(*a));//4��a[]�Ĵ�С
//	printf("%d\n", sizeof(a + 1));//4��a[1]�Ĵ�С
//	printf("%d\n", sizeof(a[1]));//4,a[1]�Ĵ�С
//	printf("%d\n", sizeof(&a));//4������ĵ�ַ��һ������ָ��
//	printf("%d\n", sizeof(*&a));//16����������
//	printf("%d\n", sizeof(&a + 1));//4������ָ��
//	printf("%d\n", sizeof(&a[0]));//4��a[0]�ĵ�ַ
//	printf("%d\n", sizeof(&a[0] + 1));//4��a[1]�ĵ�ַ����һ��int*��ָ��
//}

//int main()
//{
//	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//	printf("%d\n", sizeof(arr));//6������Ĵ�С
//	printf("%d\n", sizeof(arr + 0));//4��char*ָ��
//	printf("%d\n", sizeof(*arr));//1,arr[0]�Ĵ�С
//	printf("%d\n", sizeof(arr[1]));//1
//	printf("%d\n", sizeof(&arr));//4,����ָ��
//	printf("%d\n", sizeof(&arr + 1));//4,����ָ��
//	printf("%d\n", sizeof(&arr[0] + 1));//4��char*ָ��
//	printf("%d\n", strlen(arr));//�����
//	printf("%d\n", strlen(arr + 0));//��������ͬ�������
//	//printf("%d\n", strlen(*arr));//������룬strlen�Ĳ���Ӧ����һ���ַ�ָ������
//	//printf("%d\n", strlen(arr[1]));//ͬ��
//	//printf("%d\n", strlen(&arr));//������룬�����Ƕ���ָ��
//	//printf("%d\n", strlen(&arr + 1));//ͬ��
//	printf("%d\n", strlen(&arr[0] + 1));//�������������������С1
//	//֮���Գ��������������Ϊstrlen�ڼ���ʱ�ҵ��ǽ�����־����\0��,�����ַ���û��'\0'���ں�߼�����
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));//7,�ַ�����С+һ��������־��
//	printf("%d\n", sizeof(arr + 0));//4,�ַ�ָ��
//	printf("%d\n", sizeof(*arr));//1,char����
//	printf("%d\n", sizeof(arr[1]));//1,char����
//	printf("%d\n", sizeof(&arr));//4������ָ��
//	printf("%d\n", sizeof(&arr + 1));//4������ָ��
//	printf("%d\n", sizeof(&arr[0] + 1));//4,char*ָ��
//	printf("%d\n", strlen(arr));//6
//	printf("%d\n", strlen(arr + 0));//6
//	//printf("%d\n", strlen(*arr));//�������
//	//printf("%d\n", strlen(arr[1]));//�������
//	//printf("%d\n", strlen(&arr));//�������
//	//printf("%d\n", strlen(&arr + 1));//�������
//	//printf("%d\n", strlen(&arr[0] + 1));//�������
//	return 0;
//}

//int main()
//{
//	char *p = "abcdef";
//	printf("%d\n", sizeof(p));//4���ַ�ָ��
//	printf("%d\n", sizeof(p + 1));//4���ַ�ָ��
//	printf("%d\n", sizeof(*p));//1��char����
//	printf("%d\n", sizeof(p[0]));//1���ַ�����
//	printf("%d\n", sizeof(&p));//4������ָ��
//	printf("%d\n", sizeof(&p + 1));//4,����ָ��
//	printf("%d\n", sizeof(&p[0] + 1));//4,char*ָ��
//	printf("%d\n", strlen(p));//6�ַ�����С
//	printf("%d\n", strlen(p + 1));//5���ַ�����b��ʼ�Ĵ�С
//	//printf("%d\n", strlen(*p));//�������
//	//printf("%d\n", strlen(p[0]));//�������
//	//printf("%d\n", strlen(&p));//����ָ�룬�������
//	//printf("%d\n", strlen(&p + 1));//����ָ�룬�������
//	//printf("%d\n", strlen(&p[0] + 1));//char*ָ�룬�������
//	return 0;
//}

//int main()
//{
//	//��ά����
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48����ά�����С
//	printf("%d\n", sizeof(a[0][0]));//4,int
//	printf("%d\n", sizeof(a[0]));//16,һλ�����С
//	printf("%d\n", sizeof(a[0] + 1));//4,һλ����ָ��
//	printf("%d\n", sizeof(*(a[0] + 1)));//4,int
//	printf("%d\n", sizeof(a + 1));//4,ָ��
//	printf("%d\n", sizeof(*(a + 1)));//16,һά����
//	printf("%d\n", sizeof(&a[0] + 1));//4,int*
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16,һά����
//	printf("%d\n", sizeof(*a));//16,һλ����
//	return 0;
//}
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int *ptr = (int *)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));//
//	return 0;
//}
//���ڻ�ûѧϰ�ṹ�壬�����֪�ṹ��Ĵ�С��20���ֽ�
//struct Test
//{
//	int Num;
//	char *pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
////����p ��ֵΪ0x100000�� ���±���ʽ��ֵ�ֱ�Ϊ���٣�
//int main()
//{
//	printf("%p\n", p + 0x1);
//	//p+0x1=p+1=0x100000+20D
//	printf("%p\n", (unsigned long)p + 0x1);
//	printf("%p\n", (unsigned int*)p + 0x1);
//	return 0;
//}

//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int *ptr1 = (int *)(&a + 1);//�������һ��Ԫ�ص���һ��λ��
//	int *ptr2 = (int *)((int)a + 1);//�������
//	printf("%x,%x", ptr1[-1], *ptr2);//4,
//	return 0;
//}

//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int *ptr1 = (int *)(&a + 1);//�������һ��Ԫ�ص���һ��λ��
//	int *ptr2 = (int *)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);//4,
//	return 0;
//}


//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	int *p;
//	p = a[0];//��ά����ĵ�һ��
//	printf("%d", p[0]);//0
//	return 0;
//}

//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;//��ά����
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//0,0
//	return 0;
//}

int main()
{
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
	char**cp[] = { c + 3, c + 2, c + 1, c };
	char***cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	return 0;
}
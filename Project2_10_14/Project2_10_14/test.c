#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int search(int* arr, int col, int row,int num)
{
	//��ά�������ڴ��еĴ洢��һλ������ͬ�����Ǵ洢��һƬ������������
	//��ˣ�������ָ���������
	//
	int count = col * row;
	while (count)
	{
		if (*arr == num)
		{
			return 1;//����
		}
		else
		{
			arr++;
			count--;
		}
	}
	return 0;//������
}

int main()
{
	/*��һ�����־��󣬾����ÿ�д������ǵ����ģ�
	������ϵ����ǵ����ģ�
	���д�����������ľ����в���ĳ�������Ƿ���ڡ�
	Ҫ��ʱ�临�Ӷ�С��O(N);*/

	////������Ŀ�����־���ÿ�С�ÿ�ж��ǵ����ģ�
	//���Խ����󿴳�һ����ά��������

	//int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };//��ʼ������
	//int row = 3, col = 4;//���������������
	//int num;
	//int result;
	//scanf("%d", &num);
	//result = search(arr[0], col, row,num);//arr��ʾ��ά������Ԫ�صĵ�ַ������Ϊ��int(* arr)[4]
	////arr[0]��ʾ��ά�����0�е�������������Ϊint*����һ�����ĸ��ֽ�
	//if (result == 1)
	//{
	//	printf("����\n");
	//}
	//else
	//{
	//	printf("������\n");
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
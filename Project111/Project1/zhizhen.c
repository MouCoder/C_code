#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//指针相关作业

//第三题

//int main()
//{
//	//c语言中char short int long分别占1 2 4 4个字节
//		int arr[] = { 1, 2, 3, 4, 5 };
//		//在内存中的存放形式
//		//1		（0x）01 00 00 00
//		//2		(0x)02 00 00 00
//		//3		(0x)03 00 00 00
//		//4		(0x)04 00 00 00
//		//5		(0x)05 00 00 00
//		short *p = (short*)arr;
//		int i = 0;
//		for (i = 0; i<4; i++)
//		{
//			*(p + i) = 0;
//		}
//		//00 00;00 00;00 00;00 00
//		//改变后
//		//1		（0x）00 00 00 00
//		//2		(0x)00 00 00 00
//		//3		(0x)03 00 00 00
//		//4		(0x)04 00 00 00
//		//5		(0x)05 00 00 00
//		for (i = 0; i<5; i++)
//		{
//			printf("%d ", arr[i]);
//		}
//		//0 0 3 4 5
//	return 0;
//}

//第四题

//int main()
//{
//	unsigned long pulArray[] = { 6, 7, 8, 9, 10 };
//	unsigned long *pulPtr;
//	pulPtr = pulArray;
//	*(pulPtr + 3) += 3;//pulArray[3] = pulArray[3] + 3=12
//	printf("%d,%d\n", *pulPtr, *(pulPtr + 3));//6;12
//	return 0;
//}

//第七题

//int main()
//{
//	int a = 0x11223344;
//	char *pc = (char*)&a;
//	*pc = 0;//a= 0x11223300
//	printf("%x\n", a);//11223300
//	return 0;
//}

//写一个函数打印arr数组的内容，不使用数组下标，使用指针。arr是一个整形一维数组。
//void print(int* p,int i)
//{
//	int j = 0;
//	for (j = 0; j < i; j++)
//		printf("%3d", *(p + j));
//}
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	print(arr,sizeof(arr)/sizeof(arr[0]));
//	return 0;
//}

//写一个函数，可以逆序一个字符串的内容

//void sort(char* p,int num)
//{
//	int i = 0;
//	int temp;
//	for (i = 1; i < num / 2; i++)
//	{
//		temp = *p;
//		*p = *(p + num - i);
//		*(p + num - i) = temp;
//		p++;
//	}
//}
//int main()
//{
//	char str[20] = "12345";
//	int i = 0;
//	sort(str,strlen(str));
//	printf("%s\n", str);
//	return 0;
//}

//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
//int sum(int a, int n)
//{
//	int i = 0;
//	int sn =0;
//	for (i = 0; i < n; i++)
//		sn = sn * 10 + a;
//	return sn;
//}
//int main()
//{
//	int a;
//	printf("请输入a的值：");
//	scanf("%d", &a);
//	printf("%d", sum(a, 5));
//	return 0;
//}

//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。

//int main()
//{
//	int i = 0;
//	int count = 0;
//	int temp = 0;
//	int sum = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		temp = i;
//		while (temp)
//		{
//			count++;
//			temp / 10;
//		}
//		temp = i;
//		while (temp)
//		{
//			sum += pow((i % 10), count);
//			temp / 10;
//		}
//		if (sum == i)
//			printf("%4d", i);
//	}
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 999999; i++)
//	{
//		int count = 1;
//		int tmp = i;
//		int sum = 0;
//		//判断i是否为水仙花数
//		//1. 求判断数字的位数
//		while (tmp / 10)
//		{
//			count++;
//			tmp = tmp / 10;
//		}
//
//		//2. 计算每一位的次方和
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, count);
//			tmp = tmp / 10;
//		}
//
//		//3. 判断
//		if (sum == i)
//			printf("%d ", i);
//	}
//	return 0;
//}


int main()
{
	int line = 0;
	int i = 0;
	scanf("%d", &line);//7
	//打印上半部分
	for (i = 0; i<line; i++)
	{
		//打印一行
		//打印空格
		int j = 0;
		for (j = 0; j<line - 1 - i; j++)
		{
			printf(" ");
		}
		//打印*
		for (j = 0; j<2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}


	//打印下半部分
	for (i = 0; i<line - 1; i++)
	{
		//打印一行
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (j = 0; j<2 * (line - 1 - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
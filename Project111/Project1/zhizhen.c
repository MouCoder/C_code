#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//ָ�������ҵ

//������

//int main()
//{
//	//c������char short int long�ֱ�ռ1 2 4 4���ֽ�
//		int arr[] = { 1, 2, 3, 4, 5 };
//		//���ڴ��еĴ����ʽ
//		//1		��0x��01 00 00 00
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
//		//�ı��
//		//1		��0x��00 00 00 00
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

//������

//int main()
//{
//	unsigned long pulArray[] = { 6, 7, 8, 9, 10 };
//	unsigned long *pulPtr;
//	pulPtr = pulArray;
//	*(pulPtr + 3) += 3;//pulArray[3] = pulArray[3] + 3=12
//	printf("%d,%d\n", *pulPtr, *(pulPtr + 3));//6;12
//	return 0;
//}

//������

//int main()
//{
//	int a = 0x11223344;
//	char *pc = (char*)&a;
//	*pc = 0;//a= 0x11223300
//	printf("%x\n", a);//11223300
//	return 0;
//}

//дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣arr��һ������һά���顣
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

//дһ����������������һ���ַ���������

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

//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
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
//	printf("������a��ֵ��");
//	scanf("%d", &a);
//	printf("%d", sum(a, 5));
//	return 0;
//}

//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ���������:153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������

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
//		//�ж�i�Ƿ�Ϊˮ�ɻ���
//		//1. ���ж����ֵ�λ��
//		while (tmp / 10)
//		{
//			count++;
//			tmp = tmp / 10;
//		}
//
//		//2. ����ÿһλ�Ĵη���
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, count);
//			tmp = tmp / 10;
//		}
//
//		//3. �ж�
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
	//��ӡ�ϰ벿��
	for (i = 0; i<line; i++)
	{
		//��ӡһ��
		//��ӡ�ո�
		int j = 0;
		for (j = 0; j<line - 1 - i; j++)
		{
			printf(" ");
		}
		//��ӡ*
		for (j = 0; j<2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}


	//��ӡ�°벿��
	for (i = 0; i<line - 1; i++)
	{
		//��ӡһ��
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
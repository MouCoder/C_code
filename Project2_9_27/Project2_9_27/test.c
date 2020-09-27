#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

int main()
{
	int n = 9;
	float *pFloat = (float*)&n;
	printf("n:%d\n", n);
	printf("pFloat:%f\n", *pFloat);

	*pFloat = 9.0;
	printf("n:%d\n", n);
	printf("pFloat:%f\n", *pFloat);
	return 0;
}

//unsigned char i = 0;
//int main()
//{
//	for (i = 0; i <= 255; i++)
//	{
//		printf("%u\n",i);
//		Sleep(100);
//	}
//}

//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//	}
//}
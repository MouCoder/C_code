#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	/*int a = 15;
//	int b = -15;*/
//	int a = 1;
//	//00000000 00000000 00000000 00000001
//	//将int型数据转换char类型时，计算机会自动取int型的低字节作为char类型的结果。
//	if ((char)a == 1)
//		printf("小端机\n");
//	else
//		printf("大端机\n");
//	return 0;
//}

//int main()
//{
//	char a = -1;//10000000 00000000 00000000 00000001;11111111 11111111 11111111 11111110 ;11111111 11111111 11111111 11111111;11111110->10000001
//	signed char b = -1;
//	unsigned char c = -1;//0000001->11111111
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//}

int main()
{
	char a = -128;
	printf("%u\n", a);
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	/*int a = 15;
//	int b = -15;*/
//	int a = 1;
//	//00000000 00000000 00000000 00000001
//	//��int������ת��char����ʱ����������Զ�ȡint�͵ĵ��ֽ���Ϊchar���͵Ľ����
//	if ((char)a == 1)
//		printf("С�˻�\n");
//	else
//		printf("��˻�\n");
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


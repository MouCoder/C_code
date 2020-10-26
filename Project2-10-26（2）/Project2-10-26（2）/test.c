#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//������ת
int reverse(int x)
{
	long long int ret = 0;
	while (x)
	{
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret == (int)ret ? ret : 0;
}
//�ṹ���С�ж�
typedef struct{
	int a;
	char b;
	short c;
	short d;
}AA_t;

//memmoveģ��ʵ��
void * my_memmove(void * destination, const void * source, size_t num)
{
	//���Ÿ���
	if (destination >= source)
	{
		char* dst = (char*)(destination) + num-1;
		char* src = (char*)(source)+num-1;
		while (num)
		{
			*dst = *src;
			src--;
			dst--;
			num--;
		}
	}
	else
	{
		char* dst = (char*)destination;
		char* src = (char*)source;
		while (num)
		{
			*dst = *src;
			dst++;
			src++;
			num--;
		}
	}
	return destination;
}
int main()
{
	/*int x = 123;
	printf("%d\n", reverse(x));*/
	/*printf("%d\n", sizeof(AA_t));*/

	//memmove
	char str[] = "memmove can be very useful......";
	my_memmove(str + 20, str + 15, 11);
	puts(str);
	return 0;
}
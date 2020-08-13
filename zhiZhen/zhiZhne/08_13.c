#define _CRT_SECURE_NO_WARNINGS 1
//指针变量用于存放地址
//*说明该变量是指针，数据类型说明该变量指向的数据类型
//即 int * p = &a;表示p指向整型变量a，int表示变量指向的是int型数据

#include<stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;//让pa指向整型变量a
	*pa = 11;//*解引用操作符，通过pa的地址找到pd所指向的值进行修改
	printf("%d\n", *pa);//结果：11
	printf("%d\n", a);//与直接输出*pa结果相同，都为11
	return 0;
}

//32位机器，地址的大小是4个字节，指针变量的大小也需要4个字节
//64位机器，地址的大小是8个字节，指针变量的大小也需要8个字节
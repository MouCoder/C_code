#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	printf("当前文件的路径：%s\n当前代码的行号:%d\n", __FILE__, __LINE__);
//	printf("文件编译日期：%s\n",__DATE__);
//	printf("文件编译时间：%s\n", __TIME__);
//	return 0;
//}

//#define MAX 1000;
//int mian()
//{
//	int num[MAX];//错误，
//
//	int a = MAX //正确，注意这条语句没有写;，而是直接利用宏替换的;
//	return 0;
//}

//#define add(a,b) a+b
//
//int main()
//{
//	printf("%d\n",add(2,3));
//	printf("%d\n",add(2,3)*5);
//	return 0;
//}


//#define add(a,b) (a+b)
//
//int main()
//{
//	printf("%d\n",add(2,3));
//	printf("%d\n", add(2 , 3)*5);
//	return 0;
//}

#define mul(a,b) a*b

int main()
{
	printf("%d\n",add(2+3,5));
	return 0;
}
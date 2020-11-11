#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//字符指针
//int main()
//{
//	char str1[] = {'a','b','c'};
//	char str2[] = { 'a', 'b', 'c' };
//	char* str3 = "hello world";
//	char* str4 = "hello world";
//
//	printf("str1:%s \nstr3:%s\n",str1,str3);
//	//因为利用字符指针输出字符串时，只有遇到结束标志才会停止，所以str1:abc+随机值 str2:abc
//	printf("*str3:%c\n",*str3);
//	//因为指针“存储”字符串时实际上存储的是字符串的首字符的地址，所以*str3:h
//	if (str1 == str2)
//	{
//		printf("str1和str2相等\n");
//	}
//	else
//	{
//		//执行这个输出语句，因为数组存储时会自动内配两个数组的空间，所以str1和str2是不相同的
//		printf("str1和str2不相等\n");
//	}
//	if (str3 == str4)
//	{
//		//这个语句执行，字符串指针存储的是字符串的首地址，
//		//相同的字符串在内存中只存储1次，其他指针需要使用时直接指向该字符串的首地址
//		printf("str3和str4相等\n");
//	}
//	else
//	{
//		printf("str3和str4相等\n");
//	}
//	return 0;
//}

//int main()
//{
//	int a[10] = {0};
//	//a和取地址a的值有什么区别呢？
//	printf("a:%p\n",a);
//	printf("&a:%p\n\n",&a);
//	//a+1和&a+1又有什么区别呢？
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
//	//升序
//	PopSort(nums, 9, &GreaterPopSort);
//	for (i = 0; i<9; i++)
//		printf("%2d", nums[i]);
//	printf("\n");
//	//降序
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

//void test(int *arr)//二维数组的数组名指向的数组的首元素的地址，而二维数组的首元素是一个一维数组，所以应该用数组指针来接收
//{}
//void test(int* arr[5])//这里的参数是一个指针数组，因此错误
//{}
//void test(int(*arr)[5])//正确
//{}
//void test(int **arr)//错误，二维数组的数组名是数组指针不是二级指针
//{}
//int main()
//{
//	int arr[3][5];
//	test(arr);
//}


//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	printf("%d\n", sizeof(a));//16,数组的大小
//	printf("%d\n", sizeof(a + 0));//4,int*
//	printf("%d\n", sizeof(*a));//4，a[]的大小
//	printf("%d\n", sizeof(a + 1));//4，a[1]的大小
//	printf("%d\n", sizeof(a[1]));//4,a[1]的大小
//	printf("%d\n", sizeof(&a));//4，数组的地址是一个数组指针
//	printf("%d\n", sizeof(*&a));//16，整个数组
//	printf("%d\n", sizeof(&a + 1));//4，数组指针
//	printf("%d\n", sizeof(&a[0]));//4，a[0]的地址
//	printf("%d\n", sizeof(&a[0] + 1));//4，a[1]的地址，是一个int*的指针
//}

//int main()
//{
//	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//	printf("%d\n", sizeof(arr));//6，数组的大小
//	printf("%d\n", sizeof(arr + 0));//4，char*指针
//	printf("%d\n", sizeof(*arr));//1,arr[0]的大小
//	printf("%d\n", sizeof(arr[1]));//1
//	printf("%d\n", sizeof(&arr));//4,数组指针
//	printf("%d\n", sizeof(&arr + 1));//4,数组指针
//	printf("%d\n", sizeof(&arr[0] + 1));//4，char*指针
//	printf("%d\n", strlen(arr));//随机数
//	printf("%d\n", strlen(arr + 0));//与上面相同的随机数
//	//printf("%d\n", strlen(*arr));//错误代码，strlen的参数应该是一个字符指针类型
//	//printf("%d\n", strlen(arr[1]));//同上
//	//printf("%d\n", strlen(&arr));//错误代码，这里是二级指针
//	//printf("%d\n", strlen(&arr + 1));//同上
//	printf("%d\n", strlen(&arr[0] + 1));//随机数，与上面的随机数小1
//	//之所以出现随机数，是因为strlen在计算时找的是结束标志符‘\0’,所给字符串没有'\0'就在后边继续找
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));//7,字符串大小+一个结束标志符
//	printf("%d\n", sizeof(arr + 0));//4,字符指针
//	printf("%d\n", sizeof(*arr));//1,char类型
//	printf("%d\n", sizeof(arr[1]));//1,char类型
//	printf("%d\n", sizeof(&arr));//4，二级指针
//	printf("%d\n", sizeof(&arr + 1));//4，二级指针
//	printf("%d\n", sizeof(&arr[0] + 1));//4,char*指针
//	printf("%d\n", strlen(arr));//6
//	printf("%d\n", strlen(arr + 0));//6
//	//printf("%d\n", strlen(*arr));//错误代码
//	//printf("%d\n", strlen(arr[1]));//错误代码
//	//printf("%d\n", strlen(&arr));//错误代码
//	//printf("%d\n", strlen(&arr + 1));//错误代码
//	//printf("%d\n", strlen(&arr[0] + 1));//错误代码
//	return 0;
//}

//int main()
//{
//	char *p = "abcdef";
//	printf("%d\n", sizeof(p));//4，字符指针
//	printf("%d\n", sizeof(p + 1));//4，字符指针
//	printf("%d\n", sizeof(*p));//1，char类型
//	printf("%d\n", sizeof(p[0]));//1，字符类型
//	printf("%d\n", sizeof(&p));//4，二级指针
//	printf("%d\n", sizeof(&p + 1));//4,二级指针
//	printf("%d\n", sizeof(&p[0] + 1));//4,char*指针
//	printf("%d\n", strlen(p));//6字符串大小
//	printf("%d\n", strlen(p + 1));//5，字符串从b开始的大小
//	//printf("%d\n", strlen(*p));//错误代码
//	//printf("%d\n", strlen(p[0]));//错误代码
//	//printf("%d\n", strlen(&p));//二级指针，错误代码
//	//printf("%d\n", strlen(&p + 1));//二级指针，错误代码
//	//printf("%d\n", strlen(&p[0] + 1));//char*指针，错误代码
//	return 0;
//}

//int main()
//{
//	//二维数组
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48，二维数组大小
//	printf("%d\n", sizeof(a[0][0]));//4,int
//	printf("%d\n", sizeof(a[0]));//16,一位数组大小
//	printf("%d\n", sizeof(a[0] + 1));//4,一位数组指针
//	printf("%d\n", sizeof(*(a[0] + 1)));//4,int
//	printf("%d\n", sizeof(a + 1));//4,指针
//	printf("%d\n", sizeof(*(a + 1)));//16,一维数组
//	printf("%d\n", sizeof(&a[0] + 1));//4,int*
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16,一维数组
//	printf("%d\n", sizeof(*a));//16,一位数组
//	return 0;
//}
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int *ptr = (int *)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));//
//	return 0;
//}
//由于还没学习结构体，这里告知结构体的大小是20个字节
//struct Test
//{
//	int Num;
//	char *pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
////假设p 的值为0x100000。 如下表表达式的值分别为多少？
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
//	int *ptr1 = (int *)(&a + 1);//数组最后一个元素的下一个位置
//	int *ptr2 = (int *)((int)a + 1);//数组最后
//	printf("%x,%x", ptr1[-1], *ptr2);//4,
//	return 0;
//}

//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int *ptr1 = (int *)(&a + 1);//数组最后一个元素的下一个位置
//	int *ptr2 = (int *)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);//4,
//	return 0;
//}


//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	int *p;
//	p = a[0];//二维数组的第一行
//	printf("%d", p[0]);//0
//	return 0;
//}

//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;//二维数组
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
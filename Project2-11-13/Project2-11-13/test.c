#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
struct S3
{
	double d;
	char c;
	int i;
};
struct S1
{
	char c1;
	int i;
	char c2;
};
struct S2
{
	char c1;
	char c2;
	int i;
};

struct A
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
};

struct S {
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};

//int main()
//{
//	struct S  s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//	return 0;
//}


enum Day
{
	Mon,
	Tues,
	Wed = 5,
	Thur,
	Fri,
	Sat,
	Sun
};
enum Day1
{
	Mon1 = 1,
	Tues1 = 2,
	Wed1 = 3 ,
	Thur1 = 4 ,
	Fri1 = 5 ,
	Sat1 = 6,
	Sun1 = 7
};
enum Day2
{
	Mon2,
	Tues2,
	Wed2,
	Thur2,
	Fri2,
	Sat2,
	Sun2
};
//int main()
//{
//	printf("%d,%d,%d,%d,%d,%d,%d\n",Mon,Tues,Wed,Thur,Fri,Sat,Sun);
//	printf("%d,%d,%d,%d,%d,%d,%d\n", Mon1, Tues1, Wed1, Thur1, Fri1, Sat1, Sun1);
//	printf("%d,%d,%d,%d,%d,%d,%d\n", Mon2, Tues2, Wed2, Thur2, Fri2, Sat2, Sun2);
//	return 0;
//}

union Un1
{
	char c[5];
	int i;
};
union Un2
{
	short c[7];
	int i;
};
//下面输出的结果是什么？
int main()
{
	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));
	return 0;
}
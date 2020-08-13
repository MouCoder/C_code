#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct stu
{
	char name[20];
	short age;
};
int main()
{
	struct stu s1 = {"张三",30};//创建stu 对象s1
	printf("%s,%d", s1.name, s1.age);//结果：张三，30

	struct stu * p = &s1;
	printf("%s,%d\n", p->name, p->age);//结果：张三，30

	printf("%s,%d", (*p).name, (*p).age);
	return 0;
}

//【注】一个项目中只能有一个main函数，
//由于指针源文件中已有main函数，所以此处会报错，只用于记录
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct stu
{
	char name[20];
	short age;
};
int main()
{
	struct stu s1 = {"����",30};//����stu ����s1
	printf("%s,%d", s1.name, s1.age);//�����������30

	struct stu * p = &s1;
	printf("%s,%d\n", p->name, p->age);//�����������30

	printf("%s,%d", (*p).name, (*p).age);
	return 0;
}

//��ע��һ����Ŀ��ֻ����һ��main������
//����ָ��Դ�ļ�������main���������Դ˴��ᱨ��ֻ���ڼ�¼
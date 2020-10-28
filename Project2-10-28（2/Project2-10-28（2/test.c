#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>
//返回16进制字符对应的十进制数
int returnT(char ch)
{
	if (ch >= '0' && ch<= '9')
	{
		//字符0的ASCII是48，用该字符-48就表示该字符所表示的十进制数
		return ch-48;
	}
	else
	{
		switch (ch)
		{
		case 'a':
		case 'A':return 10;
		case 'b':
		case 'B':return 11;
		case 'c':
		case 'C':return 12;
		case 'd':
		case 'D':return 13;
		case 'e':
		case 'E':return 14;
		case 'f':
		case 'F':return 15;
		default:return -1;
		}
	}
}
int sixtenToTen(char* str)
{
	int count = 0;
	int ret = 0;
	str += strlen(str) - 1;/*指向16进制数的最低位，从最低位到最高位依次进行权位相加*/
	//当str为x说明当前指针已经遍历完所有数据位（0x表明为16进制数不参与运算）
	while (*str != 'x' && *str != 'X')
	{
		//将16进制位转化为10进制进行权位相加
		ret += (returnT(*str))*((int)pow(16, count));
		count++;
		str--;
	}
	return ret;
}

//学生信息的输入输出
typedef struct student
{
	float grade[3];
	long long int number;
}stu;
int main()
{
	stu stu1;
	scanf("%d;%f,%f,%f", &(stu1.number), &(stu1.grade[0]), &(stu1.grade[1]), &(stu1.grade[2]));
	printf("The each subject score of  No. %d is %.2f, %.2f, %.2f.\n",stu1.number,stu1.grade[0],stu1.grade[1],stu1.grade[2]);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>
//����16�����ַ���Ӧ��ʮ������
int returnT(char ch)
{
	if (ch >= '0' && ch<= '9')
	{
		//�ַ�0��ASCII��48���ø��ַ�-48�ͱ�ʾ���ַ�����ʾ��ʮ������
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
	str += strlen(str) - 1;/*ָ��16�����������λ�������λ�����λ���ν���Ȩλ���*/
	//��strΪx˵����ǰָ���Ѿ���������������λ��0x����Ϊ16���������������㣩
	while (*str != 'x' && *str != 'X')
	{
		//��16����λת��Ϊ10���ƽ���Ȩλ���
		ret += (returnT(*str))*((int)pow(16, count));
		count++;
		str--;
	}
	return ret;
}

//ѧ����Ϣ���������
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
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char * addBinary(char * a, char * b)
{
	/*���������
	*���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ��������Ϊ�ǿ��ַ�����ֻ�������� 1 �� 0��
	*/
	char* ret = NULL;
	//ָ��pa pb�ֱ�ָ��a b�����һ���ַ������ڴӺ���ǰ����a b
	char* pa = a + strlen(a) - 1;
	char* pb = b + strlen(b) - 1;
	//pa-a/pb-b��ʾ�����ַ���a/b�ĳ��ȼ�һ����һ����Ŀ���Ǹ�ret����a b�нϳ����ַ����Ĵ�С��2���ֽڵĿռ䣬����pa-a/pb-b��Ŀ���Ǽ�Сʱ�临�Ӷ�
	ret = (char*)malloc((pa - a) >= (pb - b) ? (pa - a + 3) : (pb - b + 3));
	//((pa - a) >= (pb - b) ? (pa - a + 3) : (pb - b + 3))��ʾ�ַ���ret�ĳ��ȣ���prָ��ret�����һ���ֽڣ��������ֽڸ�ֵΪ������־��
	char* pr = ret + ((pa - a) >= (pb - b) ? (pa - a + 3) : (pb - b + 3)) - 1;
	*pr = '\0';
	pr--;
	//��prȫ����ʼ��Ϊ��0��
	while (pr >= ret)
	{
		*pr = '0';
		pr--;
	}
	pr = ret + strlen(ret) - 1;//pr����ret�����һ���ַ�
	while (pa >= a && pb >= b)
	{
		switch (*pa - '0' + *pb - '0' + *pr - '0')
		{
		case 0:
			*pr = '0';
			break;
		case 1:
			*pr = '1';
			break;
		case 2:
			*pr = '0';
			*(pr - 1) = '1';
			break;
		case 3:
			*pr = '1';
			*(pr - 1) = '1';
			break;
		}
		pr--;
		pa--;
		pb--;
	}
	//a���ˣ�bû��
	if (pa < a && pb >= b)
	{
		while (pb >= b)
		{
			if (*pr - '0' + *pb - '0' == 2)
			{
				*pr = '0';
				*(pr - 1) = '1';
				pr--;
				pb--;
			}
			else
			{
				*pr = *pb>*pr?*pb:*pr;
				pr--;
				pb--;
			}
		}
	}
	else if (pb < b && pa >= a)
	{
		while (pa >= a)
		{
			if (*pr - '0' + *pa - '0' == 2)
			{
				*pr = '0';
				*(pr - 1) = '1';
				pr--;
				pa--;
			}
			else
			{
				*pr = *pa>*pr ? *pa : *pr;
				pr--;
				pa--;
			}
		}
	}
	if (*ret == '0')
		return ret + 1;
	else
		return ret;
}
int main()
{
	char * a = "1";
	char* b = "111";
	char* ret = addBinary(a,b);
	printf("%s\n",ret);
	return 0;
}
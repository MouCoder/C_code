#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//int main()
//{
//	int nums[] = { 1, 1, 3, 5, 8, 2, 5, 6, 3, 8 };
//	//num1�洢ֻ�������ε����������е��±�
//	int num1[2],count = 0;
//	int i, j;
//	//��0��ʼ���αȽ�ÿһ�������������Ƿ��ظ�������ҵ������ظ��������ж���һ���������û���ҵ��ͽ���������±걣�棬���������ҹ��˾Ͳ�������
//	for (i = 0; i < sizeof(nums) / sizeof(int); i++)
//	{
//		for (j = 0; j < sizeof(nums) / sizeof(int); j++)
//		{
//			if (nums[i] == nums[j] && j != i)
//				break;
//		}
//		if (j == sizeof(nums) / sizeof(int))
//		{
//			num1[count] = i;
//			count++;
//		}
//		if (count == 2)
//			break;
//	}
//	printf("nums[%d]:%d\nnums[%d]:%d\n",num1[0],nums[num1[0]],num1[1],nums[num1[1]]);
//	return 0;
//}
int my_atoi(const char * str)
{
	/*atoi�Ĺ��ܣ�����һ����������ɵ��ַ���������ת��������ʾ��ʮ������*/
	int i = strlen(str)-1;
	int ret = 0;
	int count = 1;
	for (; i >= 0; i--)
	{
		ret += (str[i] - '0')*count;
		count *= 10;
	}
	return ret;
}
int main()
{
	char* num = "73";
	printf("%d",my_atoi(num));

	return 0;
}
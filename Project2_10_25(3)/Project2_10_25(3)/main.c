#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
int removeElement(int* nums, int numsSize, int val)
{

	//ע�⣺
	//1.���׺������һ�������жϣ�����ѭ������д��nums!=p,�������һ����û�н����ж�
	//2.���׺�����Ŀ��������������������ԡ�ע�������Ԫ�ؿ�Ϊ����˳�򡱽����ѽ��
	//3.�������⣨�ַ���������ȵ�ɾ��������ĿҪ��ֻ��ʹ�ö����O(1)�Ŀռ����������ȿ���ʹ��ָ��
	//4.˫ָ��������ʱ�����ȿ���һ��ָ��ʼ��һ��ָ���β
	//5.�ڱ���Ŀ�У����׺���ʹ��"int* p = nums + numsSize - 1;"��ָ��pָ������ĩβʱ���������Ԫ�ظ���Ϊ0��ᵼ��pָ���λ�ò��������ĩβ
	if (numsSize == 0 )
		return 0;
	else
	{
		int* p = nums + numsSize - 1;
		while (nums <= p)
		{
			if (*p == val)
			{
				p--;
				numsSize--;
			}
			else if (*nums == val)
			{
				*nums = *p;
				p--;
				numsSize--;
				nums++;
			}
			else
			{
				nums++;
			}
		}
		return numsSize;
	}
}
int main()
{
	int nums[] = { 3, 2, 2, 3 }, val = 3;
	printf("%d\n", removeElement(nums, 4, 3));
	return 0;
}
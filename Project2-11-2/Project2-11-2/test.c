#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int* plusOne(int* digits, int digitsSize,int* returnSize)
{
	/*�������
	*1.��Ҫ��λ
	*	a.���λ����Ҫ��λ
	*		ֱ�ӽ���Ҫ��λ��Ϊ��Ϊ0��ͬʱ����һλ��Ϊ1
	*	b.���λ��Ҫ��λ
	*		��������һ��int�Ϳռ䣬���λ��Ϊ1����λ��Ϊ0
	*2.����Ҫ��λ
	*	ֱ�Ӽ�1
	*/

	/*condition 2*/
	if (digits[digitsSize - 1] < 9)
	{
		//ֱ�Ӽ�һ���������ص�����Ĵ�С����ΪdigitsSizeһ��
		digits[digitsSize - 1] += 1;
		*returnSize = digitsSize;
		return digits;
	}
	else
	{
		//�ж�������λ����Ҫ��λ���ǲ�����Ҫ��λ
		int i = digitsSize - 1;
		while (i != 0 && digits[i] == 9)
		{
			digits[i] = 0;
			i--;
		}
		//����λ�ö���Ҫ��1
		if (i == 0 && digits[0] == 9)
		{
			int* digit = (int*)calloc((digitsSize + 1),4);
			digit[0] = 1;
			*returnSize = digitsSize + 1;
			return digit;
		}
		else
		{
			digits[i] += 1;
			*returnSize = digitsSize;
			return digits;
		}
	}
}
int main()
{
	int digits[] = {8,9,9,9};
	int returnSize = 0;
	int* digit = plusOne(digits, 4, &returnSize);
	return 0;
}

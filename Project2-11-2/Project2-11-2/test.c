#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int* plusOne(int* digits, int digitsSize,int* returnSize)
{
	/*情况分析
	*1.需要进位
	*	a.最高位不需要进位
	*		直接将需要进位的为变为0，同时将上一位变为1
	*	b.最高位需要进位
	*		数组扩充一个int型空间，最高位变为1其余位均为0
	*2.不需要进位
	*	直接加1
	*/

	/*condition 2*/
	if (digits[digitsSize - 1] < 9)
	{
		//直接加一，并将返回的数组的大小设置为digitsSize一样
		digits[digitsSize - 1] += 1;
		*returnSize = digitsSize;
		return digits;
	}
	else
	{
		//判断是所有位都需要进位还是部分需要进位
		int i = digitsSize - 1;
		while (i != 0 && digits[i] == 9)
		{
			digits[i] = 0;
			i--;
		}
		//所有位置都需要加1
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

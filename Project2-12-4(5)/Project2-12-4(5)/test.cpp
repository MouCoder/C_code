#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int k = K;
	int count = 0;
	//统计K的位数
	while (k)
	{
		count++;
		k /= 10;
	}
	int flag = 0;//标记是否进位
	*returnSize = 0;//初始化为0
	//假设最高位会进行进位，申请一个大小为ASize+1大小的数组
	int* ret = (int*)malloc(sizeof(int)*(count>ASize?(count+1):(ASize+1)));
	//逆序将相加的结果存入数组中，即低位存下标较小的位置
	while (ASize)
	{
		//不需要进位，直接将相加结果存入数组
		if (A[ASize - 1] + flag + K % 10 <= 9)
		{
			ret[*returnSize] = A[ASize - 1] + flag + K % 10;
			flag = 0;//表明此位没有进位
			(*returnSize)++;
			K /= 10;
			ASize--;
		}
		else
		{
			ret[*returnSize] = (A[ASize - 1] + flag + K % 10)%10;
			flag = 1;//表明此位没有进位
			(*returnSize)++;
			K /= 10;
			ASize--;
		}
	}
	while (K)
	{
		if (flag + K % 10 <= 9)
		{
			ret[*returnSize] = K % 10 + flag;
			(*returnSize)++;
			flag = 0;
			K /= 10;
		}
		else
		{
			ret[*returnSize] = (K % 10 + flag)%10;
			(*returnSize)++;
			K /= 10;
			flag = 1;
		}
	}
	if (flag == 1)
	{
		ret[*returnSize] = 1;
		(*returnSize)++;
	}

	//逆置数组
	int start = 0;
	int end = (*returnSize) - 1;
	int mid;
	while (start < end)
	{
		mid = ret[start];
		ret[start] = ret[end];
		ret[end] = mid;
		start++;
		end--;
	}
	return ret;
}
int main()
{
	int A[] = { 7}, K = 993;
	int returnSize;
	int* num = addToArrayForm(A,1,K,&returnSize);
	for (int i = 0; i < returnSize; i++)
		printf("%d ",num[i]);
	return 0;
}
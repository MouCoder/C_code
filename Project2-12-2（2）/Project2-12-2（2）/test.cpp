#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int missingNumber(int* nums, int numsSize){
	int max = 0;
	int flag = 0;
	int sum = 0;
	//�ҳ������������������õȲ����й�ʽ�������0~n���ۼӣ�
	//�ڽ������е�Ԫ����ӡ����ۼӽ����ȥ������Ԫ�صĺ;��ǽ����ͬʱ��Ҫ�ж���������û��0
	while (numsSize)
	{
		if (nums[numsSize - 1] == 0)
			flag = 1;
		sum += nums[numsSize - 1];
		max = max < nums[numsSize - 1] ? nums[numsSize - 1] : max;
		numsSize--;
	}
	int ret = max + (max*(max - 1)) / 2;
	if (flag == 0)
		return 0;
	else if (ret == sum)
		return max + 1;
	else
		return ret - sum;
}
int main()
{
	int nums[] = {3,0,1};
	printf("%d\n",missingNumber(nums,3));
	return 0;
}
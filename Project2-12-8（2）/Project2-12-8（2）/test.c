#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize){
	//���ֻ��1������û��Ԫ�أ��϶���������ظ���ֱ�ӷ������鳤��
	if (numsSize == 0 || numsSize == 1)
		return numsSize;
	int pre = 0;
	int curr = 1;
	int tag = 0;
	//����д�������Ԫ�أ��Ϳ��ܴ����ظ�
	while (pre < numsSize - 1)
	{
		if (nums[pre] == nums[curr])
		{
			pre++;
			curr++;
		}
		else
		{
			nums[tag] = nums[pre];
			pre++;
			curr++;
			tag++;
		}
	}
	//ִ��������Ĵ��룬ָ��preָ�����һ��Ԫ���ˣ��������һ��Ԫ�ؾ�û�н��д洢
	nums[tag] = nums[pre];

	return tag + 1;
}

int main()
{
	return 0;
}

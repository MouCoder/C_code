#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize)
{
	//ɾ�����������е��ظ���
	//�����ظ������ݸ��ǵ�
	int loc = 0;//��ǵ�ǰλ��
	int mov = loc +1;//�ƶ�����
	int flag = 0;//��ǵ�ǰ��ЧԪ��λ��
	while (mov < numsSize)
	{
		if (nums[loc] != nums[mov])
		{
			nums[flag] = nums[loc];
			flag++;
			loc = mov;
			mov++;
		}
		//����������ظ����ͼ��������ߣ�ֱ���ҵ����ظ��Ľ�ǰ���ظ��ĸ��ǵ���
		while (mov != numsSize && nums[loc] == nums[mov])
		{
			mov++;
		}
	}
	nums[flag] = nums[loc];
	return flag+1;
}
int main()
{
	int num[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int i = removeDuplicates(num, 10);
	for (int j = 0; j < i; j++)
		printf("%d ",num[j]);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int k = K;
	int count = 0;
	//ͳ��K��λ��
	while (k)
	{
		count++;
		k /= 10;
	}
	int flag = 0;//����Ƿ��λ
	*returnSize = 0;//��ʼ��Ϊ0
	//�������λ����н�λ������һ����СΪASize+1��С������
	int* ret = (int*)malloc(sizeof(int)*(count>ASize?(count+1):(ASize+1)));
	//������ӵĽ�����������У�����λ���±��С��λ��
	while (ASize)
	{
		//����Ҫ��λ��ֱ�ӽ���ӽ����������
		if (A[ASize - 1] + flag + K % 10 <= 9)
		{
			ret[*returnSize] = A[ASize - 1] + flag + K % 10;
			flag = 0;//������λû�н�λ
			(*returnSize)++;
			K /= 10;
			ASize--;
		}
		else
		{
			ret[*returnSize] = (A[ASize - 1] + flag + K % 10)%10;
			flag = 1;//������λû�н�λ
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

	//��������
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
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//����һ���������飬����������ӽ�����ֵsum��������
int* search(int *num,int numSize,int sum)
{
	int s = 0, e = numSize - 1;
	/*����Ŀ�У�����Ԫ����������a,b���������Էֱ�ӿ�ʼ�ͽ�β����ʼ��
	��������βԪ�صĺ��Ƿ����sum,�����������ƶ����������鱻����һ�飬
	�Ϳ��Եõ�������������ʱ�临�Ӷ�Ϊn*/
	int ret[2];
	while (1)
	{
		if (num[s] + num[e] > sum)
			e--;
		else if (num[s] + num[e] < sum && num[s + 1] + num[e] > sum)
		{
			ret[0] = s;
			ret[1] = e;
			return ret;
		}
		else
		{
			s++;
		}
	}
	return ret;
}
int main()
{
	int num[] = {1,2,5,9,10,16,25};
	int sum = 18;
	search(num, 7, sum);
	return 0;
}
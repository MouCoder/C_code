#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;	
};
//����������ת����;
int getDecimalValue(struct ListNode* head)
{
	//ͳ��������
	int n = 0;
	int sum = 0;
	struct ListNode* phead = head;
	while (phead != NULL)
	{
		phead = phead->next;
		n++;
	}
	//Ȩλ���
	phead = head;
	while (phead)
	{
		sum += (phead->val)*(int)(pow(2.0, n - 1));
		phead = phead->next;
			n--;
	}
	return sum;
}
int main()
{
	
}
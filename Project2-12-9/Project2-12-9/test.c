#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;	
};
//二进制链表转整数;
int getDecimalValue(struct ListNode* head)
{
	//统计链表长度
	int n = 0;
	int sum = 0;
	struct ListNode* phead = head;
	while (phead != NULL)
	{
		phead = phead->next;
		n++;
	}
	//权位相加
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
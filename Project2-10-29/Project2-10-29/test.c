#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	//合并两个有序链表，两个链表均为升序
	if (l2 && l1 == NULL)
	{
		return l2;
	}
	else
	{
		struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* q = (struct ListNode*)malloc(sizeof(struct ListNode));
		p = l1;
		q = l2;
		while (l2 && p->next)
		{
			if (p->val < l2->val)
			{
				p = p->next;
			}
			else
			{
				q = q->next;
				l2 = p;
				l1->next = l2;
				l2 = q;
			}
		}
		if (p->next == NULL && l2 != NULL)
			p->next = l2;
	}
	return l1;
}
int main()
{

	return 0;
}
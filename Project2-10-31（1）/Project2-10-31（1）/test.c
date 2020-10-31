#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	struct ListNode* l3;
	l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l3->next = NULL;
	struct ListNode* r = l3;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val <= l2->val)
		{
			r->next = l1;
			r = l1;
			l1 = l1->next;
		}
		else
		{
			r->next = l2;
			r = l2;
			l2 = l2->next;
		}
	}
	if (l1)
		r->next = l1;
	else
		r->next = l2;
	return l3->next;
}

int main()
{
	return 0;
}
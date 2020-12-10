#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>

//牛客网---链表的回文结构
typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode; 
bool chkPalindrome(ListNode* A) 
{
		//思路：找到单链表的中间节点，将后半部分进行逆置跟前半部分进行比较
		if (A == NULL || A->next == NULL)
			return true;
		//找中间节点，快慢指针法
		ListNode *slow = A;
		ListNode *fast = A;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		//当前slow指向的就是中间节点，如果有两个中间节点则slow指向的是靠后的一个中间节点
		ListNode *l1Tail = slow;//前半部分链表尾结点的next域

		//逆置后半部分链表,头插法
		ListNode *head = (ListNode*)malloc(sizeof(ListNode));
		ListNode *phead = NULL;//指向链表的头结点的指针
		while (slow)
		{
			ListNode *next = slow->next;
			slow->next = phead;
			phead = slow;
			slow = next;
		}
		//逆置后，前半部分链表的头结点为A，尾结点的next为l1Tail;后半部分链表的头结点为phead,

		//比较两个链表
		while (phead && A != l1Tail)
		{
			if (A->val == phead->val)
			{
				A = A->next;
				phead = phead->next;
			}
			else
				return false;
		}
		return true;
	}
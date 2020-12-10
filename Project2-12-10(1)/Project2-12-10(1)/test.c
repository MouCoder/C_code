#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>

//ţ����---����Ļ��Ľṹ
typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode; 
bool chkPalindrome(ListNode* A) 
{
		//˼·���ҵ���������м�ڵ㣬����벿�ֽ������ø�ǰ�벿�ֽ��бȽ�
		if (A == NULL || A->next == NULL)
			return true;
		//���м�ڵ㣬����ָ�뷨
		ListNode *slow = A;
		ListNode *fast = A;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		//��ǰslowָ��ľ����м�ڵ㣬����������м�ڵ���slowָ����ǿ����һ���м�ڵ�
		ListNode *l1Tail = slow;//ǰ�벿������β����next��

		//���ú�벿������,ͷ�巨
		ListNode *head = (ListNode*)malloc(sizeof(ListNode));
		ListNode *phead = NULL;//ָ�������ͷ����ָ��
		while (slow)
		{
			ListNode *next = slow->next;
			slow->next = phead;
			phead = slow;
			slow = next;
		}
		//���ú�ǰ�벿�������ͷ���ΪA��β����nextΪl1Tail;��벿�������ͷ���Ϊphead,

		//�Ƚ���������
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
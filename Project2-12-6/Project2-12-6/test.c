#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
	
};


struct ListNode* removeElements(struct ListNode* head, int val)
{
	//���ɾ���Ľڵ����м�ڵ㣬ֱ��ɾ������
	//���ɾ���Ľڵ���ͷ�ڵ㣬����Ӧͷָ��ҲҪ�ƶ�
	//���ɾ���Ľڵ������һ���ڵ㣬�����һ���ڵ��ǰһ���ڵ��next��Ҫ�ÿ�

	//����һ���½ڵ㣬�ýڵ��next��ָ������ĵ�һ���ڵ�
	struct ListNode* preHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	preHead->next = head;

	//˫ָ�룬һ��ָ��ǰ�ڵ㣬һ��ָ��ǰ�ڵ����һ���ڵ�����ɾ���ڵ�
	struct ListNode* curr = head;
	struct ListNode* preCurr = preHead;

	while (curr != NULL)
	{
		if (curr->val == val)
		{
			preCurr->next = curr->next;
			free(curr);
			curr = preCurr->next;
		}
		else
		{
			preCurr = preCurr->next;
			curr = curr->next;
		}
	}
	head = preHead->next;
	free(preHead);
	preHead == NULL;
	return head;
}
int main()
{

	return 0;
}
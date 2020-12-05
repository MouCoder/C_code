#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
	
};


struct ListNode* removeElements(struct ListNode* head, int val)
{
	//如果删除的节点是中间节点，直接删除即可
	//如果删除的节点是头节点，则相应头指针也要移动
	//如果删除的节点是最后一个节点，则最后一个节点的前一个节点的next域要置空

	//创建一个新节点，该节点的next域指向链表的第一个节点
	struct ListNode* preHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	preHead->next = head;

	//双指针，一个指向当前节点，一个指向当前节点的上一个节点用于删除节点
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
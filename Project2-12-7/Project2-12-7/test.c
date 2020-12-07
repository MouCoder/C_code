#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode
{
	int val;
	struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head){
	if (head == NULL)
		return head;
	struct ListNode* phead = head->next;
	struct ListNode* preHead = head;
	while (phead != NULL)
	{
		if (preHead->val == phead->val)
		{
			preHead->next = phead->next;
			//free(head);
			phead = preHead->next;
		}
		else
		{
			preHead = phead;
			phead = phead->next;
		}
	}
	return head;
}
int main()
{

	return 0;
}
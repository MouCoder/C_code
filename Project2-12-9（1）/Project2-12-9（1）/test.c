#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//反转单链表
struct ListNode {
	int val;
	struct ListNode *next;
};



struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	//将头结点的next域进行保存
	struct ListNode* headNext = head->next;
	//让头节点指向空
	head->next = NULL;
	//让第二个节点指向头节点，依此类推
	//保存head节点
	struct ListNode* phead = NULL;
	while (headNext != NULL)
	{
		phead = head;
		head = headNext;
		headNext = head->next;
		head->next = phead;
	}
	return head;

}
int, main()
{
	return 0;
}
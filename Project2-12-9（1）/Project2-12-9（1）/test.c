#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��ת������
struct ListNode {
	int val;
	struct ListNode *next;
};



struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	//��ͷ����next����б���
	struct ListNode* headNext = head->next;
	//��ͷ�ڵ�ָ���
	head->next = NULL;
	//�õڶ����ڵ�ָ��ͷ�ڵ㣬��������
	//����head�ڵ�
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
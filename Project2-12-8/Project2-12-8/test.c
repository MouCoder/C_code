#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode 
{
	int val;
	struct ListNode *next;
};
void deleteNode(struct ListNode* node) 
{
	//ɾ�������еĽڵ�
	//�õ�ǰ�ڵ��ֵ����һ���ڵ��ֵ���н�����ת����ɾ��node����һ���ڵ������
	struct ListNode* nodeNext = node->next;
	node->val = node->next->val;
	node = nodeNext->next;
	free(nodeNext);
	nodeNext == NULL;
}

int main()
{

	return 0;
}
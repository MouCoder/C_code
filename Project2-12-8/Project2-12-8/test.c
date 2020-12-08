#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode 
{
	int val;
	struct ListNode *next;
};
void deleteNode(struct ListNode* node) 
{
	//删除链表中的节点
	//让当前节点的值跟下一个节点的值进行交换，转换成删除node的下一个节点的问题
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
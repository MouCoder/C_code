#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
//��ʼ��������
void InitList(struct ListNode* *L)
{
	//������øú���ʱ����Ҫ�����ǽṹ��ָ��ĵ�ַ�����Է���ռ�ʱҪ������
	*L = (struct ListNode*)malloc(sizeof(struct ListNode));
	(*L)->next = NULL;
}
//ͷ�巨����������
void CreateList(struct ListNode* L)
{
	struct ListNode* s;
	int e;//����
	int flag = 1;
	while (flag)
	{
		printf("�����뵥����ڵ�ֵ���������־:>");
		scanf("%d", &e);
		if (e != 0)/*�������Ĳ��ǽ�����־*/
		{
			s = (struct ListNode*)malloc(sizeof(struct ListNode));
			s->val = e;
			s->next = L->next;
			L->next = s;
		}
		else
		{
			flag = 0;
		}
	}
}
//�ϲ������������������
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *p1, *p2, *l3,*r;
	p1 = l1->next;
	p2 = l2->next;
	l3 = l1;
	l3->next = NULL;
	r = l3;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->val <= p2->val)
		{
			r->next = p1;
			r = p1;
			p1 = p1->next;
		}
		else
		{
			r->next = p2;
			r = p2;
			p2 = p2->next;
		}
	}
	if (p1)
		r->next = p1;
	else
		r->next = p2;
	free(l2);
	return l3;
}
int main()
{
	struct ListNode* l1,*l2;
	InitList(&l1);
	InitList(&l2);
	CreateList(l1);
	CreateList(l2);
	struct ListNode* l3 = mergeTwoLists(l1, l2);
	while (l3)
	{
		printf("%d ", l3->val);
		l3 = l3->next;
	}
	return 0;
}
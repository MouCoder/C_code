#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
typedef struct ListNode {
	int val;
	struct ListNode *next;
}*ListNode,Node;
void InitList(ListNode* L)
{
	//�������ʼ��ʱ��ʵ�δ���ʱָ�������ָ��ĵ�ַ
	(*L) = (ListNode)malloc(sizeof(Node));
	(*L)->next = NULL;
}
//ͷ�巨����������
void CreateFromHead(ListNode L)
{
	ListNode s;
	int e;
	int flag = 1;/*���ñ�ǣ������ǰ�ַ��ǽ�����־��flag��Ϊ0���������룬������־Ϊ-1*/
	while (flag)
	{
		printf("������һ�����ݻ������־-1:>");
		scanf("%d",&e);
		if (e == -1)
		{
			flag = 0;
		}
		else
		{
			s = (ListNode)malloc(sizeof(Node));
			s->val = e;
			s->next = L->next;
			L->next = s;
		}
	}
}
//β�巨����������
void CreateFromHatil(ListNode L)
{
	ListNode s;
	ListNode r=L;
	int e;
	int flag = 1;
	int count = 1;
	s = (ListNode)malloc(sizeof(Node));
	/*�������������ʱ����һ��ֵ���ǽ�����־��ʱ�򣬽���һ���ڵ��ÿջ����δ��ʼ��s�������
	�����ȸ�s����һ���ռ䣬���ü����������жϣ������һ���������ݾͲ���Ҫ����ռ�*/
	while (flag)
	{
		printf("������һ�����ݻ������־-1:>");
		scanf("%d", &e);
		if (e != -1)
		{
			
			if (count != 1)
			{
				s = (ListNode)malloc(sizeof(Node));
			}
			s->val = e;
			r->next = s;
			r = s;
			count++;
		}
		else
		{
			flag = 0;
			s->next = NULL;
		}
	}
}
//�ϲ�������������
ListNode mergeTwoLists(ListNode l1, ListNode l2)
{
	ListNode l3;
	l3 = (ListNode)malloc(sizeof(Node));
	l3->next = NULL;
	ListNode r = l3;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val <= l2->val)
		{
			r->next = l1;
			r = l1;
			l1 = l1->next;
		}
		else
		{
			r->next = l2;
			r = l2;
			l2 = l2->next;
		}
	}
	if (l1)
		r->next = l1;
	else
		r->next = l2;
	//l3Ϊ��ͷ���ĵ����������Ҫ����l3->next������ֱ�ӷ���
	return l3->next;
}
int main()
{
	//����������l1,l2����ʼ��Ϊ��
	ListNode l1;
	ListNode l2;
	InitList(&l1);
	InitList(&l2);

	//ͷ�巨����������
	/*CreateFromHead(l1);
	CreateFromHead(l2);*/

	//β�巨����������
	printf("�������һ������������ʱ����-1\n\n");
	CreateFromHatil(l1);
	printf("\n������ڶ�������������ʱ����-1\n\n");
	CreateFromHatil(l2);

	//�ϲ�l1��l2
	ListNode l3 = mergeTwoLists(l1, l2);
	//l3Ϊ�ṹͷָ�����ͣ�l3->nextΪ���صĽṹ��ĵ�һ���ڵ㡣����ʱҪ�Ӹýڵ㿪ʼ����
	l3 = l3->next;
	printf("\n�ϲ���ĵ�����Ϊ��\n");
	while (l3->next)
	{
		printf("%d ",l3->next->val);
		l3 = l3->next;
	}
	printf("\n");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
typedef struct ListNode {
	int val;
	struct ListNode *next;
}*ListNode,Node;
void InitList(ListNode* L)
{
	//单链表初始化时，实参传的时指向单链表的指针的地址
	(*L) = (ListNode)malloc(sizeof(Node));
	(*L)->next = NULL;
}
//头插法建立单链表
void CreateFromHead(ListNode L)
{
	ListNode s;
	int e;
	int flag = 1;/*设置标记，如果当前字符是结束标志将flag置为0，结束输入，结束标志为-1*/
	while (flag)
	{
		printf("请输入一个数据或结束标志-1:>");
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
//尾插法建立单链表
void CreateFromHatil(ListNode L)
{
	ListNode s;
	ListNode r=L;
	int e;
	int flag = 1;
	int count = 1;
	s = (ListNode)malloc(sizeof(Node));
	/*如果建立单链表时，第一个值就是结束标志的时候，将第一个节点置空会出现未初始化s的情况，
	所以先给s分配一个空间，在用计数器进行判断，如果第一次输入数据就不需要分配空间*/
	while (flag)
	{
		printf("请输入一个数据或结束标志-1:>");
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
//合并有序单链表，升序
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
	//l3为带头结点的单链表，因此需要返回l3->next，方可直接访问
	return l3->next;
}
int main()
{
	//建立单链表l1,l2并初始化为空
	ListNode l1;
	ListNode l2;
	InitList(&l1);
	InitList(&l2);

	//头插法建立单链表
	/*CreateFromHead(l1);
	CreateFromHead(l2);*/

	//尾插法建立单链表
	printf("请输入第一个单链表，结束时输入-1\n\n");
	CreateFromHatil(l1);
	printf("\n请输入第二个单链表，结束时输入-1\n\n");
	CreateFromHatil(l2);

	//合并l1和l2
	ListNode l3 = mergeTwoLists(l1, l2);
	//l3为结构头指针类型，l3->next为返回的结构体的第一个节点。访问时要从该节点开始访问
	l3 = l3->next;
	printf("\n合并后的单链表为：\n");
	while (l3->next)
	{
		printf("%d ",l3->next->val);
		l3 = l3->next;
	}
	printf("\n");
	return 0;
}
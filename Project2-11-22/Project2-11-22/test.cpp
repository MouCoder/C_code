#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList.h"

/*
��ͷ���ĵ�����Ͳ���ͷ�ڵ�ĵ�������������ڣ�
��ͷ���ĵ�������д�������ʱ����Ҫ����ͷ�������⴦��
����̫ͷ���ĵ�������Ҫ��ͷ�����е�������
*/

int main()
{
	LinkList* s;
	LinkListInit(&s);
	LinkListCraete_head(&s);
	LinkListPrint(s);
	printf("\n------------------------\n");
	LinkListAdd_value(&s);
	LinkListAdd_loc(&s);
	LinkListDel_value(&s);
	LinkListSear_loc(s);
	LinkListUpdate_loc(&s);
	LinkListLength(s);
	LinkListPrint(s);
	
	return 0;
}
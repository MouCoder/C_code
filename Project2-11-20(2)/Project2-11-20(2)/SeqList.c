#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void menue()
{
	SeqList list;
	init(&list);
	int x ;
	int select = 1;
	int num;
	int loc;
	do
	{
		printf("**************************************\n");
		printf("*1.打印书序表                  2.头插*\n");
		printf("*3.尾插                        4.头删*\n");
		printf("*5.尾删                6.指定位置删除*\n");
		printf("*7.指定位置插入            8.判断个数*\n");
		printf("*9.排序                        0.退出*\n");
		printf("*************************************\n");
		printf("Select：>");
		scanf("%d",&select);
		switch (select)
		{
		case 0:
			printf("Exit successfully！\n");
			break;
		case 1:
			print(&list);
			break;
		case 2:
			printf("Input the value of your insert:>");
			while (1)
			{
				scanf("%d", &x);
				if (x == -1)
					break;
				SeqListInsertHead(&list, x);
			}
			printf("Inserted successfully.\n");
			break;
		case 3:
			printf("Input the value of your insert:>");
			while (1)
			{
				scanf("%d", &x);
				if (x == -1)
					break;
				SeqListInsertTail(&list, x);
			}
			printf("Inserted successfully.\n");
			break;
		case 4:
			printf("Please enter the number you need to delete:>");
			scanf("%d",&num);
			SeqListRemoveHead(&list, num);
			break;
		case 5:
			printf("Please enter the number you need to delete:>");
			scanf("%d", &num);
			SeqListRemoveTail(&list, num);
			break;
		case 6:
			printf("Please enter delete location.:>");
			scanf("%d", &loc);
			SeqListRemoveLoc(&list, loc);
			break;
		case 7:
			printf("Please enter the insertion position and the inserted value:>");
			scanf("%d,%d",&loc,&x);
			SeqListInsertLoc(&list, loc, x);
			break;
		case 8:
			printf("The size of SeqList is %d\n",SeqListSize(&list));
			break;
		case 9:
			SeqListSort(&list);
			break;
		default:
			printf("Error seletc!Please select again.\n");
		}
		system("pause");
		system("cls");
	} while (select);
}


//初始化顺序表
void init(SeqList* list)
{
	list->data = (ElementType*)malloc(sizeof(ElementType)*MAX_SIZE);
	list->capacity = MAX_SIZE;
	list->size = 0;
}

//判满
bool ifFull(SeqList* list)
{
	assert(list);
	return list->size == list->capacity;
}
//判空
bool ifNull(SeqList* list)
{
	assert(list);
	return list->size == 0;
}

//打印顺序表
void print(SeqList* list)
{
	assert(list);
	int i = 0;
	if (ifNull(list))
		printf("The SeqList is NULL ,cannot print.\n");
	else
	{
		for (i = 0; i < list->size; ++i)
		{
			printf("%d ", list->data[i]);
		}
		printf("\n");
	}
}

//头插
void SeqListInsertHead(SeqList* list, ElementType x)
{
	assert(list);
	int i = 0;
	if (ifFull(list))
	{
		printf("SeqList is Full,cannot insert %d.\n",x);
	}
	else 
	{
		for (i = list->size - 1; i >= 0; --i)
		{
			list->data[i + 1] = list->data[i];
		}
		list->data[0] = x;
		list->size++;
	}
}

//尾插
void SeqListInsertTail(SeqList* list, ElementType x)
{
	assert(list);
	if (ifFull(list))
	{
		printf("SeqList is Full,cannot insert %d.\n", x);
	}
	else
	{
		list->data[list->size] = x;
		list->size++;
	}
}

//头删
void SeqListRemoveHead(SeqList* list,int num)
{
	assert(list);
	int i = 0;
	i += num;
	if (list->size < num)
	{
		printf("SeqList size less than the number of remove.\n");
	}
	else
	{
		for (; i < list->size; i++)
		{
			list->data[i - num] = list->data[i];
		}
		printf("Successfully deleted.\n");
		list->size -= num;
	}
}
//尾删
void SeqListRemoveTail(SeqList* list, int num)
{
	assert(list);
	if (list->size < num)
	{
		printf("SeqList size less than the number of remove.\n");
	}
	else
	{
		list->size -= num;
		printf("Successfully deleted.\n");
	}
}

//指定位置删除
void SeqListRemoveLoc(SeqList* list, int loc)
{
	assert(list);
	int i = 0;
	i += loc;
	if (loc < 0 || loc > list->size)
		printf("The specified location does not exist and cannot be deleted.\n");
	else
	{
		for (; i < list->size; i++)
		{
			list->data[i - 1] = list->data[i];
			list->size --;
			printf("Successfully deleted.\n");
		}
	}
}

//表的大小
int SeqListSize(SeqList* list)
{
	return list->size;
}

//指定位置插入
void SeqListInsertLoc(SeqList* list, int loc,ElementType x)
{
	assert(list);
	if (loc < 0 || loc > list->size)
		printf("The specified location does not exist and cannot be deleted.\n");
	else
	{
		int i = 0;
		i += list->size - 1;
		for (; i >= loc - 1; --i)
		{
			list->data[i + 1] = list->data[i];
		}
		list->size++;
		list->data[loc - 1] = x;
	}
}

//排序
void SeqListSort(SeqList* list)
{
	int i, j;
	ElementType mid;
	for (j = 0; j < list->size;j++)
	for (i = j; i < list->size -1; ++i)
	{
		if (list->data[i] > list->data[i + 1])
		{
			mid = list->data[i];
			list->data[i] = list->data[i + 1];
			list->data[i + 1] = mid;
		}
	}
}
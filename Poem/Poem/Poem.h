#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>   
#include<string.h>
#define MAX_NUM 100//宏定义，最大数量

typedef struct _Poem          
{
	int num;//编号
	char name[20];//题目
	char genre[20];//体裁
	char dynasty[20];//朝代
	char author[20];//作者
	char content[100];//内容
}Poem;
//向结构体数组中添加一个诗歌
void Add(Poem arr[],int* size);
//根据所给索引值（数组下标）删除诗歌
void Del(Poem arr[], int index, int* size);
//打印有效诗歌
void Print(Poem arr[],int size);
//按诗歌编号查找一首诗歌,如果找到则打印，否则提示没有找到
void Find(Poem arr[],int index,int size);
//修改诗歌信息，根据所给诗歌编号查找到对应的诗歌
void Modify(Poem arr[],int index,int size);
//将诗歌保存到poem.txt文件中
void Save(Poem arr[],int size);
//菜单
void Menue(Poem arr[],int* size);
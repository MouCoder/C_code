#define _CRT_SECURE_NO_WARNINGS 1
#include"Poem.h"

//向结构体数组中添加一个诗歌
void Add(Poem arr[], int* size)
{
	//添加信息
	printf("Enter num:");
	scanf("%d",&(arr[*size].num));
	printf("Enter name:");
	scanf("%s",arr[*size].name);
	printf("Enter genre:");
	scanf("%s", arr[*size].genre);
	printf("Enter dynasty:");
	scanf("%s", arr[*size].dynasty);
	printf("Enter author:");
	scanf("%s", arr[*size].author);
	printf("Enter content:");
	scanf("%s", arr[*size].content);
	//有效元素加1
	(*size)++;
}
//根据所给诗歌编号删除诗歌
void Del(Poem arr[], int index,int* size)
{
	//将该位置后的值向前移动一个位置，同时有效元素个数size--
	int i,j = 0;
	char c;
	for (; j < *size; j++)
	{
		//找到了，确定删除
		if (arr[j].num == index)
		{
			printf("确定删除？（Y/N）");
			scanf("%c", &c);
			scanf("%c", &c);
			//不删除，直接退出
			if (c == 'N')
				return;
			//进行删除
			i = j + 1;
			for (; i < *size; i++)
			{
				arr[j - 1] = arr[j];
			}
			(*size)--;
			printf("删除成功\n");
			return;
		}
	}
	printf("你要删除的诗歌不存在\n");
}
//打印有效诗歌
void Print(Poem arr[],int size)
{
	int i = 0;
	//判断是否存有诗歌
	if (size == 0)
	{
		printf("没有诗歌可以打印\n");
		return;
	}
	for (; i < size; i++)
		printf("编号：%d 题目：%s 体裁：%s 朝代：%s 作者：%s 内容：%s\n",arr[i].num,arr[i].name,arr[i].genre,arr[i].dynasty,arr[i].author,arr[i].content);
}
//按诗歌编号查找一首诗歌,如果找到则打印，否则提示没有找到
void Find(Poem arr[], int index, int size)
{
	int i = 0;
	for (; i < size; i++)
	{
		if (arr[i].num == index)
		{
			printf("查找结果：  编号：%d 题目：%s 体裁：%s 朝代：%s 作者：%s 内容：%s\n", arr[i].num, arr[i].name, arr[i].genre, arr[i].dynasty, arr[i].author, arr[i].content);
			return;
		}
	}
	printf("没有找到此编号的诗歌\n");
}
//修改诗歌信息，根据所给诗歌编号查找到对应的诗歌
void Modify(Poem arr[], int index, int size)
{
	//查找对应诗歌编号
	int i = 0;
	for (; i < size; i++)
	{
		if (arr[i].num == index)
		{
			printf("Enter num:");
			scanf("%d", &(arr[i].num));
			printf("Enter name:");
			scanf("%s", arr[i].name);
			printf("Enter genre:");
			scanf("%s", arr[i].genre);
			printf("Enter dynasty:");
			scanf("%s", arr[i].dynasty);
			printf("Enter author:");
			scanf("%s", arr[i].author);
			printf("Enter content:");
			scanf("%s", arr[i].content);
			return;
		}
	}
	printf("没有找到要修改的诗歌\n");
}
//将诗歌保存到poem.txt文件中
void Save(Poem arr[], int size)
{
	int i = 0;
	if (size == 0)
	{
		printf("没有需要保存的诗歌\n");
		return;
	}
	FILE* file = fopen("C:\\Users\\user\\Desktop\\poem.txt", "w");//打开一个只写文件
	//判断文件打开是否成功
	if (file == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	//写入文件
	for (; i < size; i++)
	{
		fprintf(file, "%d", arr[i].num);
		fprintf(file, "%c", ' ');
		fprintf(file, "%s", arr[i].name);
		fprintf(file, "%c", ' ');
		fprintf(file, "%d", arr[i].genre);
		fprintf(file, "%c", ' ');
		fprintf(file, "%d", arr[i].dynasty);
		fprintf(file, "%c", ' ');
		fprintf(file, "%d", arr[i].author);
		fprintf(file, "%c", ' ');
		fprintf(file, "%d", arr[i].content);
		fprintf(file, "%c", '\n');
	}
	printf("写入文件成功\n");
	//关闭f1文件
	fclose(file);

}
void Menue(Poem arr[], int* size)
{
	int chioce;
	int num;
	printf("-------------------\n");
	printf("-1.添加     2.删除-\n");
	printf("-3.打印     4.修改-\n");
	printf("-5.查找     6.保存-\n");
	printf("-0.退出           -\n");
	printf("-------------------\n");
	do
	{
		printf("请选择:>");
		scanf("%d", &chioce);
			switch (chioce)
			{
			case 0:break;
			case 1:
				Add(arr,size);
				break;
			case 2:
				printf("请输入要删除的诗歌的编号：");
				scanf("%d",&num);
				Del(arr,num,size);
				break;
			case 3:
				Print(arr,*size);
				break;
			case 4:
				printf("请输入要修改的诗歌的编号：");
				scanf("%d", &num);
				Modify(arr,num,*size);
				break;
			case 5:
				printf("请输入要查找的诗歌的编号：");
				scanf("%d", &num);
				Find(arr,num,*size);
				break;
			case 6:
				Save(arr,*size);
				break;
			default:
				printf("输入有误，请重新输入\n");
			}
	} while (chioce);
}

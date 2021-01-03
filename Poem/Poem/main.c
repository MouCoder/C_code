#define _CRT_SECURE_NO_WARNINGS 1
#include"Poem.h"

int main()
{
	Poem arr[MAX_NUM];
	int size = 0;//size表示有效数个数量
	Menue(arr,&size);
	return 0;
}


//int Addnew(Poem arr[], int cur)  //录入数组的系列变量
//{
//	system("cls");             //执行命令“清屏”
//	printf("输入诗歌编号:");
//	//输入诗歌的详细信息，存入arr结构体数组中
//	scanf("%d", &arr[cur].num);
//	printf("输入诗歌题目:");
//	scanf("%s", arr[cur].name);
//	printf("输入诗歌类型:");
//	scanf("%s", arr[cur].genre);
//	printf("输入诗歌朝代:");
//	scanf("%s", arr[cur].dynasty);
//	printf("输入诗歌作者:");
//	scanf("%s", &arr[cur].author);
//	printf("输入诗歌内容:");
//	scanf("%s", &arr[cur].content);
//	printf("录入成功!\n");
//	system("pause");          //冻结屏幕，用户按任意键结束
//	return cur + 1;             //添加成功后，诗歌总数+1，并返回
//}//第一个人
//
//void Xianshi(Poem arr[], int n) //显示界面，n为诗歌总数
//{
//	int i; //i为所录入诗歌数
//	system("cls");         // 执行命令“清屏”
//	for (i = 0; i<n; i++)
//	{
//		printf(" 编号:%d  题目:%s  类型:%s  朝代:%s  作者:%s  内容:%s\n", arr[i].num, arr[i].name, arr[i].genre, arr[i].dynasty, arr[i].author, arr[i].content);
//	}//显示前N个诗歌的信息
//}//第二个人
//
//void Xiugai(Poem arr[], int cur)//修改诗歌信息，cur为诗歌总数
//{
//	//按编号查找到诗歌并进行修改
//	int i;//i为诗歌数
//	int temp;//诗歌编号
//	char chioce[20];//后面（Y/N）判断的输入变量
//	Poem swap;//定义一个修改后的数组
//	system("cls");
//	printf("请输入要修改的诗歌编号:");
//	scanf("%d", &temp);   //用户输入诗歌编号
//	//浏览所有诗歌，查找编号为temp的诗歌
//	for (i = 0; i<cur; i++)
//	{
//		if (temp == arr[i].num)  //如果编号等于temp，结束循环，此时i表示的就是编号为temp的诗歌在数组中对应的下标
//		{
//			break;
//		}
//	}
//	if (i == cur)            //如果i==cur，数组已经浏览完了，表示没有找到相应的编号的诗歌
//	{
//		//提示用户输入错误，并返回
//		printf("无该诗歌信息!\n");
//		system("pause");
//		return;
//	}
//	//找到要修改的诗歌后，将诗歌信息显示
//	Xianshi(&arr[i], 1);//用户输入的信息，前面说的为什么要先写录入函数
//	printf("\n输入新的诗歌编号:");
//	scanf("%d", &swap.num);
//	printf("输入诗歌题目:");
//	scanf("%s", swap.name);
//	printf("输入诗歌类型:");
//	scanf("%s", swap.genre);
//	printf("输入诗歌年代:");
//	scanf("%s", swap.dynasty);
//	printf("输入诗歌作者:");
//	scanf("%s", swap.author);
//	printf("输入诗歌内容:");
//	scanf("%s", swap.content);
//	printf("确认修改？(Y/N)\n");
//	scanf("%c", &chioce);//将缓冲区留下的无用换行处理掉，因为输入Y/N完时要输入回车，它会留在缓冲区，若不处理掉就无法输入
//	scanf("%c", &chioce);
//	{
//		if (strcmp(chioce, "Y"))
//		{
//			arr[i] = swap;
//			printf("修改成功!\n");
//		}
//		else  printf("修改失败");
//	}
//	system("pause");
//}//第三个人
//
//void Chaxun_Num(Poem arr[], int cur)//查询设备信息，cur为诗歌总数
//{
//	int i;  //诗歌数
//	int temp;//诗歌编号
//	system("cls");           //“清屏”
//	printf("请输入要查询的诗歌编号:");
//	scanf("%d", &temp);
//	for (i = 0; i<cur; i++)
//	{
//		if (temp == arr[i].num)
//		{
//			break;  //等于其中一个，跳出
//		}
//	}
//	if (i == cur)
//	{
//		printf("无该诗歌信息!\n");
//	}
//	else
//	{
//		Xianshi(&arr[i], 1);    //显示一个诗歌的结构体数组
//	}
//	system("pause");
//}//第四个人
//
//void Save_File(Poem arr[], int cur)//保存文件
//{
//	int i;  //诗歌数
//	FILE* fp = fopen("Poem.txt", "w+");//通过读写的方式建立名为“Poem.txt”的文件
//	if (fp == NULL)                 //如果不能实现打开的任务，	
//	{
//		return;                 //	直接返回
//	}
//	for (i = 0; i<cur; i++)           //浏览诗歌数组，逐个读入文件
//	{
//		fwrite(&arr[i], sizeof(Poem), 1, fp);      //将数组的arr[i]按照Poem中的字节数（4字节）取出并写入到当前fp所指向的文件中的指定位置
//	}
//	fclose(fp);                  //关闭文件,释放缓冲区
//}
//int Open_File(Poem arr[])         //打开文件
//{
//	int i = 0;
//	FILE* fp = fopen("Poem.txt", "r+"); //通过读写的方式打开一个名为“Poem.txt”的文件，如果文件不存在创建一个文件
//	//如果文件打开或创建失败，直接结束程序
//	if (fp == NULL)
//	{
//		return 0;
//	}
//	while (fread(&arr[i], sizeof(Poem), 1, fp))	   //将数组的arr[i]按照Poem中的字节数（4字节）读取到当前fp所指向的文件中的指定位置
//	{
//		i++;                //每读入一个诗歌，i就+1
//	}
//	return i;              //将读入的诗歌总数作为返回值进行返回
//}//第五个人
//
//int menu()//菜单功能
//{
//	//显示所有功能，并且让用户输入要实现的功能，并将功能序号作为返回值进行返回
//	int chioce;//用户输入的选择
//	printf("诗歌信息管理系统\n\n");
//	printf("1:录入诗歌信息:\n");
//	printf("2:修改诗歌信息:\n");
//	printf("3:查询诗歌信息:\n");
//	printf("4:显示全部诗歌:\n");
//	printf("0:退出！\n");
//	printf("请输入选项:");//提示用户输入
//	scanf("%d", &chioce);//用户输入
//	//判断用户输入，如果输入错误（不在0~4范围内就表示输入错误）提示用户重新输入
//	while (chioce<0 || chioce>4)
//	{
//		printf("范围错误，请重新输入！:");
//		scanf("%d", &chioce);
//	}
//	return chioce;
//}//一起完成
//
//int main()
//{
//	int chioce;      //储存功能序号
//	Poem poem[MAX_NUM]; //定义一个结构体数组，存储诗歌，最多存储MAX_NUM个（MAX_NUM是上边宏定义 的值）
//	int NUM = 0;          //存储保存到文件中的诗歌的数量
//	NUM = Open_File(poem);   //调用Open_File()函数，将诗歌存入文件中，并且将诗歌总数保存在NUM中
//	do
//	{
//		chioce = menu();//调用menu函数，选择要功能，将功能序号存储在chioce中
//		//利用switch分支结构，调用相应的函数（chioce对应的函数）
//		switch (chioce)
//		{
//		case 1:
//			NUM = Addnew(poem, NUM);  //调用录入函数
//			break;
//		case 2:
//			Xiugai(poem, NUM);      //调用修改函数
//			break;
//		case 3:
//			Chaxun_Num(poem, NUM);    //调用查询函数
//			break;
//		case 4:
//			Xianshi(poem, NUM);       //调用显示函数
//			system("pause");
//			break;
//		case 0:
//			printf("退出成功\n");
//			break;
//		default:printf("输入有误，请重新输入");
//		}
//	} while (chioce != 0);          //退出界面
//	Save_File(poem, NUM);//将诗歌保存到文件中
//	return 0;
//}//一起完成

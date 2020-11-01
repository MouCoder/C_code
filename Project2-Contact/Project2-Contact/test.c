#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//void test()
//{
//	ContactBook B;
//	CB_Init(&B);
//	CB_Add(&B,"武松1","19522469983","工程大",18);
//	CB_Add(&B, "松江", "19522469983", "工程大", 18);
//	CB_Add(&B, "武松3", "19522469983", "工程大", 18);
//	CB_Add(&B, "武松4", "19522469983", "工程大", 18);
//	CB_Add(&B, "武松5", "19522469983", "工程大", 18);
//	Contact* ret = CB_Search(&B, "武松3");
//	CB_Del(&B, "武松3");
//	CB_Update_tel(&B, "武松4", "110");
//	CB_Update_age(&B, "武松4", 100);
//	CB_Update_addr(&B, "武松4", "西科大");
//}
int main()
{
	int option;
	ContactBook cba;
	char name[NAME_MS];
	char addr[ADDR_MS];
	char tel[TEL_MS];
	short age;
	do
	{
		printf("***************************************\n");
		printf("1.添加联系人   2.删除联系人\n");
		printf("3.查找联系人   4.修改联系人\n");
		printf("0.exit\n");
		printf("请选择:>");
		scanf("%d",&option);
		switch (option)
		{
		case 0:
			break;
		case 1:
			printf("请依次输入姓名 电话 地址 年龄:>\n");
			scanf("%s %s %s %d",name,tel,addr,&age);
			CB_Add(&cba,name,tel,addr,age);
			break;
		case 2:
			printf("请输入要删除的联系人的姓名:>");
			scanf("%s", name);
			CB_Del(&cba, name);
			break;
		case 3:
			printf("请输入要查找的联系人的姓名:>");
			scanf("%s", name);
			print(CB_Search(&cba, name));
			break;
		case 4:
			printf("****************************************\n");
			printf("1.修改地址   2.修改年龄   3.修改电话\n");
			printf("请选择:>");
			scanf("%d",&option);
			switch (option)
			{
			case 1:
				printf("请输入要修改的联系人的姓名和地址:>");
				scanf("%s %s",name,tel);
				CB_Update_addr(&cba, name, addr);
				break;
			case 2:
				printf("请输入要修改的联系人的姓名和年龄:>");
				scanf("%s %d", name, &age);
				CB_Update_age(&cba, name, age);
				break;
			case 3:
				printf("请输入要修改的联系人的姓名和电话:>");
				scanf("%s %s", name, tel);
				CB_Update_addr(&cba, name, addr);
				break;
			default:
				printf("输入错误\n");
				break;
			}
			break;
		default:printf("输入有误，请重新输入\n");
		}
	}while(option);
	return 0;
}
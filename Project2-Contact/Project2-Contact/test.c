#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//void test()
//{
//	ContactBook B;
//	CB_Init(&B);
//	CB_Add(&B,"����1","19522469983","���̴�",18);
//	CB_Add(&B, "�ɽ�", "19522469983", "���̴�", 18);
//	CB_Add(&B, "����3", "19522469983", "���̴�", 18);
//	CB_Add(&B, "����4", "19522469983", "���̴�", 18);
//	CB_Add(&B, "����5", "19522469983", "���̴�", 18);
//	Contact* ret = CB_Search(&B, "����3");
//	CB_Del(&B, "����3");
//	CB_Update_tel(&B, "����4", "110");
//	CB_Update_age(&B, "����4", 100);
//	CB_Update_addr(&B, "����4", "���ƴ�");
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
		printf("1.�����ϵ��   2.ɾ����ϵ��\n");
		printf("3.������ϵ��   4.�޸���ϵ��\n");
		printf("0.exit\n");
		printf("��ѡ��:>");
		scanf("%d",&option);
		switch (option)
		{
		case 0:
			break;
		case 1:
			printf("�������������� �绰 ��ַ ����:>\n");
			scanf("%s %s %s %d",name,tel,addr,&age);
			CB_Add(&cba,name,tel,addr,age);
			break;
		case 2:
			printf("������Ҫɾ������ϵ�˵�����:>");
			scanf("%s", name);
			CB_Del(&cba, name);
			break;
		case 3:
			printf("������Ҫ���ҵ���ϵ�˵�����:>");
			scanf("%s", name);
			print(CB_Search(&cba, name));
			break;
		case 4:
			printf("****************************************\n");
			printf("1.�޸ĵ�ַ   2.�޸�����   3.�޸ĵ绰\n");
			printf("��ѡ��:>");
			scanf("%d",&option);
			switch (option)
			{
			case 1:
				printf("������Ҫ�޸ĵ���ϵ�˵������͵�ַ:>");
				scanf("%s %s",name,tel);
				CB_Update_addr(&cba, name, addr);
				break;
			case 2:
				printf("������Ҫ�޸ĵ���ϵ�˵�����������:>");
				scanf("%s %d", name, &age);
				CB_Update_age(&cba, name, age);
				break;
			case 3:
				printf("������Ҫ�޸ĵ���ϵ�˵������͵绰:>");
				scanf("%s %s", name, tel);
				CB_Update_addr(&cba, name, addr);
				break;
			default:
				printf("�������\n");
				break;
			}
			break;
		default:printf("������������������\n");
		}
	}while(option);
	return 0;
}
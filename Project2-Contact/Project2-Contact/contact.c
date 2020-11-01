#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"
void CB_Init(ContactBook* cbi)
{
	cbi->size = 0;
}
void CB_Add(ContactBook* cba,char* name,char* tel,char* addr,short age)
{
	strcpy(cba->ct_array[cba->size].name, name);
	strcpy(cba->ct_array[cba->size].tel, tel);
	strcpy(cba->ct_array[cba->size].addr, addr);
	cba->ct_array[cba->size].age = age;
	cba->size++;
}
Contact* CB_Search(ContactBook* cbs, char* name)
{
	int i = 0;
	for (i = 0; i < cbs->size; i++)
	{
		if (strcmp(cbs->ct_array[i].name, name) == 0)
		{
			return &cbs->ct_array[i];
		}
	}
	return NULL;
}
void CB_Del(ContactBook* cbd, char*name)
{
	Contact* ret = CB_Search(cbd, name);
	memmove(ret,ret+1,sizeof(Contact)*(cbd->ct_array+(cbd->size - 1)-(ret+1)+1));
	cbd->size--;
}
void CB_Update_tel(ContactBook* cbt,char* name,char* tel)
{
	Contact* ret = CB_Search(cbt,name);
	strcpy(ret->tel, tel);
}
void CB_Update_addr(ContactBook* cbt, char* name, char* addr)
{
	Contact* ret = CB_Search(cbt, name);
	strcpy(ret->addr,addr);
}
void CB_Update_age(ContactBook* cbt, char* name, short age)
{
	Contact* ret = CB_Search(cbt, name);
	ret->age = age;
}
void print(Contact* cb_p)
{
	printf("*****************************************\n");
	printf("姓名：%s\n",cb_p->name);
	printf("年龄：%d\n", cb_p->age);
	printf("电话：%s\n", cb_p->tel);
	printf("地址：%s\n", cb_p->addr);
	printf("\n");
}


#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#define NAME_MS 40
#define TEL_MS 10
#define ADDR_MS 50
#define CT_ARRAY 100

typedef struct Contact
{
	char name[NAME_MS];
	short age;
	char tel[TEL_MS];
	char addr[ADDR_MS];
}Contact;
typedef struct ContactBook
{
	Contact ct_array[CT_ARRAY];
	int size;
}ContactBook;

void CB_Init(ContactBook* cbi);
void CB_Add(ContactBook* cba, char* name, char* tel, char* addr, short age);
Contact* CB_Search(ContactBook* cbs,char* name);
void CB_Del(ContactBook* cbd,char*name);
void CB_Update_tel(ContactBook* cbt, char* name, char* tel);
void CB_Update_addr(ContactBook* cbt, char* name, char* addr);
void CB_Update_age(ContactBook* cbt, char* name,short age);
void print(Contact* cb_p);
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>   
#include<string.h>
#define MAX_NUM 100//�궨�壬�������

typedef struct _Poem          
{
	int num;//���
	char name[20];//��Ŀ
	char genre[20];//���
	char dynasty[20];//����
	char author[20];//����
	char content[100];//����
}Poem;
//��ṹ�����������һ��ʫ��
void Add(Poem arr[],int* size);
//������������ֵ�������±꣩ɾ��ʫ��
void Del(Poem arr[], int index, int* size);
//��ӡ��Чʫ��
void Print(Poem arr[],int size);
//��ʫ���Ų���һ��ʫ��,����ҵ����ӡ��������ʾû���ҵ�
void Find(Poem arr[],int index,int size);
//�޸�ʫ����Ϣ����������ʫ���Ų��ҵ���Ӧ��ʫ��
void Modify(Poem arr[],int index,int size);
//��ʫ�豣�浽poem.txt�ļ���
void Save(Poem arr[],int size);
//�˵�
void Menue(Poem arr[],int* size);
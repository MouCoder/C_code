#define _CRT_SECURE_NO_WARNINGS 1
#include"Poem.h"

//��ṹ�����������һ��ʫ��
void Add(Poem arr[], int* size)
{
	//�����Ϣ
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
	//��ЧԪ�ؼ�1
	(*size)++;
}
//��������ʫ����ɾ��ʫ��
void Del(Poem arr[], int index,int* size)
{
	//����λ�ú��ֵ��ǰ�ƶ�һ��λ�ã�ͬʱ��ЧԪ�ظ���size--
	int i,j = 0;
	char c;
	for (; j < *size; j++)
	{
		//�ҵ��ˣ�ȷ��ɾ��
		if (arr[j].num == index)
		{
			printf("ȷ��ɾ������Y/N��");
			scanf("%c", &c);
			scanf("%c", &c);
			//��ɾ����ֱ���˳�
			if (c == 'N')
				return;
			//����ɾ��
			i = j + 1;
			for (; i < *size; i++)
			{
				arr[j - 1] = arr[j];
			}
			(*size)--;
			printf("ɾ���ɹ�\n");
			return;
		}
	}
	printf("��Ҫɾ����ʫ�費����\n");
}
//��ӡ��Чʫ��
void Print(Poem arr[],int size)
{
	int i = 0;
	//�ж��Ƿ����ʫ��
	if (size == 0)
	{
		printf("û��ʫ����Դ�ӡ\n");
		return;
	}
	for (; i < size; i++)
		printf("��ţ�%d ��Ŀ��%s ��ã�%s ������%s ���ߣ�%s ���ݣ�%s\n",arr[i].num,arr[i].name,arr[i].genre,arr[i].dynasty,arr[i].author,arr[i].content);
}
//��ʫ���Ų���һ��ʫ��,����ҵ����ӡ��������ʾû���ҵ�
void Find(Poem arr[], int index, int size)
{
	int i = 0;
	for (; i < size; i++)
	{
		if (arr[i].num == index)
		{
			printf("���ҽ����  ��ţ�%d ��Ŀ��%s ��ã�%s ������%s ���ߣ�%s ���ݣ�%s\n", arr[i].num, arr[i].name, arr[i].genre, arr[i].dynasty, arr[i].author, arr[i].content);
			return;
		}
	}
	printf("û���ҵ��˱�ŵ�ʫ��\n");
}
//�޸�ʫ����Ϣ����������ʫ���Ų��ҵ���Ӧ��ʫ��
void Modify(Poem arr[], int index, int size)
{
	//���Ҷ�Ӧʫ����
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
	printf("û���ҵ�Ҫ�޸ĵ�ʫ��\n");
}
//��ʫ�豣�浽poem.txt�ļ���
void Save(Poem arr[], int size)
{
	int i = 0;
	if (size == 0)
	{
		printf("û����Ҫ�����ʫ��\n");
		return;
	}
	FILE* file = fopen("C:\\Users\\user\\Desktop\\poem.txt", "w");//��һ��ֻд�ļ�
	//�ж��ļ����Ƿ�ɹ�
	if (file == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}
	//д���ļ�
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
	printf("д���ļ��ɹ�\n");
	//�ر�f1�ļ�
	fclose(file);

}
void Menue(Poem arr[], int* size)
{
	int chioce;
	int num;
	printf("-------------------\n");
	printf("-1.���     2.ɾ��-\n");
	printf("-3.��ӡ     4.�޸�-\n");
	printf("-5.����     6.����-\n");
	printf("-0.�˳�           -\n");
	printf("-------------------\n");
	do
	{
		printf("��ѡ��:>");
		scanf("%d", &chioce);
			switch (chioce)
			{
			case 0:break;
			case 1:
				Add(arr,size);
				break;
			case 2:
				printf("������Ҫɾ����ʫ��ı�ţ�");
				scanf("%d",&num);
				Del(arr,num,size);
				break;
			case 3:
				Print(arr,*size);
				break;
			case 4:
				printf("������Ҫ�޸ĵ�ʫ��ı�ţ�");
				scanf("%d", &num);
				Modify(arr,num,*size);
				break;
			case 5:
				printf("������Ҫ���ҵ�ʫ��ı�ţ�");
				scanf("%d", &num);
				Find(arr,num,*size);
				break;
			case 6:
				Save(arr,*size);
				break;
			default:
				printf("������������������\n");
			}
	} while (chioce);
}

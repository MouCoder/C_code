#define _CRT_SECURE_NO_WARNINGS 1
#include"Poem.h"

int main()
{
	Poem arr[MAX_NUM];
	int size = 0;//size��ʾ��Ч��������
	Menue(arr,&size);
	return 0;
}


//int Addnew(Poem arr[], int cur)  //¼�������ϵ�б���
//{
//	system("cls");             //ִ�����������
//	printf("����ʫ����:");
//	//����ʫ�����ϸ��Ϣ������arr�ṹ��������
//	scanf("%d", &arr[cur].num);
//	printf("����ʫ����Ŀ:");
//	scanf("%s", arr[cur].name);
//	printf("����ʫ������:");
//	scanf("%s", arr[cur].genre);
//	printf("����ʫ�賯��:");
//	scanf("%s", arr[cur].dynasty);
//	printf("����ʫ������:");
//	scanf("%s", &arr[cur].author);
//	printf("����ʫ������:");
//	scanf("%s", &arr[cur].content);
//	printf("¼��ɹ�!\n");
//	system("pause");          //������Ļ���û������������
//	return cur + 1;             //��ӳɹ���ʫ������+1��������
//}//��һ����
//
//void Xianshi(Poem arr[], int n) //��ʾ���棬nΪʫ������
//{
//	int i; //iΪ��¼��ʫ����
//	system("cls");         // ִ�����������
//	for (i = 0; i<n; i++)
//	{
//		printf(" ���:%d  ��Ŀ:%s  ����:%s  ����:%s  ����:%s  ����:%s\n", arr[i].num, arr[i].name, arr[i].genre, arr[i].dynasty, arr[i].author, arr[i].content);
//	}//��ʾǰN��ʫ�����Ϣ
//}//�ڶ�����
//
//void Xiugai(Poem arr[], int cur)//�޸�ʫ����Ϣ��curΪʫ������
//{
//	//����Ų��ҵ�ʫ�貢�����޸�
//	int i;//iΪʫ����
//	int temp;//ʫ����
//	char chioce[20];//���棨Y/N���жϵ��������
//	Poem swap;//����һ���޸ĺ������
//	system("cls");
//	printf("������Ҫ�޸ĵ�ʫ����:");
//	scanf("%d", &temp);   //�û�����ʫ����
//	//�������ʫ�裬���ұ��Ϊtemp��ʫ��
//	for (i = 0; i<cur; i++)
//	{
//		if (temp == arr[i].num)  //�����ŵ���temp������ѭ������ʱi��ʾ�ľ��Ǳ��Ϊtemp��ʫ���������ж�Ӧ���±�
//		{
//			break;
//		}
//	}
//	if (i == cur)            //���i==cur�������Ѿ�������ˣ���ʾû���ҵ���Ӧ�ı�ŵ�ʫ��
//	{
//		//��ʾ�û�������󣬲�����
//		printf("�޸�ʫ����Ϣ!\n");
//		system("pause");
//		return;
//	}
//	//�ҵ�Ҫ�޸ĵ�ʫ��󣬽�ʫ����Ϣ��ʾ
//	Xianshi(&arr[i], 1);//�û��������Ϣ��ǰ��˵��ΪʲôҪ��д¼�뺯��
//	printf("\n�����µ�ʫ����:");
//	scanf("%d", &swap.num);
//	printf("����ʫ����Ŀ:");
//	scanf("%s", swap.name);
//	printf("����ʫ������:");
//	scanf("%s", swap.genre);
//	printf("����ʫ�����:");
//	scanf("%s", swap.dynasty);
//	printf("����ʫ������:");
//	scanf("%s", swap.author);
//	printf("����ʫ������:");
//	scanf("%s", swap.content);
//	printf("ȷ���޸ģ�(Y/N)\n");
//	scanf("%c", &chioce);//�����������µ����û��д��������Ϊ����Y/N��ʱҪ����س����������ڻ�������������������޷�����
//	scanf("%c", &chioce);
//	{
//		if (strcmp(chioce, "Y"))
//		{
//			arr[i] = swap;
//			printf("�޸ĳɹ�!\n");
//		}
//		else  printf("�޸�ʧ��");
//	}
//	system("pause");
//}//��������
//
//void Chaxun_Num(Poem arr[], int cur)//��ѯ�豸��Ϣ��curΪʫ������
//{
//	int i;  //ʫ����
//	int temp;//ʫ����
//	system("cls");           //��������
//	printf("������Ҫ��ѯ��ʫ����:");
//	scanf("%d", &temp);
//	for (i = 0; i<cur; i++)
//	{
//		if (temp == arr[i].num)
//		{
//			break;  //��������һ��������
//		}
//	}
//	if (i == cur)
//	{
//		printf("�޸�ʫ����Ϣ!\n");
//	}
//	else
//	{
//		Xianshi(&arr[i], 1);    //��ʾһ��ʫ��Ľṹ������
//	}
//	system("pause");
//}//���ĸ���
//
//void Save_File(Poem arr[], int cur)//�����ļ�
//{
//	int i;  //ʫ����
//	FILE* fp = fopen("Poem.txt", "w+");//ͨ����д�ķ�ʽ������Ϊ��Poem.txt�����ļ�
//	if (fp == NULL)                 //�������ʵ�ִ򿪵�����	
//	{
//		return;                 //	ֱ�ӷ���
//	}
//	for (i = 0; i<cur; i++)           //���ʫ�����飬��������ļ�
//	{
//		fwrite(&arr[i], sizeof(Poem), 1, fp);      //�������arr[i]����Poem�е��ֽ�����4�ֽڣ�ȡ����д�뵽��ǰfp��ָ����ļ��е�ָ��λ��
//	}
//	fclose(fp);                  //�ر��ļ�,�ͷŻ�����
//}
//int Open_File(Poem arr[])         //���ļ�
//{
//	int i = 0;
//	FILE* fp = fopen("Poem.txt", "r+"); //ͨ����д�ķ�ʽ��һ����Ϊ��Poem.txt�����ļ�������ļ������ڴ���һ���ļ�
//	//����ļ��򿪻򴴽�ʧ�ܣ�ֱ�ӽ�������
//	if (fp == NULL)
//	{
//		return 0;
//	}
//	while (fread(&arr[i], sizeof(Poem), 1, fp))	   //�������arr[i]����Poem�е��ֽ�����4�ֽڣ���ȡ����ǰfp��ָ����ļ��е�ָ��λ��
//	{
//		i++;                //ÿ����һ��ʫ�裬i��+1
//	}
//	return i;              //�������ʫ��������Ϊ����ֵ���з���
//}//�������
//
//int menu()//�˵�����
//{
//	//��ʾ���й��ܣ��������û�����Ҫʵ�ֵĹ��ܣ��������������Ϊ����ֵ���з���
//	int chioce;//�û������ѡ��
//	printf("ʫ����Ϣ����ϵͳ\n\n");
//	printf("1:¼��ʫ����Ϣ:\n");
//	printf("2:�޸�ʫ����Ϣ:\n");
//	printf("3:��ѯʫ����Ϣ:\n");
//	printf("4:��ʾȫ��ʫ��:\n");
//	printf("0:�˳���\n");
//	printf("������ѡ��:");//��ʾ�û�����
//	scanf("%d", &chioce);//�û�����
//	//�ж��û����룬���������󣨲���0~4��Χ�ھͱ�ʾ���������ʾ�û���������
//	while (chioce<0 || chioce>4)
//	{
//		printf("��Χ�������������룡:");
//		scanf("%d", &chioce);
//	}
//	return chioce;
//}//һ�����
//
//int main()
//{
//	int chioce;      //���湦�����
//	Poem poem[MAX_NUM]; //����һ���ṹ�����飬�洢ʫ�裬���洢MAX_NUM����MAX_NUM���ϱߺ궨�� ��ֵ��
//	int NUM = 0;          //�洢���浽�ļ��е�ʫ�������
//	NUM = Open_File(poem);   //����Open_File()��������ʫ������ļ��У����ҽ�ʫ������������NUM��
//	do
//	{
//		chioce = menu();//����menu������ѡ��Ҫ���ܣ���������Ŵ洢��chioce��
//		//����switch��֧�ṹ��������Ӧ�ĺ�����chioce��Ӧ�ĺ�����
//		switch (chioce)
//		{
//		case 1:
//			NUM = Addnew(poem, NUM);  //����¼�뺯��
//			break;
//		case 2:
//			Xiugai(poem, NUM);      //�����޸ĺ���
//			break;
//		case 3:
//			Chaxun_Num(poem, NUM);    //���ò�ѯ����
//			break;
//		case 4:
//			Xianshi(poem, NUM);       //������ʾ����
//			system("pause");
//			break;
//		case 0:
//			printf("�˳��ɹ�\n");
//			break;
//		default:printf("������������������");
//		}
//	} while (chioce != 0);          //�˳�����
//	Save_File(poem, NUM);//��ʫ�豣�浽�ļ���
//	return 0;
//}//һ�����

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	//�ļ��Ĵ򿪺͹رվ���
//	FILE* f1;
//	//ע�⣺c�����еġ�\����ת���ַ��������ʹ�õĲ���ת����Ҫ���ж���ת�壬����������\\
//	
//	//����·������������ֻд�ķ�ʽ��txt.c�ļ�
//	f1 = fopen("C:\\Users\\user\\Desktop\\test.txt","w");
//	if (f1 == NULL)
//	{
//		printf("���ļ�ʧ��\n");
//		exit(-1);
//	}
//	//�ر�f1�ļ�
//	fclose(f1);
//
//	//��ֻд�ķ�ʽ�ӵ�ǰĿ¼��һ���ļ�
//	f1 = fopen("test.txt","w");
//	if (f1 == NULL)
//	{
//		printf("���ļ�ʧ��\n");
//		exit(-1);
//	}
//	//�ر�f1�ļ�
//	fclose(f1);
//
//	//��ǰĿ¼����һ��DebugĿ¼��һ���ļ�
//	f1 = fopen(".\\Debug\\test.txt", "w");
//	if (f1 == NULL)
//	{
//		printf("���ļ�ʧ��\n");
//		exit(-1);
//	}
//	//�ر�f1�ļ�
//	fclose(f1);
//	return 0;
//}

//int main()
//{
//	FILE* pfile1;
//	pfile1 = fopen("C:\\Users\\user\\Desktop\\test.txt","w");
//	if (pfile1 == NULL)
//	{
//		printf("ʧ��\n");
//		exit(-1);
//	}
//	fputc('h',pfile1);
//	printf("%c",fgetc(pfile1));
//	fclose(pfile1);
//	return 0;
//}

//int main()
//{
//	FILE* pfile1;
//	pfile1 = fopen("C:\\Users\\user\\Desktop\\test.txt", "r");
//	if (pfile1 == NULL)
//	{
//		printf("ʧ��\n");
//		exit(-1);
//	}
//	printf("%c", fgetc(pfile1));
//	fclose(pfile1);
//	return 0;
//}

//int main()
//{
//	FILE* pfile1;
//	char* str = (char*)malloc(11);
//	pfile1 = fopen("C:\\Users\\user\\Desktop\\test.txt", "r");
//	if (pfile1 == NULL)
//	{
//		printf("ʧ��\n");
//		exit(-1);
//	}
//	fgets(str, 11, pfile1);
//	printf("%s",str);
//	fclose(pfile1);
//	return 0;
//}

//int main()
//{
//	FILE* pfile1;
//	char* str = "hello world1";
//	pfile1 = fopen("C:\\Users\\user\\Desktop\\test.txt", "w");
//	if (pfile1 == NULL)
//	{
//		printf("ʧ��\n");
//		exit(-1);
//	}
//	fputs(str,pfile1);
//	fclose(pfile1);
//	return 0;
//}

//int main()
//{
//	FILE* pfile1;
//	char* str = (char*)malloc(11);;
//	pfile1 = fopen("C:\\Users\\user\\Desktop\\test.txt", "r");
//	if (pfile1 == NULL)
//	{
//		printf("ʧ��\n");
//		exit(-1);
//	}
//	fscanf(pfile1,"%s",str);
//	printf("%s\n",str);
//	fclose(pfile1);
//	return 0;
//}

//int main()
//{
//	FILE* pfile1;
//	char* str = "hello world1";
//	pfile1 = fopen("C:\\Users\\user\\Desktop\\test.txt", "w");
//	if (pfile1 == NULL)
//	{
//		printf("ʧ��\n");
//		exit(-1);
//	}
//	fprintf(pfile1, "%s", str);
//	fclose(pfile1);
//	return 0;
//}


//int main()
//{
//	FILE* pfile1;
//	char* str = "hello world1";
//	pfile1 = fopen("C:\\Users\\user\\Desktop\\test.txt", "w");
//	if (pfile1 == NULL)
//	{
//		printf("ʧ��\n");
//		exit(-1);
//	}
//	fputs("hello world",pfile1);
//
//	fclose(pfile1);
//	return 0;
//}

int main()
{
	FILE * pFile;
	pFile = fopen("C:\\Users\\user\\Desktop\\example.txt", "wb");
	fputs("This is an apple.", pFile);
	fseek(pFile, 9, SEEK_SET);
	fputs(" sam", pFile);
	fclose(pFile);
	return 0;
}
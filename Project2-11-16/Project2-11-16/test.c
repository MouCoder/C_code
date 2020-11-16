#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	//文件的打开和关闭举例
//	FILE* f1;
//	//注意：c语言中的‘\’是转义字符，如果想使用的不是转义需要进行二次转义，即输入两个\\
//	
//	//绝对路径：从桌面以只写的方式打开txt.c文件
//	f1 = fopen("C:\\Users\\user\\Desktop\\test.txt","w");
//	if (f1 == NULL)
//	{
//		printf("打开文件失败\n");
//		exit(-1);
//	}
//	//关闭f1文件
//	fclose(f1);
//
//	//以只写的方式从当前目录打开一个文件
//	f1 = fopen("test.txt","w");
//	if (f1 == NULL)
//	{
//		printf("打开文件失败\n");
//		exit(-1);
//	}
//	//关闭f1文件
//	fclose(f1);
//
//	//当前目录的下一级Debug目录打开一个文件
//	f1 = fopen(".\\Debug\\test.txt", "w");
//	if (f1 == NULL)
//	{
//		printf("打开文件失败\n");
//		exit(-1);
//	}
//	//关闭f1文件
//	fclose(f1);
//	return 0;
//}

//int main()
//{
//	FILE* pfile1;
//	pfile1 = fopen("C:\\Users\\user\\Desktop\\test.txt","w");
//	if (pfile1 == NULL)
//	{
//		printf("失败\n");
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
//		printf("失败\n");
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
//		printf("失败\n");
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
//		printf("失败\n");
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
//		printf("失败\n");
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
//		printf("失败\n");
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
//		printf("失败\n");
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
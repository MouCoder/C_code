#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

void test(int* arr)
{
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		//srand(time(0));
		arr[i] = rand();
	}
}
int main()
{
	//�������������ɵ�����
	int a[MAX_LENGTH];
	test(a);

	/*InsertSort(a, MAX_LENGTH);
	printf("��������");
	print(a, MAX_LENGTH);*/

	/*printf("ϣ������");
	ShellSort(a,MAX_LENGTH);
	print(a, MAX_LENGTH);*/

	/*printf("ѡ������");
	SelectSort(a,MAX_LENGTH);
	print(a, MAX_LENGTH);*/

	/*printf("ѡ��������Ż���");
	SelectSort2(a,sizeof(a)/sizeof(a[0]));
	print(a,sizeof(a)/sizeof(a[0]));*/

	/*printf("������");
	HeapSort(a,MAX_LENGTH);
	print(a, MAX_LENGTH);*/

	/*printf("ð������");
	BubbleSort(a, MAX_LENGTH);
	print(a, MAX_LENGTH);*/
	
	//��������
	//printf("����ָ�룺");
	/*printf("ǰ��ָ�뷨��");
	QuickSort(a,0,MAX_LENGTH-1);
	print(a,MAX_LENGTH);*/

	/*printf("��������ǵݹ飺");
	QuickSortNonR(a,0,MAX_LENGTH-1);
	print(a,MAX_LENGTH);*/

	//�鲢����
	/*printf("�鲢����");
	MergeSort(a,MAX_LENGTH);
	print(a,MAX_LENGTH);*/

	/*printf("�鲢����ǵݹ飺");
	MergeSortNonR(a,MAX_LENGTH);
	print(a, MAX_LENGTH);*/

	printf("��������");
	CountSort(a, MAX_LENGTH);
	print(a,MAX_LENGTH);

	return 0;
}
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
	//产生由随机数组成的数组
	int a[MAX_LENGTH];
	test(a);

	/*InsertSort(a, MAX_LENGTH);
	printf("插入排序：");
	print(a, MAX_LENGTH);*/

	/*printf("希尔排序：");
	ShellSort(a,MAX_LENGTH);
	print(a, MAX_LENGTH);*/

	/*printf("选择排序：");
	SelectSort(a,MAX_LENGTH);
	print(a, MAX_LENGTH);*/

	/*printf("选择排序的优化：");
	SelectSort2(a,sizeof(a)/sizeof(a[0]));
	print(a,sizeof(a)/sizeof(a[0]));*/

	/*printf("堆排序：");
	HeapSort(a,MAX_LENGTH);
	print(a, MAX_LENGTH);*/

	/*printf("冒泡排序：");
	BubbleSort(a, MAX_LENGTH);
	print(a, MAX_LENGTH);*/
	
	//快速排序
	//printf("左右指针：");
	/*printf("前后指针法：");
	QuickSort(a,0,MAX_LENGTH-1);
	print(a,MAX_LENGTH);*/

	/*printf("快速排序非递归：");
	QuickSortNonR(a,0,MAX_LENGTH-1);
	print(a,MAX_LENGTH);*/

	//归并排序
	/*printf("归并排序：");
	MergeSort(a,MAX_LENGTH);
	print(a,MAX_LENGTH);*/

	/*printf("归并排序非递归：");
	MergeSortNonR(a,MAX_LENGTH);
	print(a, MAX_LENGTH);*/

	printf("计数排序：");
	CountSort(a, MAX_LENGTH);
	print(a,MAX_LENGTH);

	return 0;
}
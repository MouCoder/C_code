#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

int main()
{
	Heap hp;
	HPDataType num[] = {6,5,4,3,2,1};
	HeapCreate(&hp, num, 6);
	HeapPush(&hp,7);
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");
	HeapPop(&hp);
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ",hp._a[i]);
	}
	printf("\n");

	int num1[] = {6,5,4,3,2,1};
	HeapSort(num1,6);
	for (int i = 0; i < 6; i++)
		printf("%d",num1[i]);

	int a[] = {1,5,6,8,58,69,74,55,23,48,56,97,10,22,33,55,11,0,5,4};

	PrintTopK(a,20,5);
	return 0;
}
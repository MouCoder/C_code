#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

int main()
{
	int heap[] = {10,5,5,9,6,8};
	int n = 6;
	//AdjustDown(heap,0,6);
	HeapCreate(heap,0,n);
	//HeapPush(heap,&n,4);
	HeapSort(heap,n);
	return 0;
}
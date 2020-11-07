#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
	//两数之和II---输入有序数组
	int *a = (int*)malloc(sizeof(int)* 2);
	for (int i = 0; i <= numbersSize - 2; ++i) {
		for (int j = i + 1; j <= numbersSize - 1; ++j) {
			if (numbers[i] + numbers[j] == target) {
				a[0] = i + 1;
				a[1] = j + 1;
				*returnSize = 2;
				return a;
			}
		}
	}
	*returnSize = 0;
	return 0;
}in()
{
	return 0;
}
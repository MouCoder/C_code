#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
bool searchMatrix(int matrix[][4], int target)
{
	int i = 0, j = 3;
	while (i <= 2 && j >= 0)
	{
		if (matrix[i][j] == target)
			return true;
		else if (matrix[i][j] > target)
			j--;
		else
			i++;
	}
	return false;
}
int main()
{
	int a[][4] = {{1, 3, 5, 7}, { 10, 11, 16, 20 }, { 23, 30, 34, 50 }};
	printf("%d\n",searchMatrix(a,51));
	return 0;
}
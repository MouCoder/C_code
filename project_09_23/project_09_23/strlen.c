#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int my_strlen(const char* p)
//{
//	int num = 0;
//	while (*(p++))
//	{
//		num++;
//	}
//	return num;
//}
//int main()
//{
//	char arr[] = "hello word";
//	int num = my_strlen(arr);
//	printf("%d\n", num);
//	return 0;
//}

//char * my_strcpy(char * dst, const char * src)
//{
//	char * cp = dst;
//	while (*cp++ = *src++);
//	return(dst);
//}

void swap_arr(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	int tmp = 0;


	while (left<right)
	{
		
		while ((left<right) && (arr[left] % 2 == 0))
		{
			left++;
		}

		while ((left<right) && (arr[right] % 2 == 1))
		{
			right--;
		}

		if (left<right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
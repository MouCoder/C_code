#define _CRT_SECURE_NO_WARNINGS 1

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水

int main()
{
	int battle = 0;//瓶子
	int water = 0;//水
	int money = 20;//钱数
	while (money)
	{
		money--;
		water++;
		battle++;
		if (battle == 2)
		{
			water++;
			battle++;
			battle -= 2;
		}
	}
	printf("一共可以喝%d瓶水\n", water);
}

//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//
//
//	scanf("%d", &money);
//
//	//方法1
//	total = money;
//	empty = money;
//	while (empty>1)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//
//	printf("%d", total);
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ

int main()
{
	int battle = 0;//ƿ��
	int water = 0;//ˮ
	int money = 20;//Ǯ��
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
	printf("һ�����Ժ�%dƿˮ\n", water);
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
//	//����1
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

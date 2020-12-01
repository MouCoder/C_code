#define _CRT_SECURE_NO_WARNINGS 1
int trailingZeroes(int n){

	int num = 5;
	int sum = 0;
	while (n / num)
	{
		sum += n / num;
		num *= 5;
	}
	return sum;
}
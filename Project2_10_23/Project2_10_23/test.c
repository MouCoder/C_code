#define _CRT_SECURE_NO_WARNINGS 1

//整数反转2
int reverse(int x)
{
	long long ret=0;
	while (x)
	{
		ret = ret*10 + x%10;
		x /= 10;
	}
	if (ret > 0)
	return ret > (int)ret ? 0 : ret;
	else
		return ret < (int)ret ? 0 : ret;
}
int main()
{
	return 0;
}
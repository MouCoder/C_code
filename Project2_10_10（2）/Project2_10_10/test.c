#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"

//加密：encrypt  解密：decode
//移位密码：Shift Substitution Cipher
//乘法密码：multiplicative cipher
//仿射密码：affine cipher

//求逆元
int x, y;
int ex_gcd(int k, int n)
{
	int q, t;
	if (n == 0){
		x = 1; y = 0;
		return k;
	}
	q = ex_gcd(n, k%n);
	t = x;
	x = y;
	y = t - k / n*y;
	x = (x + 26) % 26;
	return q;
}

//移位密码加密
void enOfSsc(char* p,int k)
{
	//加密算法：Ek(C)=(m+k) mod q (k<26)
	//其中k表示右移的位数，q=26
	//移位加密算法中英文字符a-z依次标序为0-25

	while (*p)
	{
		/*
		英文字母的序号与ASCII值有如下关系：对于小写字母 序号=（ASCII值%97），
		其中97为a的ASCII值，要通过字母序号得到相应字母的ASCII值只需要给序号加97即可
		（对于大写字母秩序将97换为65即可）
		*/
		//如果为小写字母
		if (*p >= 97)
		{
			*p = (((*p) % 97) + k) % 26 + 97;//向右移动k位，在取模得到相应的大写或者小写
		}
		//如果为大写字母
		else
		{
			*p = (((*p) % 65) + k) % 26 + 65;
		}
		p++;
	}
}
//移位密码解密
void deOfSsc(char* p , int k)
{
	/*
	由于解密算法中c-k可能为负数，导致ASCII值出错，
	因此解密算法需要在模26前加26.其他与加密算法相同，只是将加好变为减号。
	*/
	//解密算法：Dk(c)=(c-k) mod q
	//如果为小写字母
	while (*p)
	{
		if (*p >= 97)
		{
			*p = ((((*p) % 97) - k)+26) % 26 + 97;
		}
		//如果为大写字母
		else
		{
			*p =( (((*p) % 65) - k)+26) % 26 + 65;
		}
		p++;
	}
}

//乘法密码加密
void enOfMc(char* p,int k)
{
	/*
	在乘法加密算法中，0<k<n且k与n互素，即要满足gcd(k, n)=1，
	否则不存在模逆元，不能正确解密。因此，对于26个大写或小写
	英文字母所对应的秘钥空间为：[1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25]（即k的取值范围）
	*/

	//加密算法：c=i*k mod n
	//其中：0<k<n且k与n互素，即要满足gcd(k, n)=1,n=26
	//i为明文消息元素的下标

	while (*p)
	{
		//小写字母
		if (*p >= 97)
		{
			*p = (((*p) % 97) * k) % 26 + 97;
		}
		//小写字母
		else
		{
			*p = (((*p) % 65) * k) % 26 + 65;
		}
		p++;
	}
}
//乘法密码解密
void deOfMc(char* p,int k)
{
	//解密算法：D=j*X mod n
	//其中j为密文消息元素的下标
	//X为k（秘钥模逆元）的逆元
	//n=26
	ex_gcd(k, 26);
	printf("秘钥模逆元:%d\n", x);
	while (*p)
	{
		if (*p >= 97)
		{
			*p = (((*p) % 97) * x) % 26 + 97;
		}
		else
		{
			*p = (((*p) % 65) * x) % 26 + 65;
		}
		p++;
	}
}
//仿射密码加密
void enOfAc(char* p ,int a,int b)
{
	//加密算法：E(x) = (ax + b) (mod m)，其中，a与b互质且a与m互质，m = 26
	//x为明文下标
	while (*p)
	{
		if (*p >= 97)
		{
			*p =( (((*p) % 97) * a) + b) % 26 + 97;
		}
		else
		{
			*p = ((((*p) % 65) * a) + b)% 26 + 65;
		}
		p++;
	}
}
//放射密码解密
void deOfAc(char* p,int a,int b)
{
	//解密算法：D(x) = X (x - b) (mod m)，其中 X 是 a 在群的乘法逆元
	//x为明文下标
	int h;
	ex_gcd(a, 26);
	printf("秘钥模逆元:%d\n", x);
	while (*p)
	{
		if (*p >= 97)
		{
			h = x*(((*p) % 97) - b);
			if (h >= 0)
			{
				*p = h % 26 + 97;
			}
			else
			{
				*p = (h + ((-h / 26) + 1) * 26) % 26 + 97;
			}
		}
		else
		{
			h = x*(((*p) % 65) - b);
			if (h >= 0)
			{
				*p = h % 26 + 65;
			}
			else
			{
				*p = (h + ((-h / 26)+1)*26 ) % 26 + 65;
			}
		}
		p++;
	}
}

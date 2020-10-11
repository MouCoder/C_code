#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int ex_gcd(int k, int n);
//移位密码加密
void enOfSsc(char* p, int k);
//移位密码解密
void deOfSsc(char* p, int k);
//乘法密码加密
void enOfMc(char* p, int k);
//乘法密码解密
void deOfMc(char* p, int k);
//仿射密码加密
void enOfAc(char* p, int a, int b);
//放射密码解密
void deOfAc(char* p, int a, int b);
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void hexToTwo(char num[16], short key[64]);
void scan_f(int j, int k, short key[64]);
void replace(short key[65], short key2[56]);
void left(int digit, short CD[28]);
void C0D0Tokey2(short C0[28], short D0[28], short key2[56]);
void part(short key2[56], short C0[28], short D0[28]);
void replaceTo48(short P[16][48], short key2[56], int j);
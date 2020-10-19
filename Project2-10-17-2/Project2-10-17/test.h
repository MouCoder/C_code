#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void hexToTwo(char num[16], short key[64]);
void scan_f(int j, int k, short key[64]);
void replace(short key[65], short key2[56]);
void left(int digit, short CD[28]);
void C0D0Tokey2(short C0[28], short D0[28], short key2[56]);
void part(short key2[56], short C0[28], short D0[28]);
void replaceTo48(short P[16][48], short key2[56], int j);
void part_1(short password[64], short L0[32], short R0[32]);
void S_1(short E_1ORk1[48], short s_2[8][4]);
void encrypt(short password[64], short IP[64], short L0[32], short R0[32], short E_1[48], short E_1ORk1[48], short keyKids[16][48]);
void E(short R0[32], short E_1[48]);
int hexToTen(short n1, short n2, short n3, short n4);
void IP_1(short result[64], short merge[64]);
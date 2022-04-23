/**
*	@file		ex3_007.c
*	@brief		ユークリッドの互除法（別解）
*	@author		Hiroaki Nitobe / 新渡戸広明
*	@date		2022/04/24
*	@details	２つの正の整数を入力して、その最大公約数を、ユークリッドの互除法を用いて算出するプログラムを作成してください。
*				１．２つの整数の大きい方を被除数、小さい方を除数として除算を行い、剰余を求める。
*				２．剰余が０でない場合は、前回の除数を被除数に、前回の剰余を除数にして除算を行い、剰余を求める。
*				３．剰余が０になるまで２を繰り返し、剰余が０になったら、最後の除数が最大公約数。
*				出力イメージ
*				C:\Vc7\algorithm>ex3_010
*				数値1を入力してください => 384
*				数値2を入力してください => 720
*				720 / 384 -> 1...336
*				384 / 336 -> 1...48
*				336 / 48 -> 7...0
*				384と720の最大公約数は48です
*/

#include	<stdio.h>

int gcd(int a, int b);
void swap(int *x, int *y);

int main(void)
{
	int		n1, n2;

	/* 2つの数値を入力する */
	printf("数値1を入力してください => ");
	scanf("%d", &n1);
	
	printf("数値2を入力してください => ");
	scanf("%d", &n2);

	printf("%dと%dの最大公約数は%dです\n", n1, n2, gcd(n1, n2));
	
	return 0;
}

/**
*	@fn			int get_gcd(int a, int b)
*	@brief 		与えられた2値の最大公約数を返却する
*	@param[in]	a , b
*	@param[out]	最大公約数
*	@return 	int 最大公約数
*	@details 	ユークリッドの互除法で最大公約数を求める
*				https://ja.wikipedia.org/wiki/ユークリッドの互除法
*/
int gcd(int a, int b)
{
	if (b == 0) return 0;
	if (a < b) {
		swap(&a, &b);
	}
	
	printf("%d / %d -> %d...%d\n", a, b, a/b, a%b);
	
	if (a % b == 0) {
		return b;
	} else {
		return gcd(b, a % b);
	}
}

void swap(int *x, int *y)
{
	if (x != y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}

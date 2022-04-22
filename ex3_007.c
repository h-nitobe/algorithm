/**
*	@file		ex3_007.c
*	@brief		完全数と友愛数（別解）
*	@author		Hiroaki Nitobe / 新渡戸広明
*	@date		2022/04/24
*	@details	１から１００００までの完全数と、友愛数の組を求めるプログラムを作成して下さい。
*				自分自身以外の約数の総和が自分自身に等しくなる自然数を完全数（perfect number）といいます。
*				自分自身以外の約数の総和が、互いに他方の数と等しくなるような異なる自然数の組を友愛数（amicable number）と言います。
*				出力イメージ
*				C:\Vc7\algorithm>ex3_005
*				数値を入力してください＝＞ 1000
*				0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987,
*/

#include	<stdio.h>

#define		MAX		10000

int main(void)
{
	int	i, j;
	int	sum1, sum2;
	int perfect = 0, amicable = 0;
	
	/* 完全数を探す */
	
	printf("完全数ー＞");
	for (i = 1; i <= MAX; i++) {
		sum1 = 0;
		for (j = 1; j <= (i / 2); j++) {
			if (!(i % j)) {					// 約数を探す
				sum1+= j;					// 足しこむ
			}
		}
		if (i == sum1) {					// 約数の合計と自分自身が同じなら完全数
			printf(" %d,", i);
			perfect++;
		}
	}
	
	printf("\n1から%dまでに、完全数は%d個存在しました\n\n", MAX, perfect);
	
	/* 友愛数を探す */
	
	printf("友愛数ー＞");
	for (i = 1; i <= MAX; i++) {
		sum2 = sum1 = 0;
		for (j = 1; j <= (i / 2); j++) {
			if (!(i % j)) {					// 約数を探す
				sum1 += j;					// 足しこむ
			}
		}
		for (j = 1; j <= (sum1 / 2); j++) {
			if (!(sum1 % j)) {				// sum1 の約数を探す
				sum2 += j;					// 足しこむ
			}
		}
		if (i < sum1 && sum2 == i) {		// sum1 が自分自身より大きい場合、かつ、sum2 が自分自身なら友愛数
			printf(" (%d:%d),", i, sum1);
			amicable++;
		}
	}
	
	printf("\n1から%dまでに、友愛数は%d組存在しました\n", MAX, amicable);
	
	return 0;
}

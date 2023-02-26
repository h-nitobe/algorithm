/*
*	@file		eratos.c
*	@brief		sieve of Eratosthenes
*	@author		Hiroaki Nitobe / 新渡戸広明
*	@date		2022/08/27
*	@details	エラトステネスの篩
*				配列の無駄使い
*/

#include	<stdio.h>
#include	<string.h>
#include	<math.h>
#include	<time.h>

#define		PRIME	0				// 素数
#define		NON		1				// 非素数

#define		NUM		1000000000

void printCount(unsigned int pc, unsigned int denominator);

unsigned char	array[NUM] = { PRIME };		// とりあえず全部素数

int main(void)
{	
	unsigned int		i, j, k = 10;
	const unsigned int	RTN = (unsigned int)sqrt(NUM);
	unsigned int		count = 0, prev = 0;
	clock_t				start;
	
	fprintf(stderr, "NUM = %u\n", NUM);
	fprintf(stderr, "RTN = %u\n", RTN);

	start = clock();

	array[0] |= NON;									// 0 を除外
	array[1] |= NON;									// 1 を除外

	for (i = 2; i < NUM; i++) {
		if (array[i] == PRIME) {						// 素数なら
			fprintf(stdout,"%u ", i);					// 記録
			count++;									// カウントアップ
			if (count % 10 == 0) fprintf(stdout, "\n");	// 10毎に改行

			if (i < RTN) {								// sqrt(NUM)未満なら
				for (j = i + i; j <= NUM; j += i) {		// 倍数を
					array[j] = NON;						// 除外
				}
			}

//			if (i == (prev+2)) {
//				fprintf(stderr, "Twins : %u %u\n", prev, i);
//			}
//			if (i == (prev+4)) {
//				fprintf(stderr, "Cousin: %u %u\n", prev, i);
//			}
//			if (i == (prev+6)) {
//				fprintf(stderr, "Sexy  : %u %u\n", prev, i);
//			}
			prev = i;
		}
		if (i == k) {									// 途中経過表示
			printCount(count, i);
			k *= 10;									// 次の途中経過
		}
	}

	if ((i - 1) != (k / 10)) {					// Nが10の冪乗ではない場合
		printCount(count, i);
	}

	fprintf(stderr, "clock:%f\n",						// 実行時間表示
				(double)(clock() - start) / CLOCKS_PER_SEC);

	return 0;
}

void printCount(unsigned int pc, unsigned int denominator)
{
	unsigned int        m;
	char            u[8];

	fflush(stdout);

	if (denominator >= 1000000000000) {
		m = denominator / 1000000000000; strcpy(u, "兆");
	} else if (denominator >= 100000000) {
		m = denominator / 100000000; strcpy(u, "億");
	} else if (denominator >= 10000) {
		m = denominator / 10000; strcpy(u, "万");
	} else {
		m = denominator; strcpy(u, "　");
	}

	fprintf(stderr, "%4u%sまで： %10u： %10.6f%%\n",
		m, u, pc, (double)pc*100/denominator);
}

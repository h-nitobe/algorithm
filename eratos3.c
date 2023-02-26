/*
*	@file		eratos3.c
*	@brief		sieve of Eratosthenes
*	@author		Hiroaki Nitobe / 新渡戸広明
*	@date		2022/09/04
*	@details	エラトステネスの篩
*				64ビットパック
*				2の倍数、3の倍数除外
*/
#include	<stdio.h>
#include	<stdint.h>
#include	<string.h>
#include	<stdbool.h>
#include	<math.h>
#include	<time.h>

#define		PRIME	0UL		// 素数
#define		NON		1UL		// 非素数

#define		BPL		64

#define		NUM		10000000000UL
#define		NP3		(NUM/3)
#define		SLT		(NP3/BPL+1)

void printCount(uint64_t pc, uint64_t denominator);

uint64_t	array[SLT] = { PRIME };	// とりあえず全部素数

int main(void)
{	
	uint64_t		i, j = 0UL, k = 10UL;
	uint64_t		x, a, b;
	const uint64_t	RTN = (uint64_t)sqrt(NUM);
	uint64_t		pc = 0UL;
	bool			s;
	clock_t			start;

	fprintf(stderr, "NUM = %lu\n", NUM);
	fprintf(stderr, "NP3 = %lu\n", NP3);
	fprintf(stderr, "SLT = %lu\n", SLT);
	fprintf(stderr, "RTN = %lu\n", RTN);

	start = clock();

	array[0] |= NON << 0;			// 1 を除外 0*3+1=1

	fprintf(stdout,"%lu ", 2UL);	// 2 は素数
	pc++;							// カウントアップ

	fprintf(stdout,"%lu ", 3UL);	// 3 は素数
	pc++;							// カウントアップ

	for (i = 1UL; i < NP3; i++) {
		x = i*3+i%2+1;									// 値を求める
		if ((array[i/BPL] & (NON << i%BPL)) == PRIME) {	// 素数なら
			fprintf(stdout,"%lu ", x);					// 記録
			pc++;										// カウントアップ
			if (pc % 10 == 0) fprintf(stdout, "\n");	// 10毎に改行
			if (x < RTN) {
				s = 1;									// 
				b = (uint64_t)((double)x*2/3+0.5);		// オフセットb
				a = x*2-b;								// オフセットa
				for (j = i + a; j < NP3; j += s? a: b) {
					s = !s;
					array[j/BPL] |= (NON << j%BPL);		// 除外
				}
			}
		}
		if (x+3 == k) {								// 途中経過表示
			printCount(pc, x+3);
			k *= 10;								// 次の途中経過
		}
	}

	if (x+3 != (k/10)) {
		printCount(pc, x+3);
	}

	fprintf(stderr, "clock:%f\n",
		(double)(clock() - start) / CLOCKS_PER_SEC);

	return 0;
}

void printCount(uint64_t pc, uint64_t denominator)
{
	uint64_t	m;
	char		u[8];

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

	fprintf(stderr, "%4lu%sまで： %10lu： %10.6f%%\n",
			m, u, pc, (double)pc*100/denominator);
}

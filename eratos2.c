/*
*	@file		eratos2.c
*	@brief		sieve of Eratosthenes
*	@author		Hiroaki Nitobe / 新渡戸広明
*	@date		2022/08/27
*	@details	エラトステネスの篩
*				64ビットパック
*/
#include	<stdio.h>
#include	<stdint.h>
#include	<string.h>
#include	<math.h>
#include	<time.h>

#define		PRIME	0UL		// Prime number
#define		NON		1UL		// Non-prime number

#define		BPL		64

#define		NUM		1000000000UL
#define		NP2		(NUM/2)
#define		SLT		(NP2/BPL+1)

void printCount(uint64_t count, uint64_t denominator);

uint64_t	allay[SLT] = { PRIME };	// とりあえず全部素数

int main(void)
{	
	uint64_t	i, j = 0, k = 10UL;
	const uint64_t	RTN = (uint64_t)sqrt(NUM);
	uint64_t	count = 0UL;
	clock_t		start;
					
	fprintf(stderr, "NUM = %lu\n", NUM);
	fprintf(stderr, "NP2 = %lu\n", NP2);
	fprintf(stderr, "SLT = %lu\n", SLT);
	fprintf(stderr, "RTN = %lu\n", RTN);

	start = clock();

	allay[0] |= NON << 0;		// 1 を除外

	fprintf(stdout,"%lu ", 2UL);	// 2 は素数
	count++;					// カウントアップ

	for (i = 1; i < NP2; i++) {
		if ((allay[i/BPL] & (NON << i%BPL)) == PRIME) {	// 素数なら
			fprintf(stdout,"%lu ", i*2+1);
			fflush(stdout);
			count++;								// カウントアップ
			if (count % 10 == 0) fprintf(stdout, "\n");
			if (i*2+1 < RTN) {
				for (j = i + (i*2+1); j <= NP2; j += (i*2+1)) {	// 倍数を
					allay[j/BPL] |= (NON << j%BPL);				// 除外
				}
			}
		}
		if (i*2+2 == k) {			// 途中経過表示
			fflush(stdout);
			printCount(count, i*2+2);
			k *= 10;				// 次の途中経過
		}
	}

	if ((i*2) != (k/10)) {
		fflush(stdout);
		printCount(count, i*2+2);
	}

	fprintf(stderr, "clock:%f\n",
		(double)(clock() - start) / CLOCKS_PER_SEC);

	return 0;
}

void printCount(uint64_t count, uint64_t denominator)
{
	uint64_t	m;
	char		u[8];

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
			m, u, count, (double)count*100/denominator);
}

/**
*	@file		eratosthenes.c
*	@brief		sieve of Eratosthenes
*	@author		Hiroaki Nitobe / 新渡戸広明
*	@date		2022/04/23
*	@details	エラトステネスの篩
*				
*/

#include	<stdio.h>

#define		FALSE	0
#define		TRUE	1
//#define		N		8190
#define		N		65536

char	flag[N+1];

int isPrime(unsigned int n);

int main(void)
{	
	int i, p, k, cnt, pcnt;
	
	printf("%d ", 2);
	cnt = 1; pcnt = 1;
	
	for (i = 0; i <= N; i++) {
		flag[i] = TRUE;
	}
	for (i = 0; i <= N; i++) {
		if (flag[i]) {
			p = i + i + 3;
			if (isPrime(p)) pcnt++;
			printf("%d ", p);
			for (k = i + p; k <= N; k += p) {
				flag[k] = FALSE;
			}
			cnt++;
		}
	}
	printf("\n%d primes. check %d\n", cnt, pcnt);
	
	return 0;
}

/* nが素数であるかどうかを判定する */
int isPrime(unsigned int n)
{

    unsigned int i;

    if (n < 2) {				/* 2未満の場合は素数でない */
        
        return 0;
    }

    for (i = 2; i < n; i++) { 	/* nが2?n-1で割り切れるかどうかを確認 */
        if (n % i == 0) {		/* 2?n-1で割り切れる場合はnは素数でない */
            return 0;
        }
    }

    return 1;
}

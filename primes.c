/**
*	@file		primes.c
*	@brief		prime numbers
*	@author		Hiroaki Nitobe / �V�n�ˍL��
*	@date		2022/04/23
*	@details	�V���v����
*				
*/

#include	<stdio.h>

#define		N		9593

int	prime[N];

int isPrime(unsigned int n);

int main(void)
{	
	int j, k, x, cnt, pcnt;
	
	prime[0] = 2;
	x = 1; k = 1;
	printf("%d ", prime[0]);
	cnt = 1; pcnt = 1;
	
	while (k < N) {
		x += 2; j = 0;
		while (j < k && x% prime[j] != 0) j++;
		if ( j == k) {
			printf("%d ",  x);
			if (isPrime(x)) pcnt++;
			prime[k++] = x;
		}
	}
	printf("\n%d primes. check %d\n", k, pcnt);
}

/* n���f���ł��邩�ǂ����𔻒肷�� */
int isPrime(unsigned int n)
{

    unsigned int i;

    if (n < 2) {				/* 2�����̏ꍇ�͑f���łȂ� */
        return 0;
    }

    for (i = 2; i < n; i++) { 	/* n��2?n-1�Ŋ���؂�邩�ǂ������m�F */
        if (n % i == 0) {		/* 2?n-1�Ŋ���؂��ꍇ��n�͑f���łȂ� */
            return 0;
        }
    }

    return 1;
}

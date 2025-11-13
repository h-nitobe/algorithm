//  Kaprekar's constant 2

#include	<stdio.h>
#include	<stdlib.h>

void caprekar(char*ar);
int atoi4(char *a);
void itoa4(int n, char *a);
void asort4(char *a);
void dsort4(char *a);
void aswap(char *x, char *y);
void dswap(char *x, char *y);

int main(void)
{
	int 	cnt = 0;
	char	arr[4];
	int		num;

//　4桁マルチセットの組合せ（多重集合）	
//　「同じ4つの数字を使った並びは順序に関係なく1通りと数える」
	for(arr[0] = 0; arr[0] < 10; arr[0]++) {
		for(arr[1] = arr[0]; arr[1] < 10; arr[1]++) {
			for(arr[2] = arr[1]; arr[2] < 10; arr[2]++) {
				for(arr[3] = arr[2]; arr[3] < 10; arr[3]++) {
					caprekar(arr);
					cnt++;
				}
			}
		}
	}
	printf("-----\n%d\n", cnt);
}

void caprekar(char *ar)
{
	char	wk[4];
	int		i = 0, j, k, p;
	
	memcpy(wk, ar, 4);
	printf("\033[37m");			// 文字色白
	printf("%04d ", atoi4(wk));

	for (i = 0; i < 7; i++) {
		dsort4(wk);
		j = atoi4(wk);
		asort4(wk);
		k = atoi4(wk);
		p = j - k;
		itoa4(p, wk);
		if (p == 6174) {
			printf("\033[32m");	// 文字色緑
		}
		printf("%04d ", p);
	}
	printf("\n");
}

int atoi4(char *a)
{
	return a[0]*1000+a[1]*100+a[2]*10+a[3];
}

void itoa4(int n, char *a)
{	int		i;
	
	for (i = 0; i < 4; i++) {
		a[3-i] = n % 10; n /= 10;
	}
}

// 完全最小比較ネットワーク 昇順
void asort4(char *a)
{
	aswap(&a[0], &a[1]);
	aswap(&a[2], &a[3]);
	aswap(&a[0], &a[2]);
	aswap(&a[1], &a[3]);
	aswap(&a[1], &a[2]);
}

void aswap(char *x, char *y)
{
	char		t;
	
	if (*x > *y) {
		t = *x;
		*x = *y;
		*y = t;
	}
}

// 完全最小比較ネットワーク 降順
void dsort4(char *a)
{
	dswap(&a[0], &a[1]);
	dswap(&a[2], &a[3]);
	dswap(&a[0], &a[2]);
	dswap(&a[1], &a[3]);
	dswap(&a[1], &a[2]);
}

void dswap(char *x, char *y)
{
	char		t;
	
	if (*x < *y) {
		t = *x;
		*x = *y;
		*y = t;
	}
}


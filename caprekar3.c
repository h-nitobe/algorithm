//  Kaprekar's constant 3

#include	<stdio.h>
#include	<stdlib.h>

void caprekar3(char*ar);
int atoi3(char *a);
void itoa3(int n, char *a);
void asort3(char *a);
void dsort3(char *a);
void aswap(char *x, char *y);
void dswap(char *x, char *y);

int main(void)
{
	int 	cnt = 0;
	char	arr[3];
	int		num;

//　3桁マルチセットの組合せ（多重集合）	
//　「同じ3つの数字を使った並びは順序に関係なく1通りと数える」
	for(arr[0] = 0; arr[0] < 10; arr[0]++) {
		for(arr[1] = arr[0]; arr[1] < 10; arr[1]++) {
			for(arr[2] = arr[1]; arr[2] < 10; arr[2]++) {
				caprekar3(arr);
				cnt++;
			}
		}
	}
	printf("-----\n%d\n", cnt);
}

void caprekar3(char *ar)
{
	char	wk[3];
	int		i = 0, j, k, p;
	
	memcpy(wk, ar, 3);
	printf("\033[37m");			// 文字色白
	printf("%03d ", atoi3(wk));

	for (i = 0; i < 6; i++) {
		dsort3(wk);
		j = atoi3(wk);
		asort3(wk);
		k = atoi3(wk);
		p = j - k;
		itoa3(p, wk);
		if (p == 495) {
			printf("\033[32m");	// 文字色緑
		}
		printf("%03d ", p);
	}
	printf("\n");
}

int atoi3(char *a)
{
	return a[0] * 100 + a[1] * 10 + a[2];
}

void itoa3(int n, char *a)
{	int		i;
	
	for (i = 0; i < 3; i++) {
		a[2-i] = n % 10;
		n /= 10;
	}
}

// 完全最小比較ネットワーク 昇順
void asort3(char *a)
{
	aswap(&a[0], &a[1]);
	aswap(&a[0], &a[2]);
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
void dsort3(char *a)
{
	dswap(&a[0], &a[1]);
	dswap(&a[0], &a[2]);
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


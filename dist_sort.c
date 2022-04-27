/**
*	@file		dist_sort.c
*	@brief		distribution cnting sort / 分布数えソート
*	@author		Hiroaki Nitobe／新渡戸広明
*	@date		2022/04/27
*	@details	データを通読してキーの値の度数分布を求め、それを蓄積して順位に変換し、その順位の場所にデータを入れなおす
*/

#include	<stdio.h>

#define	MAX		100
#define	MIN		0
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void print_array(int *pa, int n);
void dist_sort(int *a, int *b, int n);

int main(void)
{	
	int			in[] = { 0, 2, 1, 8, 5, 4, 7, 9, 10, 6, 3 };
	int			out[NUM(in)];
	int			n = NUM(in);

	print_array(in, n);
	
	dist_sort(in, out, n);
	
	print_array(out, n);
	
	return 0;
}

void print_array(int *pa, int n)
{
	int		i;
	
	for (i = 0; i < n; i++) {
		printf ("%d ", *(pa + i));
	}
	puts("");
}

/* 分布数えソート */
void dist_sort(int *a, int *b, int n)
{
	int		i, x;
	static int cnt[MAX - MIN + 1] = { 0 };
	
	for (i = 0; i < n; i++) {
		cnt[a[i] - MIN]++;
	}
	for (i = 1; i <= MAX - MIN; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (i = n - 1; i >= 0; --i) {
		x = a[i] - MIN;
		b[--cnt[x]] = x;
	}
}

/**
*	@file		dist_sort.c
*	@brief		distribution cnting sort / 分布数えソート
*	@author		Hiroaki Nitobe／新渡戸広明
*	@date		2022/04/27
*	@details	データを通読してキーの値の度数分布を求め、それを蓄積して順位に変換し、その順位の場所にデータを入れなおす
*/

#include	<stdio.h>
#include	<time.h>
#include	"my_lib.h"

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void dist_sort(unsigned short *a, unsigned short *b, int n);

static unsigned short data[NUMBER_OF_DATA];
static unsigned short out[NUMBER_OF_DATA];

int main(void)
{	
	create_data(data, NUM(data));

	dist_sort(data, out, NUM(data));
	
	save_array("dist_sort.txt", out, NUM(out));
	check_the_order(out,  NUM(out));
	
	return 0;
}

static int 		cnt[NUMBER_OF_DATA] = { 0 };

/* 分布数えソート */
void dist_sort(unsigned short *a, unsigned short *b, int n)
{
	int				i;
	unsigned short	x;
	clock_t			start;
	
	start = clock();
	printf("Dist sort: ");	
	for (i = 0; i < n; i++) {
		cnt[a[i]]++;
	}
	for (i = 1; i <= NUMBER_OF_DATA; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (i = n - 1; i >= 0; --i) {
		x = a[i];
		b[--cnt[x]] = x;
	}
	printf("%.3lfsec\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}

//cl /Wall dist_sort.c my_lib.c

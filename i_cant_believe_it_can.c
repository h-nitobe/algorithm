/**
*	@file		i_cant_believe_it_can.c
*	@brief		I can't believe can sort. 
*	@author		新渡戸広明
*	@date		2022/04/17
*	@details	I can't believe can sort. 
*				ソートできるなんて信じられない
*				Is this the simplest (and most surprising) sorting algorithm ever?
*				これは、これまでで最もシンプルな（そして最も驚くべき）ソートアルゴリズムなのだろうか？
*				https://arxiv.org/abs/2110.01111
*				https://siv3d.jp/web/sample/itcansort/itcansort.html
*/

#include	<stdio.h>
#include	<time.h>
#include	"my_lib.h"

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void i_cant_believe_it_can(unsigned short *pa, int n);

static unsigned short data[NUMBER_OF_DATA];

int main(void)
{		
	create_data(data, NUM(data));
	
	i_cant_believe_it_can(data, NUM(data));
	
	save_array("i_cant_believe_it_can.txt", data, NUM(data));
	check_the_order(data, NUM(data));
	
	return 0;
}

void i_cant_believe_it_can(unsigned short *pa, int n)
{
	int			i, j;
	clock_t		start;
	
	printf("Shell sort: ");
	start = clock();
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (*(pa + i) < *(pa + j)) {
				swap(pa + i, pa + j);
			}
		}
	}
	printf("%.3lfsec\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}

//cl /Wall  i_cant_believe_it_can.c my_lib.c

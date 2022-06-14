/**
*	@file		bubble_sort.c
*	@brief		バブルソート Bubble sort
*	@author		新渡戸広明 Hiroaki Nitobe
*	@date		2022/06/12
*	@details	
*/

#include	<stdio.h>
#include	<time.h>
#include	"my_lib.h"

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void bubble_sort(unsigned short *pa, int n);

static unsigned short data[NUMBER_OF_DATA];

int main(void)
{	
	create_data(data, NUM(data));
	
	bubble_sort(data, NUM(data));
	
	save_array("bubble_sort.txt", data, NUM(data));
	check_the_order(data,  NUM(data));
	
	return 0;
}

void bubble_sort(unsigned short *pa, int n)
{
	int			i, j;
	clock_t		start;
	
	printf("Bubble sort: ");
	start = clock();
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j >= i + 1; --j) {
			if (*(pa + j) < *(pa + j - 1)) {
				swap(pa + j, pa + j - 1);
			}
		}
	}
	printf("%.3lfsec\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}

//cl /Wall bubble_sort.c my_lib.c

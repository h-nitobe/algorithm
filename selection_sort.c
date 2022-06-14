/**
*	@file		selection_sort.c
*	@brief		選択ソート selection sort
*	@author		新渡戸広明 Hiroaki Nitobe
*	@date		2022/06/12
*	@details	
*/

#include	<stdio.h>
#include	<time.h>
#include	"my_lib.h"

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void selection_sort(unsigned short *pa, int n);

static unsigned short data[NUMBER_OF_DATA];

int main(void)
{
	create_data(data, NUM(data));
	
	selection_sort(data, NUM(data));
	
	save_array("selection_sort.txt", data, NUM(data));
	check_the_order(data, NUM(data));
	
	return 0;
}

void selection_sort(unsigned short *pa, int n)
{
	int			i, j, m;
	clock_t		start;
	
	printf("Selection sort: ");
	start = clock();
	for (i = 0; i < n - 1; i++) {
		m = i;
		for (j = i + 1; j < n; j++) {
			if (*(pa + j) < *(pa + m)) {
				m = j;
			}
		}
		if (i != m) {
			swap(pa + m, pa + i);
		}
	}
		printf("%.3lfsec\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}

//cl /Wall selection_sort.c my_lib.c

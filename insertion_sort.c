/**
*	@file		insertion_sort.c
*	@brief		ë}ì¸É\Å[Ég Insertion sort
*	@author		êVìnåÀçLñæ Hiroaki Nitobe
*	@date		2022/06/12
*	@details	
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#include	"my_lib.h"

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void insertion_sort(unsigned short a[], int n);

static unsigned short data[NUMBER_OF_DATA];

int main(void)
{		
	create_data(data, NUM(data));

	insertion_sort(data, NUM(data));
	
	save_array("insertion_sort.txt", data, NUM(data));
	check_the_order(data, NUM(data));
	
	return 0;
}

void insertion_sort(unsigned short *pa, int n)
{
	int		i, j;
	clock_t	start = clock();
	
	printf("Selection sort: ");	
	for (i = 1; i < n; i++) {
		j = i;
		while ((j > 0) && *(pa + j -1) > *(pa + j)) {
			swap(pa + j - 1, pa + j);
			--j;
		}
	}
	printf("%.3lfsec\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}


//cl /Wall insertion_sort.c my_lib.c

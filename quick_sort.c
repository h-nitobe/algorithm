/**
*	@file		quick_sort.c
*	@brief		クイックソート Quick_sort
*	@author		新渡戸広明 Hiroaki Nitobe
*	@date		2022/06/12
*	@details	
*/

#include	<stdio.h>
#include	<time.h>
#include	"my_lib.h"

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void quick_sort(unsigned short *pa, int i, int j);

static unsigned short data[NUMBER_OF_DATA];

int main(void)
{		
	create_data(data, NUM(data));
	
	printf("Selection sort: ");	
	quick_sort(data, 0, NUM(data) - 1);
	printf("%d\n", clock());
	
	save_array("quick_sort.txt", data, NUM(data));
	check_the_order(data,  NUM(data));
	
	return 0;
}

void quick_sort(unsigned short *pa, int left, int right)
{
	int		i, j;
	int		pivot;
	
	if (left >= right) return;
	
	i = left;
	j = right;
	pivot = *(pa + i);
	
	for ( ;; ) {
		while (*(pa + i) < pivot) i++;
		while (*(pa + j) > pivot) --j;
		if (i >= j) break;
		swap(pa+ i, pa + j);
		i++;
		--j;
	}
	
	quick_sort(pa, left, i - 1);
	quick_sort(pa, j + 1, right);
}

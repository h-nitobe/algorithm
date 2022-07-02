/**
*	@file		test_qsort.c
*	@brief		標準ライブラリの qsort を使う
*	@author		新渡戸広明 Hiroaki Nitobe
*	@date		2022/07/03
*	@details	
*/

#include	<stdio.h>
#include	<stdlib.h>	// for qsort()
#include	<stdint.h>
#include	<time.h>
#include	"my_lib.h"

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void test_qsort(unsigned short *pa, int i);

int cmpNum(const void *a, const void *b)

int main(void)
{
	clock_t		start;
	
	create_data(data, NUM(data));
	
	printf("qsort: ");
	start = clock();
	quick_sort(data, 0, NUM(data) - 1);
	printf("%.3lfsec\n", (double)(clock() - start) / CLOCKS_PER_SEC);
	
	save_array("quick_sort.txt", data, NUM(data));
	check_the_order(data,  NUM(data));
	
	return 0;
}

int cmpNum(const void *a, const void *b)
{
	if(*(unsigned short *)a > *(unsigned short *)b) return 1;
	
}

//cl /Wall quick_sort.c my_lib.c

/**
*	@file		test_qsort.c
*	@brief		標準ライブラリの qsort を使う
*	@author		新渡戸広明 Hiroaki Nitobe
*	@date		2022/07/03
*	@details	
*/

#include	<stdio.h>
#include	<stdlib.h>	// for qsort()
#include	<time.h>
#include	"my_lib.h"

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))


static unsigned short data[NUMBER_OF_DATA];

int cmpNum(const void *a, const void *b);

int main(void)
{
	clock_t		start;
	
	create_data(data, NUM(data));
	
	printf("qsort: ");
	start = clock();
	qsort(data, NUM(data), sizeof(unsigned short), cmpNum);
	printf("%.3lfsec\n", (double)(clock() - start) / CLOCKS_PER_SEC);
	
	save_array("qsort.txt", data, NUM(data));
	check_the_order(data,  NUM(data));
	
	return 0;
}

int cmpNum(const void *a, const void *b)
{
	int		ret;
	
	if(*(unsigned short *)a > *(unsigned short *)b) {
		ret = 1;
	} else if(*(unsigned short *)a < *(unsigned short *)b) {
		ret = -1;
	} else {
		ret = 0;
	}
	
	return ret;
}

//cl /Wall test_sort.c my_lib.c

/**
*	@file		my_lib.c
*	@brief		
*	@author		Hiroaki Nitobe
*	@date		2018/10/13
*	@details	
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"my_lib.h"

void create_data(unsigned short *pa, int n)
{
	int		i;
	
	printf("Create data: ");
	srand(0);
	for (i = 0; i < n; i++) {
		*(pa + i) = (unsigned short)rand();
	}
	printf("%d\n", i);
}

void check_the_order(unsigned short *pa, int n)
{
	int		i;
	
	printf("Check the order: ");
	for (i = 1; i < n; i++) {
		if (*(pa + i) < *(pa + i - 1)) break;
	}
	printf(i == n ? "OK\n" : "NG\n");
}


void swap(unsigned short *x, unsigned short *y)
{
	if (x != y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}

void save_array(char *fn, unsigned short *pa, int n)
{
	FILE	*fp;
	int		i;
	char	buff[16];
	
	printf("Save %s: ", fn);
	fp = fopen(fn, "w");
	
	for (i = 0; i < n; i++) {
		sprintf(buff, "%d\n", *(pa+i));
		fputs(buff, fp);
	}
	printf("%d\n", i);
	
	fclose(fp);
}


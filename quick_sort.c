/**
*	@file		quick_sort.c
*	@brief		クイックソート Quick_sort
*	@author		新渡戸広明 Hiroaki Nitobe
*	@date		2022/06/12
*	@details	
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void create_data(unsigned short *pa, int n);
void check_the_order(unsigned short *pa, int n);
void quick_sort(unsigned short *pa, int i, int j);
void swap(unsigned short *x, unsigned short *y);
void save_array(unsigned short *pa, int n);

static unsigned short data[NUMBER_OF_DATA];

int main(void)
{		
	srand(0);
	
	create_data(data, NUM(data));
	
	printf("Selection sort: ");	
	quick_sort(data, 0, NUM(data) - 1);
	printf("%d\n", clock());
	
	save_array(data, NUM(data));
	check_the_order(data,  NUM(data));
	
	return 0;
}

void create_data(unsigned short *pa, int n)
{
	int		i;
	
	printf("Create data: ");
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

void swap(unsigned short *x, unsigned short *y)
{
	if (x != y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}

void save_array(unsigned short *pa, int n)
{
	FILE	*fp;
	int		i;
	char	buff[16];
	
	fp = fopen("quick_sort.txt", "w");
	
	for (i = 0; i < n; i++) {
		sprintf(buff, "%d\n", *(pa+i));
		fputs(buff, fp);
	}
	
	fclose(fp);
}

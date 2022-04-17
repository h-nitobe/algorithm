/**
*	@file		insertion_sort.c
*	@brief		‘}“üƒ\[ƒg
*	@author		V“nŒËL–¾
*	@date		2022/04/17
*	@details	
*/

#include	<stdio.h>

#define NUM(a) (sizeof(a)/sizeof(a[0]))

void print_array(int *pa, int n);
void insertion_sort(int a[], int n);
void swap(int *x, int *y);

int main(void)
{	
	int data[] = { 3, 1, 6, 7, 4, 2 };
	
	print_array(data, NUM(data));
	
	insertion_sort(data, NUM(data));
	
	print_array(data,  NUM(data));
	
	return 0;
}

void print_array(int *pa, int n)
{
	int		i;
	
	for (i = 0; i < n; i++) {
		printf ("%d ", *(pa + i));
	}
	puts("");
}

void insertion_sort(int *pa, int n)
{
	int		i, j;
	
	for (i = 1; i < n; i++) {
		j = i;
		while ((j > 0) && *(pa + j -1) > *(pa + j)) {
			swap(pa + j - 1, pa + j);
			--j;
		}
	}
}

void swap(int *x, int *y)
{
	if (x != y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}


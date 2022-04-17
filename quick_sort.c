/**
*	@file		quick_sort.c
*	@brief		クイックソート
*	@author		新渡戸広明
*	@date		2022/04/17
*	@details	
*/

#include	<stdio.h>

#define NUM(a) (sizeof(a)/sizeof(a[0]))

void print_array(int *pa, int n);
void quick_sort(int *pa, int i, int j);
void swap(int *x, int *y);

int main(void)
{	
	int data[] = { 3, 1, 6, 7, 4, 2 };
	
	print_array(data, NUM(data));
	
	quick_sort(data, 0, NUM(data) - 1);
	
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

void quick_sort(int *pa, int left, int right)
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

void swap(int *x, int *y)
{
	if (x != y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}


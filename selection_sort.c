/**
*	@file		selection_sort.c
*	@brief		選択ソート
*	@author		新渡戸広明
*	@date		2022/04/17
*	@details	
*/

#include	<stdio.h>

#define NUM(a) (sizeof(a)/sizeof(a[0]))

void print_array(int *pa, int n);
void selection_sort(int a[], int n);
void swap(int *x, int *y);

int main(void)
{	
	int data[] = { 3, 1, 6, 7, 4, 2 };
	
	print_array(data, NUM(data));
	
	selection_sort(data, NUM(data));
	
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

void selection_sort(int *pa, int n)
{
	int		i, j, m;
	
	for (i = 0; i < n - 1; i++) {
		m = i;
		for (j = i + 1; j < n; j++) {
			if (*(pa + j) < *(pa + m)) {
				m = j;
			}
		}
		swap(pa + m, pa + i);
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


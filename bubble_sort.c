/**
*	@file		bubble_sort.c
*	@brief		バブルソート
*	@author		新渡戸広明
*	@date		2022/04/17
*	@details	
*/

#include	<stdio.h>

#define NUM(a) (sizeof(a)/sizeof(a[0]))

void print_array(int *pa, int n);
void bubble_sort(int a[], int n);
void swap(int *x, int *y);

int main(void)
{	
	int data[] = { 0, 2, 1, 8, 5, 4, 7, 9, 10, 6, 3 };
	
	print_array(data, NUM(data));
	
	bubble_sort(data, NUM(data));
	
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

void bubble_sort(int *pa, int n)
{
	int		i, j;
	
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j >= i + 1; --j) {
			if (*(pa + j) < *(pa + j - 1)) {
				swap(pa + j, pa + j - 1);
			}
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


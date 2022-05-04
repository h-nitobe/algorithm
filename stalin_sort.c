/**
*	@file		stalin_sort.c
*	@brief		スターリンソート
*	@author		Hiroaki Nitobe／新渡戸　広明
*	@date		2022/04/23
*	@details	条件に合わない数値を粛清します。
*				噂のスターリンソートをPythonで実装してみた @sakairi
*				https://qiita.com/sakairi/items/16838883d667fe117ab5
*/

#include	<stdio.h>

#define NUM(a) (sizeof(a)/sizeof(a[0]))

void print_array(int *pa, int n);
int stalin_sort(int *a, int n);

int main(void)
{	
	int data[] = { 0, 2, 1, 8, 5, 4, 7, 9, 10, 6, 3 };
//	int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int data[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int data[] = { 0, 2, 1, 4, 3, 6, 5, 8, 7, 10, 9 };
//	int data[] = { 1, 2, 1, 1, 4, 3, 9 };
	
	int n = NUM(data);
		
	print_array(data, n);
	
	n = stalin_sort(data, n);
	
	print_array(data, n);
	
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

/* スターリンソート */
int stalin_sort(int *a, int n)
{
	int	i, t, m = 1;
	
	t = *a;
	
	for (i = 1; i < n; i++) {
		if (t < *(a + i)) {
			t = *(a + m) = *(a + i);
			m++;
		}
	}

	return m;
}

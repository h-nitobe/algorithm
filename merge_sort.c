/**
*	@file		merge_sort.c
*	@brief		マージソート Merge_sort
*	@author		@omu58n
*	@date		2018/10/22
*	@details	分割統治法に基づくアルゴリズム
*				https://qiita.com/omu58n/items/2aa3c751cfb10cdbbb43
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void create_data(unsigned short *pa, int n);
void check_the_order(unsigned short *pa, int n);
void merge_sort (unsigned short array[], int left, int right);
void swap(unsigned short *x, unsigned short *y);

static unsigned short data[NUMBER_OF_DATA];

int main(void)
{	
	create_data(data, NUM(data));

	printf("Merge sort: ");	
	merge_sort(data, 0, NUM(data) - 1);
	printf("%d\n", clock());	
	
	check_the_order(data, NUM(data));
	
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

/* マージソート */
void merge_sort (unsigned short array[], int left, int right)
{
	int		i, j, k, mid;
	static unsigned short work[NUMBER_OF_DATA];	// 作業用配列 注意！
	
	if (left < right) {
		mid = (left + right) / 2;			// 真ん中
		merge_sort(array, left, mid);		// 左を整列
		merge_sort(array, mid + 1, right);	// 右を整列
		for (i = mid; i >= left; --i) {		// 左半分
			work[i] = array[i];
		}
		for (j = mid + 1; j <= right; j++) {		// 右半分を逆順
			work[right-(j-(mid + 1))] = array[j]; 
		}
		i = left;
		j = right;
		for (k = left; k <= right; k++) {
			if (work[i] < work[j]) {
				array[k] = work[i++];
			} else {
				array[k] = work[j--];
			}
			
		}
	}
}

void swap(unsigned short *x, unsigned short *y)
{
	if (x != y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}


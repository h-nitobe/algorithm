/**
*	@file		merge_sort.c
*	@brief		マージソート
*	@author		@omu58n
*	@date		2018/10/22
*	@details	分割統治法に基づくアルゴリズム
*				https://qiita.com/omu58n/items/2aa3c751cfb10cdbbb43
*/

#include	<stdio.h>

#define NUM(a) (sizeof(a)/sizeof(a[0]))

void print_array(int *pa, int n);
void merge_sort (int array[], int left, int right);
void swap(int *x, int *y);

int main(void)
{	
	int data[] = { 0, 2, 1, 8, 5, 4, 7, 9, 10, 6, 3 };
	
	print_array(data, NUM(data));
	
	merge_sort(data, 0, NUM(data) - 1);
	
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

/* マージソート */
void merge_sort (int array[], int left, int right)
{
	int		i, j, k, mid;
	int		work[11];	 					// 作業用配列 注意！
	
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

void swap(int *x, int *y)
{
	if (x != y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}


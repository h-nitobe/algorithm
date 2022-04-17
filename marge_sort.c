/**
*	@file		merge_sort.c
*	@brief		�}�[�W�\�[�g
*	@author		@omu58n
*	@date		2018/10/22
*	@details	���������@�Ɋ�Â��A���S���Y��
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

/* �}�[�W�\�[�g */
void merge_sort (int array[], int left, int right)
{
	int		i, j, k, mid;
	int		work[11];	 					// ��Ɨp�z�� ���ӁI
	
	if (left < right) {
		mid = (left + right) / 2;			// �^��
		merge_sort(array, left, mid);		// ���𐮗�
		merge_sort(array, mid + 1, right);	// �E�𐮗�
		for (i = mid; i >= left; --i) {		// ������
			work[i] = array[i];
		}
		for (j = mid + 1; j <= right; j++) {		// �E�������t��
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


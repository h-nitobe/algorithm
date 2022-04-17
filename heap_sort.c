/**
*	@file		heap_sort.c
*	@brief		�q�[�v�\�[�g
*	@author		�V�n�ˍL��
*	@date		2022/04/17
*	@details	https://qiita.com/omu58n/items/5c7cc358b1463c0a4710
*/

#include	<stdio.h>

#define NUM(a) (sizeof(a)/sizeof(a[0]))

void print_array(int *pa, int n);
void heap_sort (int array[], int array_size);
void pushdown (int array[], int first, int last);
void swap(int *x, int *y);

int main(void)
{	
	int data[] =  { 0, 2, 1, 8, 5, 4, 7, 9, 10, 6, 3 };
	
	print_array(data, NUM(data));
	
	heap_sort(data, NUM(data));
	
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

/* �q�[�v�\�[�g */
void heap_sort(int array[], int array_size)
{
	int i;

	for (i = array_size / 2; i >= 1; i--) {
		pushdown(array, i, array_size);	// �S�̂��q�[�v��
	}
	for (i = array_size; i >= 2; i--) {
		swap(&array[1], &array[i]);		// �ő�̂��̂��Ō��
		pushdown(array, 1, i - 1);		// �q�[�v�č\�z
	}
}

/* pushdouwn���� */
void pushdown(int array[], int first, int last)
{
	int parent = first;			// �e
	int child = 2 * parent;		// ���̎q

	while (child <= last) {
		if ((child < last) && (array[child] < array[child+1])) {
			child++;			// �E�̎q�̕����傫���Ƃ��A�E�̎q���r�Ώۂɐݒ�
		}
		if (array[child] <= array[parent]) {
			break;				// �q�[�v�ς�
		}
		swap(&array[child], &array[parent]);
		parent = child;
		child = 2 * parent;
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


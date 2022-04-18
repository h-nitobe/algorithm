/**
*	@file		stalin_sort.c
*	@brief		�X�^�[�����\�[�g
*	@author		Hiroaki Nitobe�^�V�n�ˁ@�L��
*	@date		2022/04/19
*	@details	
*/

#include	<stdio.h>

void print_array(int *pa, int n);
void shell_sort (int array[], int array_size);
void swap(int *x, int *y);

int main(void)
{	
	
	print_array(data, NUM(data));
	
	stalin_sort(data, NUM(data));
	
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

/* �X�^�[�����\�[�g */
void stalin_sort (struct *data)
{
}

void swap(int *x, int *y)
{
	if (x != y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}


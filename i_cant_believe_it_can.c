/**
*	@file		i_cant_believe_it_can.c
*	@brief		I cant't believe can sort. 
*	@author		�V�n�ˍL��
*	@date		2022/04/17
*	@details	�\�[�g�ł���Ȃ�ĐM�����Ȃ�
*				����́A����܂łōł��V���v���ȁi�����čł������ׂ��j�\�[�g�A���S���Y���Ȃ̂��낤���H
*				https://arxiv.org/abs/2110.01111
*				https://siv3d.jp/web/sample/itcansort/itcansort.html
*/

#include	<stdio.h>

#define NUM(a) (sizeof(a)/sizeof(a[0]))

void print_array(int *pa, int n);
void i_cant_believe_it_can(int *pa, int n);
void swap(int *x, int *y);

int main(void)
{	
	int data[] = { 0, 2, 1, 8, 5, 4, 7, 9, 10, 6, 3 };
	
	print_array(data, NUM(data));
	
	i_cant_believe_it_can(data, NUM(data));
	
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

void i_cant_believe_it_can(int *pa, int n)
{
	int		i, j;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (*(pa + i) < *(pa + j)) {
				swap(pa + i, pa + j);
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

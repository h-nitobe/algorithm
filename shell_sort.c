/**
*	@file		shell_sort.c
*	@brief		�V�F���\�[�g
*	@author		@omu58n
*	@date		2018/10/09
*	@details	�}���\�[�g�̉��ǔŁB�}���\�[�g�����x���J��Ԃ����Ƃō������������B
*				https://qiita.com/omu58n/items/bb9b4a88ec4351b11727
*/

#include	<stdio.h>

#define NUM(a) (sizeof(a)/sizeof(a[0]))

void print_array(int *pa, int n);
void shell_sort (int array[], int array_size);
void swap(int *x, int *y);

int main(void)
{	
	int data[] = { 0, 2, 1, 8, 5, 4, 7, 9, 10, 6, 3 };
	
	print_array(data, NUM(data));
	
	shell_sort(data, NUM(data));
	
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

/* �V�F���\�[�g */
void shell_sort (int array[], int array_size)
{
  int i, j, h;

  for (h = 1; h <= array_size/9; h = 3*h + 1);   // �Ԋuh�����߂�
  for ( ; h > 0; h /= 3) {   // h�����߂Ă���
    /* �ȉ��A�}���\�[�g�Ƃقړ��� */
    for (i = h; i < array_size; i++) {
      j = i;
      while ((j > h - 1) && (array[j-h] > array[j])) {
        swap(&array[j-h], &array[j]);
        j -= h;
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


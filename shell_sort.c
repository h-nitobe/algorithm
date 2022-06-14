/**
*	@file		shell_sort.c
*	@brief		�V�F���\�[�g Shell_sort
*	@author		@omu58n
*	@date		2018/10/09
*	@details	�}���\�[�g�̉��ǔŁB�}���\�[�g�����x���J��Ԃ����Ƃō������������B
*				https://qiita.com/omu58n/items/bb9b4a88ec4351b11727
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#include	"my_lib.h"

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void shell_sort (unsigned short array[], int array_size);

static unsigned short data[NUMBER_OF_DATA];

int main(void)
{	
c	
	shell_sort(data, NUM(data));
	
	save_array("shell_sort.txt", data, NUM(data));
	check_the_order(data, NUM(data));
	
	return 0;
}


/* �V�F���\�[�g */
void shell_sort (unsigned short array[], int array_size)
{
  int			i, j, h;
  clock_t		start;

  printf("Shell sort: ");
  start = clock();
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
  printf("%.3lfsec\n", (double)(clock() - start) / CLOCKS_PER_SEC);

}

//cl /Wall shell_sort.c my_lib.c

/**
*	@file		shell_sort.c
*	@brief		シェルソート Shell_sort
*	@author		@omu58n
*	@date		2018/10/09
*	@details	挿入ソートの改良版。挿入ソートを何度か繰り返すことで高速化を実現。
*				https://qiita.com/omu58n/items/bb9b4a88ec4351b11727
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void create_data(unsigned short *pa, int n);
void check_the_order(unsigned short *pa, int n);
void shell_sort (unsigned short array[], int array_size);
void swap(unsigned short *x, unsigned short *y);
void save_array(unsigned short *pa, int n);

static unsigned short data[NUMBER_OF_DATA];

int main(void)
{	
	srand(0);
	
	create_data(data, NUM(data));
	
	shell_sort(data, NUM(data));
	
	save_array(data, NUM(data));
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

/* シェルソート */
void shell_sort (unsigned short array[], int array_size)
{
  int i, j, h;

  printf("Shell sort: ");
  for (h = 1; h <= array_size/9; h = 3*h + 1);   // 間隔hを決める
  for ( ; h > 0; h /= 3) {   // hを狭めていく
    /* 以下、挿入ソートとほぼ同じ */
    for (i = h; i < array_size; i++) {
      j = i;
      while ((j > h - 1) && (array[j-h] > array[j])) {
        swap(&array[j-h], &array[j]);
        j -= h;
      }
    }
  }
  printf("%d\n", clock());

}

void swap(unsigned short *x, unsigned short *y)
{
	if (x != y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}

void save_array(unsigned short *pa, int n)
{
	FILE	*fp;
	int		i;
	char	buff[16];
	
	fp = fopen("shell_sort.txt", "w");
	
	for (i = 0; i < n; i++) {
		sprintf(buff, "%d\n", *(pa+i));
		fputs(buff, fp);
	}
	
	fclose(fp);
}



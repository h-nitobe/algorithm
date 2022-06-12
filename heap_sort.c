/**
*	@file		heap_sort.c
*	@brief		ヒープソート Heap_sort
*	@author		@omu58n
*	@date		2018/10/14
*	@details	https://qiita.com/omu58n/items/5c7cc358b1463c0a4710
*				何処かにバグがあります。探してください。
*				There is a bug somewhere. please look for it.
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void create_data(unsigned short *pa, int n);
void check_the_order(unsigned short *pa, int n);
void heap_sort (unsigned short array[], int array_size);
void pushdown (unsigned short array[], int first, int last);
void swap(unsigned short *x, unsigned short *y);
void save_array(unsigned short *pa, int n);

static unsigned short data[NUMBER_OF_DATA];

int main(void)
{	
	srand(0);

	create_data(data, NUM(data));
	
	heap_sort(data, NUM(data));
	
	save_array(data,  NUM(data));
	check_the_order(data,  NUM(data));
	
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

/* ヒープソート */
void heap_sort(unsigned short array[], int array_size)
{
	int i;

	printf("Heap sort: ");	
	for (i = array_size / 2; i >= 1; i--) {
		pushdown(array, i, array_size);	// 全体をヒープ化
	}
	for (i = array_size; i >= 2; i--) {
		swap(&array[1], &array[i]);		// 最大のものを最後に
		pushdown(array, 1, i - 1);		// ヒープ再構築
	}
	printf("%d\n", clock());
}

/* pushdouwn操作 */
void pushdown(unsigned short array[], int first, int last)
{
	int parent = first;			// 親
	int child = 2 * parent;		// 左の子

	while (child <= last) {
		if ((child < last) && (array[child] < array[child+1])) {
			child++;			// 右の子の方が大きいとき、右の子を比較対象に設定
		}
		if (array[child] <= array[parent]) {
			break;				// ヒープ済み
		}
		swap(&array[child], &array[parent]);
		parent = child;
		child = 2 * parent;
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

void save_array(unsigned short *pa, int n)
{
	FILE	*fp;
	int		i;
	char	buff[16];
	
	fp = fopen("heap_sort.txt", "w");
	
	for (i = 0; i < n; i++) {
		sprintf(buff, "%d\n", *(pa+i));
		fputs(buff, fp);
	}
	
	fclose(fp);
}


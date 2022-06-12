/**
*	@file		selection_sort.c
*	@brief		�I���\�[�g selection sort
*	@author		�V�n�ˍL�� Hiroaki Nitobe
*	@date		2022/06/12
*	@details	
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void create_data(unsigned short *pa, int n);
void check_the_order(unsigned short *pa, int n);
void selection_sort(unsigned short *pa, int n);
void swap(unsigned short *x, unsigned short *y);
void save_array(unsigned short *pa, int n);

static unsigned short data[NUMBER_OF_DATA];

int main(void)
{
	srand(0);
	
	create_data(data, NUM(data));
	
	selection_sort(data, NUM(data));
	
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

void selection_sort(unsigned short *pa, int n)
{
	int		i, j, m;
	
	printf("Selection sort: ");	
	for (i = 0; i < n - 1; i++) {
		m = i;
		for (j = i + 1; j < n; j++) {
			if (*(pa + j) < *(pa + m)) {
				m = j;
			}
		}
		if (i != m) {
			swap(pa + m, pa + i);
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
	
	fp = fopen("selection_sort.txt", "w");
	
	for (i = 0; i < n; i++) {
		sprintf(buff, "%d\n", *(pa+i));
		fputs(buff, fp);
	}
	
	fclose(fp);
}

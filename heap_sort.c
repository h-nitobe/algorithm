/**
*	@file		heap_sort.c
*	@brief		�q�[�v�\�[�g Heap_sort
*	@author		@omu58n
*	@date		2018/10/14
*	@details	https://qiita.com/omu58n/items/5c7cc358b1463c0a4710
*				�������Ƀo�O������܂��B�T���Ă��������B
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

/* �q�[�v�\�[�g */
void heap_sort(unsigned short array[], int array_size)
{
	int i;

	printf("Heap sort: ");	
	for (i = array_size / 2; i >= 1; i--) {
		pushdown(array, i, array_size);	// �S�̂��q�[�v��
	}
	for (i = array_size; i >= 2; i--) {
		swap(&array[1], &array[i]);		// �ő�̂��̂��Ō��
		pushdown(array, 1, i - 1);		// �q�[�v�č\�z
	}
	printf("%d\n", clock());
}

/* pushdouwn���� */
void pushdown(unsigned short array[], int first, int last)
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


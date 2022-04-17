/**
*	@file		sleep_sort.c
*	@brief		スリープソート＊linux上のgccでビルド可能です。
*	@author		@Risebbit
*	@date		2020/05/31
*	@details	C言語 POSIX ThreadでSleep Sort
*				https://qiita.com/Risebbit/items/36a6391b35865891bc07
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM(a) (sizeof(a)/sizeof(a[0]))

void print_array(int *pa, int n);
void *sleep_sort(void *t);

int main(void){
	int			i;
    int 		arr[] = { 2, 1, 8, 5, 4, 7, 9, 10, 6, 3 };
	pthread_t	tid[NUM(arr)];

	print_array(arr, NUM(arr));
	
    for (i = 0; i < NUM(arr); i++) {
        if(pthread_create(&tid[i], NULL, sleep_sort, &arr[i])){
            fprintf(stderr, "error: pthread_create\n");
            exit(1);
        }
    }
    for (i = 0; i < NUM(arr); i++) {
        if (pthread_join(tid[i], NULL)){
            fprintf(stderr, "error: pthread_join\n");
            exit(1);
        }
    }
	
	puts("");
	
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

void *sleep_sort(void *t)
{
    int n = *(int *)t;
    sleep(n);
    printf("%d ", n);
    pthread_exit(NULL);
}


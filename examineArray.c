/**
*	@file		examineArray.c
*	@brief		新渡戸ダークサイド版
*	@author		新渡戸広明
*	@date		2022/05/02
*	@details	
*/
#include	<stdio.h>
#include	"getFunc.h"

int getOddMax(int *ary, int size)
{
	int		i, max = ERR;
	
	if (ary != NULL && 0 <= size) {
		for (i = 0; i < size; i++) {
			if (ary[i] & 1) {
				if (max < ary[i]) {
					max = ary[i];
				}
			}
		}
	}
	
	return max;
}

int getSecondMin(int *ary, int size)
{
	int		i, min1 = NUM_MAX, min2 = NUM_MAX;
	
	if (ary != NULL && 0 <= size) {
		
		for (i = 0; i < size; i++) {
			if (ary[i] < min1) {
				min2 = min1;
				min1 = ary[i];
			} else if (min1 < ary[i] && ary[i] < min2) {
				min2 = ary[i];
			}
			
		}
	}
	
	return min2;
}

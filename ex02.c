/**
*	@file		ex02.c
*	@brief		main()　新渡戸ダークサイド版
*	@author		新渡戸広明
*	@date		2022/05/02
*	@details	
*/

#include	<stdio.h>
#include	"getFunc.h"
#include	"examineArray.h"

#define		SIZE		10								// (1)

int main(void)
{
	int		num[SIZE];
	int 	i, oddMax = ERR, secMin = NUM_MAX;
	
	printf("＊＊総合演習２開始＊＊\n\n");
	
	printf("%dから%dまでの数値を%d回入力してください\n", NUM_MIN, NUM_MAX, SIZE);
	
		for (i = 0; i < SIZE; i++) {					// (2)
		num[i] = getNumber("input => ", NUM_MIN, NUM_MAX);
		if (num[i] == ERR) {
			return ERR;
		}
			if (num[i] == CR) {							// (2)
			break;
		}
	}

	oddMax = getOddMax(num, i);							// (3)
	printf("\n奇数で一番大きな数値：");
	printf(oddMax != ERR ? "%d\n" : "なし\n", oddMax);	// (5)
	
	secMin = getSecondMin(num, i);						// (4)
	printf("小さい方から2番目の数値：");
	printf(secMin != NUM_MAX ? "%d\n" : "なし\n", secMin);	// (5)

	printf("\n＊＊総合演習２終了＊＊");
		
	return 0;
}

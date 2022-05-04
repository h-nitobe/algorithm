/**
*	@file		ex01.c
*	@brief		main()　新渡戸ダークサイド版
*	@author		新渡戸広明
*	@date		2022/05/02
*	@details	
*/

#include <stdio.h>
#include "getFunc.h"

#define BUFFER_SIZE	(100)						// (3) 文字列バッファのサイズ
#define	LINE	"--------------------"

int main(void)
{
	char	buff[BUFFER_SIZE];
	int 	i = 0, line = 0;
	
	printf("＊＊総合演習１開始＊＊\n\n");
	
	/* 文字列の入力 */
	printf("文字を入力してください（%d文字以内）\n", BUFFER_SIZE - 2);	// (1)
	
	/* getString()によるデータ入力 */
	if (getString("input => ", buff, BUFFER_SIZE)) {
		return ERR;
	}
	
	printf(LINE);
	while (buff[i] != '\0') {
			if (!(i % 10)) {											// (2)
			printf("\n分割(%2d)：", ++line);
		}
		printf("%c", buff[i++]);
	}
	
	printf("\n" LINE);
	printf("\n%d文字表示しました\n\n", i);	
	printf("＊＊総合演習１終了＊＊");
		
		
	return 0;
}

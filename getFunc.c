/**
*	@file		getFunc.c
*	@brief		getString(),getNumber　新渡戸ダークサイド版
*	@author		新渡戸広明
*	@date		2022/05/02
*	@details	
*/

//	getString
//
//	#	idx	strlen
//		         97  98  99  99
//
//		  1   0   A   A   A   A
//		  2   1   B   B   B   B
//		  3   2   C   C   C   C
//		  .
//		  .
//		  .
//		 95  94   U   U   U   U
//		 96  95   V   V   V   V
//		 97  96   W   W   W   W
//		 98  97 *\n*  X   X   X
//		 99  98  \0 *\n*  Y   Y
//		100  99   ?  \0  \0  \0
//
//  Stream    ?   ?   ?  \n   Z
//            ?   ?   ?      \n
//

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<ctype.h>
#include	"getFunc.h"

int getString(char *pro, char *buf, int size)
{
	char 	*p;
	int		ret = LOOP;
	
	do {
		printf(pro ? pro : "=>");						// (1)
		
		if (fgets(buf, size, stdin) != NULL) {			// (2)
			if ((p = strchr(buf, '\n')) != NULL) {		// 入力過多でなければ	
					*p = '\0';							// (5)
					ret = OK;							// (4)
			} else {									// (3) 入力過多
				printf("<%d文字以内で入力してください>\n", size - 2);
				while (getchar() != '\n') ;				// ストリームバッファクリア
				ret = LOOP;
			}
		} else { 
			ret = ERR;
		}
	} while (ret == LOOP);

	return ret;
}

int getNumber(char *pro, int min, int max)
{
	char	buf[DIG_MAX];
	int		num, ret = LOOP;

	if ((max <= min) || (min < MIN) || (MAX < max)) {
		return ERR;
	}

	do {
		printf(pro ? pro : "=>");						// (1)

		if (fgets(buf, DIG_MAX, stdin) != NULL) {		// (2)
			if (strchr(buf, '\n') != NULL) {			// 入力過多でなければ	
				if (isdigit(buf[0])) {
					num = atoi(buf);
					if (min <= num && num <= max) {		// (4)
						ret = num;	
					} else {							// (3)
						printf("＜%d～%dの範囲で入力してください＞\n", min, max);
						ret = LOOP;
					}
				} else if (buf[0] == '\n') {
					ret = CR;
				} else {								// (3)
					printf("＜'0'～'9'以外の文字を入力しないでください＞\n");
					ret = LOOP;
				}
			} else {									// 入力過多
				while (getchar() != '\n') ;				// ストリームバッファクリア
				printf("＜%d文字以下の数値を入力してください＞\n", DIG_MAX - 2);
//				ret = LOOP;								// 自明
			}
		} else {
			ret = ERR;
		}
	} while (ret == LOOP);
	
	return ret;
}

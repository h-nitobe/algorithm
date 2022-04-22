/**
*	@file		ex3_003.c
*	@brief		大文字小文字変換（別解）
*	@author		Hiroaki Nitobe / 新渡戸広明
*	@date		2022/04/24
*	@details	入力した文字列を、英字の大文字と小文字を変換して表示するプログラムを作成してください。
*				・英字以外はそのまま出力してください。
*				・ASCII文字セットを使用することが前提のプログラムでかまいません。
*				出力イメージ
*				C:\Vc7\algorithm>ex3_003
*				文字（９９文字まで）を入力してください
*				＝＞ QWERTYUIOPasdfghjkl123456789!"#$%&'()
*				＞＞ qwertyuiopASDFGHJKL123456789!"#$%&'()
*/

#include <stdio.h>		// for printf(), scanf()
#include <string.h>		// for strlen()
#include <ctype.h>		// for islower(), isupper(), tolower(), toupper()

int main(void)
{
	char	str[100];
	int		len, i;
	
	printf("文字（９９文字まで）を入力してください\n＝＞ ");
	scanf("%s", str);
	
	len = strlen(str);
	
	for (i = 0; i <len; i++) {
		if (isupper(str[i])) {				// 大文字だったら
			str[i] = (char)tolower(str[i]);	// 小文字にする
		} else if (islower(str[i])) {		// 小文字だったら
			str[i] = (char)toupper(str[i]);	// 大文字にする
		}
	}

	printf("＞＞ %s\n", str);

	return 0;
}

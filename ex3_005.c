/**
*	@file		ex3_005.c
*	@brief		フィボナッチ数列（別解）
*	@author		Hiroaki Nitobe / 新渡戸広明
*	@date		2022/04/24
*	@details	正の整数値を入力し、その数値までのフィボナッチ数列を表示するプログラムを作成してください。
*				・最初の２項は０と１で、以後はその直前の２つの項の和となっています。
*				0 1 1 2 3 5 8 13 21 34 55 89 144 ・・・＞と続きます。
*				出力イメージ
*				C:\Vc7\algorithm>ex3_005
*				数値を入力してください＝＞ 1000
*				0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987,
*/

#include <stdio.h>		// for printf(), scanf()
#include <math.h>

int main(void)
{
	int		max, i, fibonacci = 0;
	double	root5 = sqrt(5);

#if 0
	printf("root5 = %g\n", root5);
#endif
	
	printf("数値を入力してください＝＞ ");
	scanf("%d", &max);
	
	for (i = 0; ; i++) {
		fibonacci = (int)((pow(((1+root5)/2), i) - pow(((1-root5)/2), i)) / root5);
		if (max < fibonacci) {
			break;
		}
		printf("%d, ", fibonacci);
	};

	printf("\n");

	return 0;
}

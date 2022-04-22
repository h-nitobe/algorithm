/**
*	@file		ex3_005.c
*	@brief		�t�B�{�i�b�`����i�ʉ��j
*	@author		Hiroaki Nitobe / �V�n�ˍL��
*	@date		2022/04/24
*	@details	���̐����l����͂��A���̐��l�܂ł̃t�B�{�i�b�`�����\������v���O�������쐬���Ă��������B
*				�E�ŏ��̂Q���͂O�ƂP�ŁA�Ȍ�͂��̒��O�̂Q�̍��̘a�ƂȂ��Ă��܂��B
*				0 1 1 2 3 5 8 13 21 34 55 89 144 �E�E�E���Ƒ����܂��B
*				�o�̓C���[�W
*				C:\Vc7\algorithm>ex3_005
*				���l����͂��Ă����������� 1000
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
	
	printf("���l����͂��Ă����������� ");
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

/**
*	@file		ex02.c
*	@brief		main()�@�V�n�˃_�[�N�T�C�h��
*	@author		�V�n�ˍL��
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
	
	printf("�����������K�Q�J�n����\n\n");
	
	printf("%d����%d�܂ł̐��l��%d����͂��Ă�������\n", NUM_MIN, NUM_MAX, SIZE);
	
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
	printf("\n��ň�ԑ傫�Ȑ��l�F");
	printf(oddMax != ERR ? "%d\n" : "�Ȃ�\n", oddMax);	// (5)
	
	secMin = getSecondMin(num, i);						// (4)
	printf("������������2�Ԗڂ̐��l�F");
	printf(secMin != NUM_MAX ? "%d\n" : "�Ȃ�\n", secMin);	// (5)

	printf("\n�����������K�Q�I������");
		
	return 0;
}

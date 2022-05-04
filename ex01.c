/**
*	@file		ex01.c
*	@brief		main()�@�V�n�˃_�[�N�T�C�h��
*	@author		�V�n�ˍL��
*	@date		2022/05/02
*	@details	
*/

#include <stdio.h>
#include "getFunc.h"

#define BUFFER_SIZE	(100)						// (3) ������o�b�t�@�̃T�C�Y
#define	LINE	"--------------------"

int main(void)
{
	char	buff[BUFFER_SIZE];
	int 	i = 0, line = 0;
	
	printf("�����������K�P�J�n����\n\n");
	
	/* ������̓��� */
	printf("��������͂��Ă��������i%d�����ȓ��j\n", BUFFER_SIZE - 2);	// (1)
	
	/* getString()�ɂ��f�[�^���� */
	if (getString("input => ", buff, BUFFER_SIZE)) {
		return ERR;
	}
	
	printf(LINE);
	while (buff[i] != '\0') {
			if (!(i % 10)) {											// (2)
			printf("\n����(%2d)�F", ++line);
		}
		printf("%c", buff[i++]);
	}
	
	printf("\n" LINE);
	printf("\n%d�����\�����܂���\n\n", i);	
	printf("�����������K�P�I������");
		
		
	return 0;
}

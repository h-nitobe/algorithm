/**
*	@file		ex3_003.c
*	@brief		�啶���������ϊ��i�ʉ��j
*	@author		Hiroaki Nitobe / �V�n�ˍL��
*	@date		2022/04/24
*	@details	���͂�����������A�p���̑啶���Ə�������ϊ����ĕ\������v���O�������쐬���Ă��������B
*				�E�p���ȊO�͂��̂܂܏o�͂��Ă��������B
*				�EASCII�����Z�b�g���g�p���邱�Ƃ��O��̃v���O�����ł��܂��܂���B
*				�o�̓C���[�W
*				C:\Vc7\algorithm>ex3_003
*				�����i�X�X�����܂Łj����͂��Ă�������
*				���� QWERTYUIOPasdfghjkl123456789!"#$%&'()
*				���� qwertyuiopASDFGHJKL123456789!"#$%&'()
*/

#include <stdio.h>		// for printf(), scanf()
#include <string.h>		// for strlen()
#include <ctype.h>		// for islower(), isupper(), tolower(), toupper()

int main(void)
{
	char	str[100];
	int		len, i;
	
	printf("�����i�X�X�����܂Łj����͂��Ă�������\n���� ");
	scanf("%s", str);
	
	len = strlen(str);
	
	for (i = 0; i <len; i++) {
		if (isupper(str[i])) {				// �啶����������
			str[i] = (char)tolower(str[i]);	// �������ɂ���
		} else if (islower(str[i])) {		// ��������������
			str[i] = (char)toupper(str[i]);	// �啶���ɂ���
		}
	}

	printf("���� %s\n", str);

	return 0;
}

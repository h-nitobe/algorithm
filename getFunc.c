/**
*	@file		getFunc.c
*	@brief		getString(),getNumber�@�V�n�˃_�[�N�T�C�h��
*	@author		�V�n�ˍL��
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
			if ((p = strchr(buf, '\n')) != NULL) {		// ���͉ߑ��łȂ����	
					*p = '\0';							// (5)
					ret = OK;							// (4)
			} else {									// (3) ���͉ߑ�
				printf("<%d�����ȓ��œ��͂��Ă�������>\n", size - 2);
				while (getchar() != '\n') ;				// �X�g���[���o�b�t�@�N���A
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
			if (strchr(buf, '\n') != NULL) {			// ���͉ߑ��łȂ����	
				if (isdigit(buf[0])) {
					num = atoi(buf);
					if (min <= num && num <= max) {		// (4)
						ret = num;	
					} else {							// (3)
						printf("��%d�`%d�͈̔͂œ��͂��Ă���������\n", min, max);
						ret = LOOP;
					}
				} else if (buf[0] == '\n') {
					ret = CR;
				} else {								// (3)
					printf("��'0'�`'9'�ȊO�̕�������͂��Ȃ��ł���������\n");
					ret = LOOP;
				}
			} else {									// ���͉ߑ�
				while (getchar() != '\n') ;				// �X�g���[���o�b�t�@�N���A
				printf("��%d�����ȉ��̐��l����͂��Ă���������\n", DIG_MAX - 2);
//				ret = LOOP;								// ����
			}
		} else {
			ret = ERR;
		}
	} while (ret == LOOP);
	
	return ret;
}

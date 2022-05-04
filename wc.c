/*======================================================================
	�v���W�F�N�g��	�FC����v���O���~���O�i�ǉ��������K1�j�_�[�N�T�C�h�Łi�}�l�����Ⴞ�߂�j
	�t�@�C����	�Fwc.c
	�@�\		�F�e�L�X�g�t�@�C���`�F�b�N
	���i�d�l���j���r���[�F
		�K���J�[�Y��UNIX�̓N�w
			�P�D���������͔̂������B
			�Q�D�e�v���O��������̂��Ƃ����܂����悤�ɂ���B
			�R�D�ł�����葁�����^�i�v���g�^�C�v�j�����B
			�S�D���������ڐA���₷����I�ׁB
			�T�D�P���ȃe�L�X�g�t�@�C���Ƀf�[�^���i�[����B
			�U�D�\�t�g�E�F�A�𞌎q(�Ă�)�Ƃ��ė��p����B
			�V�D�����ƈڐA�������߂邽�߂ɃV�F���X�N���v�g�𗘗p����B
			�W�D�S���I�ȃ��[�U�[�C���^�[�t�F�[�X�͍��ȁB
			�X�D�S�Ẵv���O�����̓t�B���^�Ƃ��ĐU�镑���悤�ɂ���B
		https://ja.wikipedia.org/wiki/UNIX�N�w

		UNIX�N�w�ɔ����܂��̂ŁA�]�v�ȏo�͂͂������܂���B�i�V�n�ˁj
		�t�B���^�Ƃ���ׁA�t�@�C�����̃L�[�C���͂����܂���B�i�V�n�ˁj

	�C������	�F1.00	2021/04/24�@�V�n�ˍL���@�쐬
	Copyright(c) 2020 emBex Education inc. All Rights Reserved.
======================================================================*/

/* �w�b�_�t�@�C����荞�� */
#include	<stdio.h>	/* fprintf() �� */
#include	<stdlib.h>	/* exit() */
#include	<ctype.h>	/* isgraph() */

/* �񋓌^ */
typedef enum { FALSE, TRUE } BOOL;

/* �֐��v���g�^�C�v�錾 */
void countWord(FILE *fp);

/*======================================================================
	�֐���		�Fmain
	�@�\		�F���C������
	���͈�������	�FNone
	�o�͈�������	�FNone
	�߂�l		�F�I�����i��ɂO�j
	���͏��	�FNone
	�o�͏��	�FNone
	���L����	�FNone
	�C������	�F1.00	2021/04/24	�V�n�ˍL��	�쐬
======================================================================*/

int main(int argc, char *argv[])
{
	FILE	*fp;
	
	if (argc == 1) {
		countWord(stdin);
	} else if (1 < argc) {
		if ((fp = fopen(argv[1], "rb")) == NULL) {	/* �������̂ݏ��� */
			fprintf(stderr, "%s:�z�l�ȃt�@�C���͂���܂���\n" , argv[1]);
			exit(1);
		}
		if (2 < argc) {
			fprintf(stderr, "�������ȍ~�͖������܂���\n");
		}

		countWord(fp);
		
		if (argc == 2) {
			fprintf(stdout, "%s\n", argv[1]);
		}

		fclose(fp);
	}
	
	return 0;
}

/*======================================================================
	�֐���		�FcountWord
	�@�\		�F�s�A�P��A�����J�E���g
	���͈�������	�FFILE *fp �X�g���[���|�C���^
	�o�͈�������	�FNone
	�߂�l		�FNone
	���͏��	�FNone
	�o�͏��	�FNone
	���L����	�FNone
	�C������	�F1.00	2021/04/24�@�V�n�ˍL���@�쐬
======================================================================*/

void countWord(FILE *fp)
{
	int	ch;
	int 	charCount = 0;
	int	wordCount = 0;
	int	lineCount = 0;
	BOOL	inWord = FALSE;
	
	do {
		ch = fgetc(fp);
		
		if (isgraph(ch)) {		/* isprint() �̓X�y�[�X���܂� */
			inWord = TRUE;
			charCount++;
		} else if (inWord) {
			inWord = FALSE;
			wordCount++;
		}
		if ((ch == '\n') || (ch == EOF)) {
			lineCount++;
		}
	} while (ch != EOF);
	
	fprintf(stdout, "%d\t%d\t%d\t", lineCount, wordCount, charCount);
}

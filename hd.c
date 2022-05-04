/*======================================================================
	�v���W�F�N�g��	�FC����v���O���~���O�i�ǉ��������K2�j�_�[�N�T�C�h�Łi�}�l�����Ⴞ�߂�j
	�t�@�C����	�Fhd.c
	�@�\		�F�_���v�R�}���h
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

	�C������	�F1.00	2021/04/24	�V�n�ˍL��	�쐬
			�F1.01	2021/04/25	�V�n�ˍL��	�W�����o�̓o�C�i���Ή�
	Copyright(c) 2020 emBex Education inc. All Rights Reserved.
======================================================================*/

/* �w�b�_�t�@�C����荞�� */
#include	<stdio.h>	/* fprintf() �� */
#include	<stdlib.h>	/* exit() */
#include	<ctype.h>	/* isprint() */
#include	<io.h>		/* _setmode() */
#include	<fcntl.h>	/* for _O_TEXT and _O_BINARY */

/* �L���萔�E�}�N���֐� */
#define		PROC_UNIT	16
#define		isKanji1(c)	(0x81 <= (c) && (c) <= 0x9F || 0xE0 <= (c) && (c) <= 0xFC)
#define		isKanji2(c)	(0x40 <= (c) && (c) <= 0xFC && (c) != 0x7F)

/* �񋓌^ */
typedef enum { FALSE, TRUE } BOOL;

/* �֐��v���g�^�C�v�錾 */
void dumpStream(FILE *fp);

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
	
	if (_setmode( _fileno(stdin) , _O_BINARY ) == -1) {	/* �W�����͂��o�C�i�����[�h�ɂ��� */
		fprintf( stderr , "System error [%d]\n" , errno );
		exit(1);
	}
	if (_setmode( _fileno(stdout) , _O_BINARY ) == -1) {	/* �W���o�͂��o�C�i�����[�h�ɂ��� */
		fprintf( stderr , "System error [%d]\n" , errno );
		exit(1);
	}
	
	if (argc == 1) {
		dumpStream(stdin);
	} else if (1 < argc) {
		if ((fp = fopen(argv[1], "rb")) == NULL) {	/* �������̂ݏ��� */
			fprintf(stderr, "%s:�z�l�ȃt�@�C���͂���܂���\n" , argv[1]);
			exit(1);
		}
		if (2 < argc) {
			fprintf(stderr, "�������ȍ~�͖������܂���\n");
		}

		dumpStream(fp);

		fclose(fp);
	}
	
	return 0;
}

/*======================================================================
	�֐���		�FdumpStream
	�@�\		�F16�i�_���v
	���͈�������	�FFILE *fp �X�g���[���|�C���^
	�o�͈�������	�FNone
	�߂�l		�FNone
	���͏��	�FNone
	�o�͏��	�FNone
	���L����	�FNone
	�C������	�F1.00	2021/04/24	�V�n�ˍL��	�쐬
======================================================================*/

void dumpStream(FILE *fp)
{
	int		line[PROC_UNIT + 1];			/* ��s16�����{1(�����p�\���̈�) */
	unsigned char 	kanji[2 + 1];				/* �����R�[�h�{�^�[�~�l�[�^ */
	int		address = 0, idx, ch = '\0';
	BOOL		kanjiFlag = FALSE;
	
	do {
		/* ��s������ */
		for (idx = 0; idx <= PROC_UNIT; idx++) {	/* �������������ɔ����Ĉꕶ���]�v�ɓǂ�ł��� */
			if ((ch = fgetc(fp)) != EOF) {
				line[idx] = ch;
			} else {
				break;				/* EOF ���o�������烋�[�v�𔲂��� */
			}
		}
		if (ch != EOF) {
			ungetc(ch,  fp);			/* �X�g���[���o�b�t�@�ɖ߂����ǂ� */
		} else {
			for ( ; idx <= PROC_UNIT; idx++) {	/* EOF ���o��������c��S�� EOF */
				line[idx] = EOF;
			}
		}
		
		/* ��s���o�� */
		
		fprintf(stdout, " %08X ", address);		/* �A�h���X�����o�� */
		address += PROC_UNIT;
		
		for (idx = 0; idx < PROC_UNIT; idx++) {		/* �w�L�T�f�V�}�������o�� */
			ch = line[idx];
			if (ch != EOF) {
				fprintf(stdout, "%02X ", ch);
			} else {
				fprintf(stdout, "   ");
			}
		}
		
		for (idx = 0; idx < PROC_UNIT; idx++) {		/* �e�L�X�g�����o�� */
			ch = line[idx];
			if (kanjiFlag) {
				kanjiFlag = FALSE;
				fputc(' ', stdout);
			} else if (isKanji1(line[idx]) && isKanji2(line[idx + 1])) {	/* ������ */
				kanji[0] = (unsigned char) line[idx++];
				kanji[1] = (unsigned char) line[idx];
				kanji[2] = '\0';
				fprintf(stdout, "%s", kanji);
				if (idx == PROC_UNIT) {
					kanjiFlag = TRUE;
				}
			} else if (ch == EOF) {			/* EOF�Ȃ� */
				fputc(' ', stdout);		/* ' '��\������ */
			} else if (isprint(ch)) {		/* �\���\�Ȃ�i�X�y�[�X�܂ށj */
				fputc(ch, stdout);		/* ���̕�����\������ */
			} else {				/* �\���s�\�Ȃ� */
				fputc('.', stdout);		/* '.'��\������ */
			}
		}
		
		fprintf(stdout, "\n");				/* ��s�I��� */
	} while (ch != EOF);
}

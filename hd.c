/*======================================================================
	プロジェクト名	：C言語プログラミング（追加総合演習2）ダークサイド版（マネしちゃだめよ）
	ファイル名	：hd.c
	機能		：ダンプコマンド
	問題（仕様書）レビュー：
		ガンカーズのUNIXの哲学
			１．小さいものは美しい。
			２．各プログラムが一つのことをうまくやるようにせよ。
			３．できる限り早く原型（プロトタイプ）を作れ。
			４．効率よりも移植しやすさを選べ。
			５．単純なテキストファイルにデータを格納せよ。
			６．ソフトウェアを梃子(てこ)として利用せよ。
			７．効率と移植性を高めるためにシェルスクリプトを利用せよ。
			８．拘束的なユーザーインターフェースは作るな。
			９．全てのプログラムはフィルタとして振る舞うようにせよ。
		https://ja.wikipedia.org/wiki/UNIX哲学

		UNIX哲学に反しますので、余計な出力はいたしません。（新渡戸）
		フィルタとする為、ファイル名のキーインはさせません。（新渡戸）

	修正履歴	：1.00	2021/04/24	新渡戸広明	作成
			：1.01	2021/04/25	新渡戸広明	標準入出力バイナリ対応
	Copyright(c) 2020 emBex Education inc. All Rights Reserved.
======================================================================*/

/* ヘッダファイル取り込み */
#include	<stdio.h>	/* fprintf() 他 */
#include	<stdlib.h>	/* exit() */
#include	<ctype.h>	/* isprint() */
#include	<io.h>		/* _setmode() */
#include	<fcntl.h>	/* for _O_TEXT and _O_BINARY */

/* 記号定数・マクロ関数 */
#define		PROC_UNIT	16
#define		isKanji1(c)	(0x81 <= (c) && (c) <= 0x9F || 0xE0 <= (c) && (c) <= 0xFC)
#define		isKanji2(c)	(0x40 <= (c) && (c) <= 0xFC && (c) != 0x7F)

/* 列挙型 */
typedef enum { FALSE, TRUE } BOOL;

/* 関数プロトタイプ宣言 */
void dumpStream(FILE *fp);

/*======================================================================
	関数名		：main
	機能		：メイン処理
	入力引数説明	：None
	出力引数説明	：None
	戻り値		：終了情報（常に０）
	入力情報	：None
	出力情報	：None
	特記事項	：None
	修正履歴	：1.00	2021/04/24	新渡戸広明	作成
======================================================================*/

int main(int argc, char *argv[])
{
	FILE	*fp;
	
	if (_setmode( _fileno(stdin) , _O_BINARY ) == -1) {	/* 標準入力をバイナリモードにする */
		fprintf( stderr , "System error [%d]\n" , errno );
		exit(1);
	}
	if (_setmode( _fileno(stdout) , _O_BINARY ) == -1) {	/* 標準出力をバイナリモードにする */
		fprintf( stderr , "System error [%d]\n" , errno );
		exit(1);
	}
	
	if (argc == 1) {
		dumpStream(stdin);
	} else if (1 < argc) {
		if ((fp = fopen(argv[1], "rb")) == NULL) {	/* 第一引数のみ処理 */
			fprintf(stderr, "%s:斯様なファイルはありませぬ\n" , argv[1]);
			exit(1);
		}
		if (2 < argc) {
			fprintf(stderr, "第二引数以降は無視しまする\n");
		}

		dumpStream(fp);

		fclose(fp);
	}
	
	return 0;
}

/*======================================================================
	関数名		：dumpStream
	機能		：16進ダンプ
	入力引数説明	：FILE *fp ストリームポインタ
	出力引数説明	：None
	戻り値		：None
	入力情報	：None
	出力情報	：None
	特記事項	：None
	修正履歴	：1.00	2021/04/24	新渡戸広明	作成
======================================================================*/

void dumpStream(FILE *fp)
{
	int		line[PROC_UNIT + 1];			/* 一行16文字＋1(漢字用予備領域) */
	unsigned char 	kanji[2 + 1];				/* 漢字コード＋ターミネータ */
	int		address = 0, idx, ch = '\0';
	BOOL		kanjiFlag = FALSE;
	
	do {
		/* 一行分入力 */
		for (idx = 0; idx <= PROC_UNIT; idx++) {	/* 漢字だった時に備えて一文字余計に読んでおく */
			if ((ch = fgetc(fp)) != EOF) {
				line[idx] = ch;
			} else {
				break;				/* EOF が出現したらループを抜ける */
			}
		}
		if (ch != EOF) {
			ungetc(ch,  fp);			/* ストリームバッファに戻すけどね */
		} else {
			for ( ; idx <= PROC_UNIT; idx++) {	/* EOF が出現したら残り全て EOF */
				line[idx] = EOF;
			}
		}
		
		/* 一行分出力 */
		
		fprintf(stdout, " %08X ", address);		/* アドレス部分出力 */
		address += PROC_UNIT;
		
		for (idx = 0; idx < PROC_UNIT; idx++) {		/* ヘキサデシマル部分出力 */
			ch = line[idx];
			if (ch != EOF) {
				fprintf(stdout, "%02X ", ch);
			} else {
				fprintf(stdout, "   ");
			}
		}
		
		for (idx = 0; idx < PROC_UNIT; idx++) {		/* テキスト部分出力 */
			ch = line[idx];
			if (kanjiFlag) {
				kanjiFlag = FALSE;
				fputc(' ', stdout);
			} else if (isKanji1(line[idx]) && isKanji2(line[idx + 1])) {	/* 漢字だ */
				kanji[0] = (unsigned char) line[idx++];
				kanji[1] = (unsigned char) line[idx];
				kanji[2] = '\0';
				fprintf(stdout, "%s", kanji);
				if (idx == PROC_UNIT) {
					kanjiFlag = TRUE;
				}
			} else if (ch == EOF) {			/* EOFなら */
				fputc(' ', stdout);		/* ' 'を表示する */
			} else if (isprint(ch)) {		/* 表示可能なら（スペース含む） */
				fputc(ch, stdout);		/* その文字を表示する */
			} else {				/* 表示不可能なら */
				fputc('.', stdout);		/* '.'を表示する */
			}
		}
		
		fprintf(stdout, "\n");				/* 一行終わり */
	} while (ch != EOF);
}

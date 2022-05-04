/*======================================================================
	プロジェクト名	：C言語プログラミング（追加総合演習1）ダークサイド版（マネしちゃだめよ）
	ファイル名	：wc.c
	機能		：テキストファイルチェック
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

	修正履歴	：1.00	2021/04/24　新渡戸広明　作成
	Copyright(c) 2020 emBex Education inc. All Rights Reserved.
======================================================================*/

/* ヘッダファイル取り込み */
#include	<stdio.h>	/* fprintf() 他 */
#include	<stdlib.h>	/* exit() */
#include	<ctype.h>	/* isgraph() */

/* 列挙型 */
typedef enum { FALSE, TRUE } BOOL;

/* 関数プロトタイプ宣言 */
void countWord(FILE *fp);

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
	
	if (argc == 1) {
		countWord(stdin);
	} else if (1 < argc) {
		if ((fp = fopen(argv[1], "rb")) == NULL) {	/* 第一引数のみ処理 */
			fprintf(stderr, "%s:斯様なファイルはありませぬ\n" , argv[1]);
			exit(1);
		}
		if (2 < argc) {
			fprintf(stderr, "第二引数以降は無視しまする\n");
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
	関数名		：countWord
	機能		：行、単語、文字カウント
	入力引数説明	：FILE *fp ストリームポインタ
	出力引数説明	：None
	戻り値		：None
	入力情報	：None
	出力情報	：None
	特記事項	：None
	修正履歴	：1.00	2021/04/24　新渡戸広明　作成
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
		
		if (isgraph(ch)) {		/* isprint() はスペースを含む */
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

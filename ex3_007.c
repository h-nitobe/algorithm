/**
*	@file		ex3_007.c
*	@brief		���S���ƗF�����i�ʉ��j
*	@author		Hiroaki Nitobe / �V�n�ˍL��
*	@date		2022/04/24
*	@details	�P����P�O�O�O�O�܂ł̊��S���ƁA�F�����̑g�����߂�v���O�������쐬���ĉ������B
*				�������g�ȊO�̖񐔂̑��a���������g�ɓ������Ȃ鎩�R�������S���iperfect number�j�Ƃ����܂��B
*				�������g�ȊO�̖񐔂̑��a���A�݂��ɑ����̐��Ɠ������Ȃ�悤�ȈقȂ鎩�R���̑g��F�����iamicable number�j�ƌ����܂��B
*				�o�̓C���[�W
*				c:\Vc7\algorithm>ex3_007
*				���S���[�� 6, 28, 496, 8128,
*				1����10000�܂łɁA���S����4���݂��܂���
*				
*				�F�����[�� (220:284), (1184:1210), (2620:2924), (5020:5564), (6232:6368),
*				1����10000�܂łɁA�F������5�g���݂��܂���
*/

#include	<stdio.h>

#define		MAX		10000

int main(void)
{
	int	i, j;
	int	sum1, sum2;
	int perfect = 0, amicable = 0;
	
	/* ���S����T�� */
	
	printf("���S���[��");
	for (i = 1; i <= MAX; i++) {
		sum1 = 0;
		for (j = 1; j <= (i / 2); j++) {
			if (!(i % j)) {					// �񐔂�T��
				sum1+= j;					// ��������
			}
		}
		if (i == sum1) {					// �񐔂̍��v�Ǝ������g�������Ȃ犮�S��
			printf(" %d,", i);
			perfect++;
		}
	}
	
	printf("\n1����%d�܂łɁA���S����%d���݂��܂���\n\n", MAX, perfect);
	
	/* �F������T�� */
	
	printf("�F�����[��");
	for (i = 1; i <= MAX; i++) {
		sum2 = sum1 = 0;
		for (j = 1; j <= (i / 2); j++) {
			if (!(i % j)) {					// �񐔂�T��
				sum1 += j;					// ��������
			}
		}
		for (j = 1; j <= (sum1 / 2); j++) {
			if (!(sum1 % j)) {				// sum1 �̖񐔂�T��
				sum2 += j;					// ��������
			}
		}
		if (i < sum1 && sum2 == i) {		// sum1 ���������g���傫���ꍇ�A���Asum2 ���������g�Ȃ�F����
			printf(" (%d:%d),", i, sum1);
			amicable++;
		}
	}
	
	printf("\n1����%d�܂łɁA�F������%d�g���݂��܂���\n", MAX, amicable);
	
	return 0;
}

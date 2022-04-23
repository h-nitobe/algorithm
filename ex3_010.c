/**
*	@file		ex3_007.c
*	@brief		���[�N���b�h�̌ݏ��@�i�ʉ��j
*	@author		Hiroaki Nitobe / �V�n�ˍL��
*	@date		2022/04/24
*	@details	�Q�̐��̐�������͂��āA���̍ő���񐔂��A���[�N���b�h�̌ݏ��@��p���ĎZ�o����v���O�������쐬���Ă��������B
*				�P�D�Q�̐����̑傫������폜���A���������������Ƃ��ď��Z���s���A��]�����߂�B
*				�Q�D��]���O�łȂ��ꍇ�́A�O��̏�����폜���ɁA�O��̏�]�������ɂ��ď��Z���s���A��]�����߂�B
*				�R�D��]���O�ɂȂ�܂łQ���J��Ԃ��A��]���O�ɂȂ�����A�Ō�̏������ő���񐔁B
*				�o�̓C���[�W
*				C:\Vc7\algorithm>ex3_010
*				���l1����͂��Ă������� => 384
*				���l2����͂��Ă������� => 720
*				720 / 384 -> 1...336
*				384 / 336 -> 1...48
*				336 / 48 -> 7...0
*				384��720�̍ő���񐔂�48�ł�
*/

#include	<stdio.h>

int gcd(int a, int b);
void swap(int *x, int *y);

int main(void)
{
	int		n1, n2;

	/* 2�̐��l����͂��� */
	printf("���l1����͂��Ă������� => ");
	scanf("%d", &n1);
	
	printf("���l2����͂��Ă������� => ");
	scanf("%d", &n2);

	printf("%d��%d�̍ő���񐔂�%d�ł�\n", n1, n2, gcd(n1, n2));
	
	return 0;
}

/**
*	@fn			int get_gcd(int a, int b)
*	@brief 		�^����ꂽ2�l�̍ő���񐔂�ԋp����
*	@param[in]	a , b
*	@param[out]	�ő����
*	@return 	int �ő����
*	@details 	���[�N���b�h�̌ݏ��@�ōő���񐔂����߂�
*				https://ja.wikipedia.org/wiki/���[�N���b�h�̌ݏ��@
*/
int gcd(int a, int b)
{
	if (b == 0) return 0;
	if (a < b) {
		swap(&a, &b);
	}
	
	printf("%d / %d -> %d...%d\n", a, b, a/b, a%b);
	
	if (a % b == 0) {
		return b;
	} else {
		return gcd(b, a % b);
	}
}

void swap(int *x, int *y)
{
	if (x != y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}

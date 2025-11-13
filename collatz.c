// Collatz problem

#include	<stdio.h>

int main(void)
{
	int	n;

	for (;;) {
		printf("N : ");
		scanf("%d", &n);
		printf("%d ", n);
		if (n <= 1) break;

		while (n != 1) {
			n = (n % 2) ? 3 * n + 1 : n / 2 ;
			printf("%d ", n);
			fflush(stdout);
		}
		printf("\n");
	}

	return 0;
}


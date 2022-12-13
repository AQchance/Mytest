#include<stdio.h>
int main()
{
	int a[40][40] = { 0 };
	int i, j, k, l, N, K, i0, j0;
	scanf("%d", &N);
	K = 1;
	a[0][(N - 1) / 2] = K;
	K++;
	for (; K <= N * N; K++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (a[i][j] == K - 1) {
					i0 = i;
					j0 = j;
					goto out;
				}
			}
		}
	out:
		if (i0 == 0 && j0 < N - 1) {
			a[N - 1][j0 + 1] = K;
			continue;
		}
		if (j0 == N - 1 && i0 > 0) {
			a[i0 - 1][0] = K;
			continue;
		}
		if (i0 == 0 && j0 == N - 1) {
			a[i0 + 1][j0] = K;
			continue;
		}
		if (i0 > 0 && j0 < N - 1) {
			if (a[i0 - 1][j0 + 1] == 0) {
				a[i0 - 1][j0 + 1] = K;
			}
			else {
				a[i0 + 1][j0] = K;
			}
			continue;
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (j < N - 1) printf("%d ", a[i][j]);
			else printf("%d\n", a[i][j]);
		}
	}
	return 0;
}
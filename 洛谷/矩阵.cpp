#include<stdio.h>
int main()
{
	int a[20][20];
	int i, j, k, l, m;
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int b[42] = { 0 };
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			b[i] += a[i][j];
		}
	}
	for (j = 0; j < m; j++) {
		for (i = 0; i < m; i++) {
			b[m + j] += a[i][j];
		}
	}
	for (i = 0; i < m; i++) {
		b[2 * m] += a[i][i];
	}
	for (i = 0; i < m; i++) {
		b[2 * m + 1] += a[i][m - 1 - i];
	}
	for (i = 0; i < 2 * m + 1; i++) {
		for (j = i + 1,k = i;j<2*m+2; j++) {
			if (b[j] > b[k]) k = j;
		}
		if (k != i) {
			l = b[k];
			b[k] = b[i];
			b[i] = l;
		}
	}
		for (i = 0; i < 2 * m + 2; i++) {
			printf("%d ", b[i]);
		}
	return 0;
}


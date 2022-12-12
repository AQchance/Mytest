#include<stdio.h>
int main()
{
	int m, n, i, j, k, l,p;
	int a[30][30] = { {0},{0} };
	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int b[30][30];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			b[i][j] = a[i][j];
		}
	}
	int count = 1;
	for (k = 0; k < m; k++) {
		count = 1;
		for (l = 0; l < n - 1; l++) {
			if (b[k][l] == b[k][l + 1]) count++;
			else count = 1;
			p = count;
			if (p>= 3) {
				for (; p >= 1; p--) {
					a[k][l - p + 2] = 0;
				}
			}
		}
	}
	for (j = 0; j < n; j++) {
		count = 1;
		for (i = 0; i < m - 1; i++) {
			if (b[i][j] == b[i + 1][j]) {
				count++;
			}
			else count = 1;
			p = count;
			if (p >= 3) {
				for (; p >= 1; p--) {
					a[i + 2 - p][j] = 0;
				}
			}
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (j != n - 1) printf("%d ", a[i][j]);
			else printf("%d\n", a[i][j]);
		}
	}
	return 0;
}

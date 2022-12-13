#include<stdio.h>
int main()
{
	int a[100][100];
	int n, i, j, k, l;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("%d ", a[0][0]);
	for (k = 0, j = 1; j < 2*n-2; j++) {
		if (j < n) {
			if (j % 2 != 0) {
				for (; k <= j; k++) {
					printf("%d ", a[k][j - k]);
				}
				k = 0;
			}
			if (j % 2 == 0) {
				for (; k <= j; k++) {
					printf("%d ", a[j - k][k]);
				}
				k = 0;
			}
		}
		if (j >= n) {
			if (j % 2 == 0) {
				k = j + 1 - n;
				for (i=0; k < n; k++,i++) {
					printf("%d ", a[n - 1 - i][k]);
				}
			}
			if (j % 2 != 0) {
				k = j + 1 - n;
				for (i=0; k < n; k++,i++) {
					printf("%d ", a[k][n - 1 - i]);
				}
			}
		}
	}
	printf("%d ", a[n - 1][n - 1]);
	return 0;
}
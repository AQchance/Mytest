#include<stdio.h>
int main()
{
	int a[100][100];
	int i, j, k, l, m, n;
	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (j = 0; j < n; j++) {
		for (i = m-1; i >=0; i--) {
			if (i != 0) {
				printf("%d ", a[i][j]);
			}
			else printf("%d\n", a[i][j]);
		}
	}
	return 0;
}
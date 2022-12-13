#include<stdio.h>
int main()
{
	int m, n, i, j, k, l,r,s;
	int exit;
	int count = 0;
	scanf("%d %d", &m, &n);
	int a[100][100];
	int b[100];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 1, k = 0; j < n; j++) {
			if (a[i][k] > a[i][j]) k = j;
		}
		exit = 1;
		for (r = 0; r < m; r++) {
			if (a[r][k] > a[i][k]) {
				exit = 0; 
				break;
			}
		}
		if (exit == 1) {
			count++;
			printf("%d %d %d\n", i, k, a[i][k]);
		}
	}
	if (count == 0) printf("no\n");
	return 0;
}
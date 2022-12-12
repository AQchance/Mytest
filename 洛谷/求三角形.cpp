#include<stdio.h>
int main()
{
	int i, j, k=1, n;
	int num[9][18] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < 2 * n; j+=2) {
			num[i][j] = k / 10;
			num[i][j + 1] = k % 10;
			printf("%d%d", num[i][j], num[i][j + 1]);
			if (j == 2 * n - 2) printf("\n");
			k++;
		}
	}
	printf("\n");
	k = 1;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 2 * (n - i -1); j++) {
			printf(" ");
		}
		for (j=2*(n-i-1); j < 2 * n; j+=2,k++) {
			printf("%d%d", k / 10, k % 10);
			if (j == 2 * n - 2) printf("\n");
		}
	}
	return 0;
}
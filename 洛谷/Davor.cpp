#include<stdio.h>
int main()
{
	int n, x, k, i, j, sum = 0;
	scanf("%d", &n);
	n /= 52;
	for (k = 1;k<=n; k++) {
		for (x = 100; x >= (n - 21 * k) / 7; x--) {
			if (7*x+21*k==n) {
				printf("%d\n%d", x, k);
				goto here;
			}
		}
	}
here:
	return 0;
}
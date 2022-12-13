int prime(int n) {
	int exit = 1;
	int i = 2;
	for (; i <= n / 2; i++) {
		if (n % i == 0) {
			exit = 0;
			break;
		}
	}
	return exit;
}
#include<stdio.h>
int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 2; i <=n/2; i++) {
		if (n % i == 0) {
			if (prime(n / i) == 1) {
				printf("%d", n/i);
				break;
			}
		}
	}
	return 0;
}
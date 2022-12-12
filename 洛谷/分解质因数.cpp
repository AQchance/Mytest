#include<stdio.h>
int main()
{
	int n, a;
	int exit;
	scanf("%d", &n);
	for (a = 2; a <= n; a++) {
		exit = 0;
		for (int i = 2; i < (a - 1); i++) {
			if (exit == 1) break;
			if (a % i == 0) {
				exit = 1;
			}
		}
		if (exit == 0 && n % a == 0) {
			if (n / a != 1) {
				printf("%d*", a);
			}
			else {
				printf("%d", a);
			}
			n /= a;
			a = 1;
		}
	}
	return 0;
}
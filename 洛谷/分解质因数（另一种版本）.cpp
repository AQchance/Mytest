#include<stdio.h>
int f(int x) {
	int i, exit = 0;
	if (x == 2) exit = 0;
	else{
		for (i = 2; i < x; i++) {
			if (x % i == 0) {
				exit = 1;
				break;
			}
			else {
				exit = 0;
				continue;
			}
		}
	}
	return exit;
}
int main() {
	int n, i, m;
	scanf("%d", &n);
	for (i = 2; i <= n; i++) {
		if (f(i) == 0) {
			if (n % i == 0) {
				printf("%d", i);
				n /= i;
				i--;
				if (n != 1) printf("*");
			}
		}
	}
	return 0;
}
int prime(int n) {
	int i;
	int exit = 1;
	for (i = 2; i <= n / 2; i++) {
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
	int a, b, n;
	int i, j, k, l;
	scanf("%d %d", &a, &b);
	for (i = a; i <= b; i++) {
		if (prime(i) == 0) {
			continue;
		}
		else {
			int count = 0;
			j = i;
			int a[9];
			for (k = 0; j > 0; j /= 10) {
				count++;
				a[k] = j % 10;
				k++;
			}
			if (count == 1) {
				printf("%d\n", i);
			}
			else{
				l = 1;
				for (k = 0; k <= (count-1) / 2; k++) {
					if (a[k] != a[count-1-k]) {
						l = 0;
						break;
					}
					else {
						l = 1;
					}
				}
				if (l == 1) {
					printf("%d\n", i);
				}
			}
		}
	}
	return 0;
}
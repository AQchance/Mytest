#include<stdio.h>
int main()
{
	int n, i;
	char a[10] = { '\0' };
	scanf("%d", &n);
	if (n > 0) {
		for (i = 0; n > 0; n /= 10, i++) {
			a[i] = n % 10 + 48;
		}
		for (; i > 0; i--) {
			printf("%c", a[i - 1]);
		}
	}
	else if (n < 0) {
		n = 0 - n;
		for (i = 0; n > 0; n /= 10, i++) {
			a[i] = 48 + n % 10;
		}
		printf("-");
		for (; i > 0; i--) {
			printf("%c", a[i - 1]);
		}
	}
	else if (n == 0) printf("0");
	return 0;
}
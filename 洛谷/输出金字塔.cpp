#include<stdio.h>
int main()
{
	char a, b, c;
	int m, n, i;
	scanf("%c", &a);
	n = a - 'A' + 1;
	b = 'B';
	for (m = 0;m<n-1;m++) {
		printf(" ");
	}
	printf("A\n");
	for (i = n - 2; i >= 0; i--,b++) {
		for (m = 0; m < i; m++) {
			printf(" ");
		}
		for (c = 'A'; c < b; c++) {
			printf("%c", c);
		}
		for (; c >= 'A'; c--) {
			if (c == 'A') printf("%c\n", c);
			else printf("%c", c);
		}
	}
	return 0;
}
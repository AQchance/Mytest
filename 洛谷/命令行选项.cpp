#include<stdio.h>
int main()
{
	char a[256] = { '\0' };
	char b[256] = { '\0' };
	int i, j, k=0,exit=1,l;
	char m;
	gets_s(a);
	for (i = 0; a[i] != '\0'; i++) {
		exit = 1;
		if (a[i] != '-') continue;
		else {
			for (j = 0; b[j] != '\0'; j++) {
				if (b[j] == a[i + 1]) {
					exit = 0;
					break;
				}
			}
			if (exit == 1) {
				b[k] = a[i + 1];
				k++;
			}
			i += 2;
		}
	}
	for (i = 0; i < k - 1; i++) {
		for (j = i + 1, l = i; j < k; j++) {
			if (b[j] < b[l]) l = j;
		}
		if (l != i) {
			m = b[l];
			b[l] = b[i];
			b[i] = m;
		}
	}
	if (k != 0) {
		for (i = 0; b[i] != '\0'; i++) {
			printf("-%c ", b[i]);
		}
	}
	else printf("no");
	return 0;
}
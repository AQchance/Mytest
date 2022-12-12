#include<stdio.h>
int main()
{
	char a[80] = { '\0' };
	int i, j, k;
	char exchange;
	scanf("%s", &a);
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] >= 'a' && a[i] <= 'z') a[i] = a[i] + 'A' - 'a';
	}
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') {
			for (j = i + 1, k = i; a[j] != '\0'; j++) {
				if (a[j] < 'A' || a[j]>'Z') continue;
				else {
					if (a[j] < a[k]) k = j;
				}
			}
			if (k != i) {
				exchange = a[i];
				a[i] = a[k];
				a[k] = exchange;
			}
		}
		else continue;
	}
	printf("%s", a);
	return 0;
}
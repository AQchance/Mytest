#include<stdio.h>
int main()
{
	char a[100] = { '\0' };
	char b[100] = { '\0' };
	char c[200] = { '\0' };
	int i, k;
	scanf("%s", &a);
	getchar();
	scanf("%s", &b);
	getchar();
	for (k = 0; a[k] != '\0'; k++) {
		c[k] = a[k];
	}
	for (i = 0; b[i] != '\0'; i++,k++) {
		c[k] = b[i];
	}
	printf("%s", c);
	return 0;
}
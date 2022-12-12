#include<stdio.h>
int main()
{
	int a[10] = { 0 }, b[9] = { 0 };
	int i, j;
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &a[i]);
	}
	for (i = 0, j = 1; j < 10; j++, i++) {
		b[i] = a[j] / a[i];
	}
	for (i = 0; i < 9; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}
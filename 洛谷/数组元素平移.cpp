#include<stdio.h>
int main()
{
	int a[10] = { 0 };
	int p, i, j;
	scanf("%d", &p);
	for (j=0,i = p + 2; i <= 10; i++,j++) {
		a[j] = i;
	}
	for (i = 1; j < 10; j++,i++) {
		a[j] = i;
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}

}
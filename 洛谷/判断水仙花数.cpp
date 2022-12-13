#include<stdio.h>
int number(int a) {
	int n, sum = 0, m;
	m = a;
	while (m > 0) {
		n = m % 10;
		sum += n * n * n;
		m /= 10;
	}
	return sum;
}
int main()
{
	int i;
	scanf("%d", &i);
	if (i == number(i)) {
		printf("%d是水仙花数", i);
	}
	else {
		printf("%d不是水仙花数", i);
	}
	return 0;
}
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
		printf("%d��ˮ�ɻ���", i);
	}
	else {
		printf("%d����ˮ�ɻ���", i);
	}
	return 0;
}
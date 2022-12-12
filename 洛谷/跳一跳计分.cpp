#include<stdio.h>
int main()
{
	int N;
	int number;
	int factorial;
	int sum;
	int count;
	scanf("%d", &N);
	number = N;
	for (sum=0; number > 0; number--) {
		count = number;
		for (factorial = 1; count > 0; count--) {
			factorial *= count;
		}
		sum += factorial;
	}
	printf("%d %d %d", N, fatorial, sum);
	return 0;
}
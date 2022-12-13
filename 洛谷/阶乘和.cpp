#include<stdio.h>
int main()
{
	int N;
	int number;
	int factorial;
	int sum;
	int count;
	int max = 0;
	scanf("%d", &N);
	number = N;
	for (sum = 0; number > 0; number--) {
		count = number;
		for (factorial = 1; count > 0; count--) {
			factorial *= count;
			if (max < factorial) {
				max = factorial;
			}
		}
		sum += factorial;
	}
	printf("%d %d %d", N, max, sum);
	return 0;
}

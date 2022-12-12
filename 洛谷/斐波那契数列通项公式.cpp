#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	double m;
	scanf("%d", &n);
	m = (pow(sqrt(5) / 2 + 1.0 / 2, n) - pow((1 / 2.0 - sqrt(5) / 2), n)) / sqrt(5);
	printf("%.2lf", m);
	return 0;
}
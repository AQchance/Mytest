#include<stdio.h>
double func(double x) {
	return 2 * x * x * x - 4 * x * x + 3 * x - 6;
}
double func1(double x) {
	return 6 * x * x - 8 * x + 3;
}
int main()
{
	double x=1.5, ��;
	scanf("%lf", &��);
	for (; func(x) != 0;) {
		x = �� - func(��) / func1(��);
		�� = x;
	}
	printf("%.2lf", x);
	return 0;
}
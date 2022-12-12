#include<stdio.h>
int main()
{
	double S=0, h=100.0;
	int n;
	scanf("%d", &n);
	for (; n > 0; n--) {
		if (h == 100.0) S += h;
		else S += 2 * h;
		h /= 2;
	}
	printf("S=%.3lf h=%.3lf", S, h);
	return 0;
}
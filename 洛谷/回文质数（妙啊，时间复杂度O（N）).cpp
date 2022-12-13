#include<stdio.h>
#include<math.h>
int isprime(int x) {
	int i;
	if (x == 2||x==3) return 1;
	else {
		for (i = 2; i <= sqrt(x); i++) {
			if (x % i == 0) return 0;
		}
		return 1;
	}
}
int countpositions(int x) {
	int count = 0, i;
	for (i = 1; x / i > 0; i *= 10) {
		count++;
	}
	return count;
}
int sumeachposition(int a[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum *= 10;
		sum += a[i];
	}
	return sum;
}
int main()
{
	int i, j, k, l, a, b;
	int fig[10] = { 0 };
	scanf("%d %d", &a, &b);
	if (a <= 5 && 5 <= b) printf("5\n");
	if (a <= 7 && 7 <= b) printf("7\n");
	if (a <= 11 && 11 <= b) printf("11\n");
	for (i = 10; i < 9999; i++) {
		k = i;
		l = countpositions(k);
		for (j = 0; j < l; j++) {
			fig[l-1-j] = k % 10;
			k /= 10;
		}
		if (fig[0] % 2 == 0) continue;
		else {
			for (j = 0; j < l - 1; j++) {
				fig[2*l-2-j] = fig[j];
			}
		}
		k = sumeachposition(fig, 2*l - 1);
		if (k > b) break;
		else if (a <= k && k <= b && isprime(k) == 1) printf("%d\n",k);
	}
	return 0;
}
#include<stdio.h>
#include<math.h>
int isprime(int x) {
	if (x == 2 || x == 3) {
		return 1;
	}
	else {
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0) return 0;
		}
		return 1;
	}
}
int main()
{
	int i, p;
	scanf("%d", &p);
	for (i = 2; i <= sqrt(p); i++) {
		if (isprime(i)) {
			if (p % i == 0) {
				printf("%d", p / i);
				break;
			}
		}
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

double my_index(double x, int n) {
	double result = 1;
	for (int i = 0; i < n; i++) {
		result *= x;
	}
	return result;
}

double my_loge(double x) {
	double y = (x - 1) / (x + 1);
	double sum = 0;
	for (int i = 1; i <= 1000; i++) {
		sum =sum + (1.0 / (2 * i - 1)) * my_index(y, 2*i-1);
	}
	sum *= 2;
	return sum;
}

double my_log(double a, double n) {
	double x = my_loge(n);
	double y = my_loge(a);
	return x / y;
}

double my_pow(double x, double y) {
	double intpart;
	if (x > 1) {
		double m = modf(y, &intpart);
		double mid;
		double result = 1;
		double high = x,low = 1;
		result = my_index(x, (int)intpart);
		for (int i = 1; i <= 1000; i++) {
			mid = (high + low) / 2;
			if (my_log(x, mid) < y) low = mid;
			else if (my_log(x, mid) > y) high = mid;
			else return result * mid;
		}
		return result * mid;
	}
}

int main()
{
	int x = 2.0;
	cout << my_pow(2, 1.3);
	return 0;
}
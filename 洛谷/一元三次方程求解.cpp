#include <bits/stdc++.h>

using namespace std;

//完美的二分，一次AC，爽！

double a, b, c, d;
double dou[3] = { 0 };
int cnt = 0;

double f(double x) {
	return a * x * x * x + b * x * x + c * x + d;
}

void Result(double left, double right) {
	if (f(right) * f(left) == 0) {
		if (f(left) == 0) {
			dou[cnt] = left;
			cnt++;
		}
		return;
	}
	else if (f(right) * f(left) < 0) {
		if (right - left < .0001) {
			dou[cnt] = left;
			cnt++;
			return;
		}
		else {
			double mid = (right + left) / 2;
			if (f(mid) * f(left) <= 0) Result(left, mid);
			else Result(mid, right);
		}
	}
}

int main()
{
	int i, j;
	double v, u;
	cin >> a >> b >> c >> d;
	for (v = -100.00; v <= 100; v += 1) {
		if (f(v) * f(v + 1) <= 0) Result(v, v + 1);
	}
	for (i = 0; i < 3; i++) {
		printf("%.2lf ", dou[i]);
	}
	return 0;
}
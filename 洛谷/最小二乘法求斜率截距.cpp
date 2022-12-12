#include <bits/stdc++.h>

using namespace std;

int main() {
	double average_y, average_x, sum = 0.0, xi, yi, k, b, A = 0.0, B = 0.0;
	double y[100] = { 0.0 };
	double x[100] = { 0.0 };
	int n;
	cout << "请输入表中数据组数" << endl;
	cin >> n;
	cout << "请输入yi:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> y[i];
		sum += y[i];
	}
	average_y = sum / n;
	cout << "yi均值为：" << average_y << endl;
	cout << "请输入xi:" << endl;
	sum = 0.0;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		sum += x[i];
	}
	average_x = sum / n;
	cout << "xi均值为：" << average_x << endl;
	for (int i = 0; i < n; i++) {
		A += y[i] * x[i] - average_x * average_y;
	}
	for (int i = 0; i < n; i++) {
		B += (x[i] - average_x) * (x[i] - average_x);
	}
	k = A / B;
	b = average_y - k * average_x;
	printf("斜率为:%.10lf\n", k);
	printf("截距为:%.6lf\n", b);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	double average_y, average_x, sum = 0.0, xi, yi, k, b, A = 0.0, B = 0.0;
	double y[100] = { 0.0 };
	double x[100] = { 0.0 };
	int n;
	cout << "�����������������" << endl;
	cin >> n;
	cout << "������yi:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> y[i];
		sum += y[i];
	}
	average_y = sum / n;
	cout << "yi��ֵΪ��" << average_y << endl;
	cout << "������xi:" << endl;
	sum = 0.0;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		sum += x[i];
	}
	average_x = sum / n;
	cout << "xi��ֵΪ��" << average_x << endl;
	for (int i = 0; i < n; i++) {
		A += y[i] * x[i] - average_x * average_y;
	}
	for (int i = 0; i < n; i++) {
		B += (x[i] - average_x) * (x[i] - average_x);
	}
	k = A / B;
	b = average_y - k * average_x;
	printf("б��Ϊ:%.10lf\n", k);
	printf("�ؾ�Ϊ:%.6lf\n", b);
	return 0;
}
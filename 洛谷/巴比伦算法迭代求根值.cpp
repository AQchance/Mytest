#include<bits/stdc++.h>

using namespace std;

double Babylonian_algorithm(double x) {
	if (x == 0) return 0;
	else {
		double a = 1;
		for (int i = 0; i < 100; i++) {
			a = 0.5 * (a + x / a);
		}
		return a;//û�м��㾫�ȣ�ֻ�ǵ�����100�Σ����Ǿ����Ѿ��㹻����
	}
}

int main()
{
	double x;
	cin >> x;
	cout<<Babylonian_algorithm(x);
	return 0;
}
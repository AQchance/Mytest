#include <iostream>

using namespace std;

template <class T>
void sort_num(T a[], int n) {
	for (int j = n - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
		}
	}
}

int main() {
	int m, n;
	int a[100] = { 0 };
	float b[100] = { 0 };
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort_num(a, m);
	sort_num(b, n);
	for (int i = 0; i < m; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}
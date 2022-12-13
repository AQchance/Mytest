#include <bits/stdc++.h>

using namespace std;

void CheckSTP(int a[], int n, int x) {
	int k;
	for (k = x; k * 2 <= n;) {
		if (k * 2 + 1 > n) {
			if (a[k] <= a[k * 2]) return;
			else {
				swap(a[k], a[k * 2]);
				return;
			}
		}
		else {
			if (a[k * 2] <= a[k * 2 + 1] && a[k * 2] < a[k]) {
				swap(a[k * 2], a[k]);
				k = k * 2;
			}
			else if (a[k * 2 + 1] < a[k * 2] && a[k * 2 + 1] < a[k]) {
				swap(a[k * 2 + 1], a[k]);
				k = k * 2 + 1;
			}
			else return;
		}
	}
}

void CreateSTP(int a[], int n) {
	int i, j = n / 2, k, l;
	for (i = j; i > 0; i--) {
		if (i * 2 + 1 > n) {
			if (a[i * 2] < a[i]) swap(a[i], a[i * 2]);
		}
		else {
			if (a[i * 2] <= a[i * 2 + 1] && a[i * 2] < a[i]) {
				swap(a[i * 2], a[i]);
				CheckSTP(a, n, i * 2);
			}
			else if (a[i * 2 + 1] < a[i * 2] && a[i * 2 + 1] < a[i]) {
				swap(a[i * 2 + 1], a[i]);
				CheckSTP(a, n, i * 2 + 1);
			}
		}
	}
}

int main()
{
	int i, n, a[100] = { 0 };
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}
	CreateSTP(a, n);
	for (i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
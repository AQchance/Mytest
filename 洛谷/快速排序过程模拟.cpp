#include <bits/stdc++.h>

using namespace std;

void Qsort(int a[], int low, int high) {
	int i = low, j = high, k = a[low];
	while (i != j) {
		while (a[j] >= k) {
			j--;
			if (j == i) {
				a[j] = k;
				return;
			}
		}
		a[i] = a[j];
		while (a[i] <= k) {
			i++;
			if (i == j) {
				a[i] = k;
				return;
			}
		}
		a[j] = a[i];
	}
	a[j] = k;
}

int main()
{
	int i, n;
	int a[100] = { 0 };
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	Qsort(a, 0, n - 1);
	for (i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}